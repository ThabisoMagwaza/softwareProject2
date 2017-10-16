#include "Playing.h"
#include <iostream>
#include <ctime>

Playing::Playing(const gameSettings& settings){
    srand(time(0));
    _settings = settings;
    _player = std::unique_ptr<Player> (new Player(_settings.playerStartingPosition,_settings.playerStartingAngle,_settings.playingRadius));
    
    for(int i = 0; i < _settings.numberOfEnemies; i++){
        _enemyMovingAngles.push_back(rand()%361);
    }

    for(int i = 0; i < _settings.numberOfEnemies; i++){
        auto temp = std::shared_ptr<Enemy> (new Enemy(_settings.origin)); //all enemies start at origin
        _enemies.push_back(temp);
    }
    setBoundsRects();
    //setEnemyMovingAngles(_enemyMovingAngles);
    _positions = std::shared_ptr<objectPositions> (new objectPositions);
    
}

void Playing::addPlayerBullet() {
	
	if(_player->_bullets.size() < _settings.maxPlayerBullets ){ //limit number of player bullets
		_player->addBullet();
	}
}

bool Playing::advancePlayerBullets(){
    for(unsigned int i = 0; i < _player->_bullets.size();i++){
        _player->_bullets.at(i)->shoot(_settings.origin,_settings.playerBulletSpeed);

		if(_player->_bullets.at(i)->getDisplacement() < 5){ //remove bullet when it reaches the center
			_player->removeBullet(i);
		}else if(playerBullet_Enemy_Collision(i)){
			_player->removeBullet(i);
			removeEnemy(i);
		}
    }
	return _enemies.size() != 0;
}

bool Playing::playerBullet_Enemy_Collision(const int& bullet) const{
    auto rect1 = _player->_bullets[bullet]->getBoundRect();
    for(unsigned int i = 0; i< _enemies.size();i++){
        auto rect2 = _enemies[i]->getBoundRect();
        if(rect1->intersects(rect2))
            return true;
    }
    return false;
}

bool Playing::player_Enemy_Collison() const{
	auto rect1 = _player->getBoundRect();
	for(unsigned int i = 0;i<_enemies.size();i++){
		auto rect2 = _enemies[i]->getBoundRect();
		if(rect1->intersects(rect2))
			return true;
	}
    return false;
}

void Playing::setEnemyMovingAngles(std::vector<int> angles){
    _enemyMovingAngles = angles;
    for(unsigned int i = 0;i<_enemies.size();i++){
        _enemies[i]->setAngle(_enemyMovingAngles[i]);
    }
}

bool Playing::advanceEnemies() {
	bool bulletMovingResult = true;
    for(unsigned int i = 0;i<_enemies.size();i++){
		if(_enemies[i]->getDisplacement() == _settings.playingRadius + 60){  //set position to origin
			auto temp = std::make_shared<Position>(_settings.origin.x,_settings.origin.y);
			_enemyMovingAngles[i] =  rand()%361; //randomize new moving angles
			_enemies[i]->setLocation(temp);
			_enemies[i]->setDisplacement(0);
		}else{
			_enemies[i]->move('l',_settings.origin,_settings.enemySpeed,_enemyMovingAngles[i]);
			if(player_Enemy_Collison()) //end game if player collides with enemy
				return false;
		}
		
		//enemy bullets are only shot at approximately enemyBulletShootingDistance
		if(_enemies[i]->getDisplacement() >= _settings.enemyBulletShootingDistance && _enemies[i]->getDisplacement() <= _settings.enemyBulletShootingDistance + 2){
			makeEnemybullets();
			bulletMovingResult = advanceEnemyBullets(); //returns false if bullet collides with player
			if(!bulletMovingResult)
				return bulletMovingResult;
		}else if(_enemies[i]->getDisplacement() > _settings.enemyBulletShootingDistance + 2){
			bulletMovingResult = advanceEnemyBullets();
			if(!bulletMovingResult)
				return bulletMovingResult;
		}
    }
	return bulletMovingResult;
}

void Playing::updatePositions(){
    _positions->playerPos = _player->getLocation();
    
    //update enemy positions
    _positions->enemyPos.clear();
    for(unsigned int i = 0; i<_enemies.size();i++){
        auto temp = _enemies.at(i)->getLocation();
		
        _positions->enemyPos.push_back(temp);
    }
    
    //updated player bullets
    auto pBullets = _player->getBullets();
    _positions->playerBulletsPos.clear();
    for(unsigned int i = 0; i< pBullets.size();i++){
        auto temp = pBullets.at(i)->getLocation();
        _positions->playerBulletsPos.push_back(temp);
    }
    
    //update enemy bullets
    _positions->enemyBulletsPos.clear();
    for(unsigned int i = 0; i< _enemies.size();i++){
        auto temp = _enemies.at(i)->getBullet();
        if(temp != NULL)
            _positions->enemyBulletsPos.push_back(temp->getLocation());
    }
    
}

bool Playing::enemyBullet_player_collision(const int& enemy) const{
    auto rect1 = _player->getBoundRect();
    auto rect2 = _enemies[enemy]->getBullet()->getBoundRect();
    
    return rect1->intersects(rect2);
}

bool Playing::advanceEnemyBullets(){
	
    for(unsigned int i = 0;i<_enemies.size();i++){
        if(_enemies[i]->getBullet() != NULL){

			_enemies[i]->shoot(_settings.origin,_settings.enemyBulletSpeed);
		
			if(_enemies[i]->getBullet()->getDisplacement() > (_settings.playingRadius + 60)){ //remove bullets out of playing area
				_enemies[i]->removeBullet();
			}else if(enemyBullet_player_collision(i)){
				_enemies[i]->removeBullet();
				return false;
			}
		}
    }
	return true;
}

std::shared_ptr<objectPositions> Playing::getPositions(){
    updatePositions();
    return _positions;
}

void Playing::movePlayer(char dir){
    _player->move(dir,_settings.origin,_settings.playerSpeed);
}

void Playing::setBoundsRects(){
    _player->getBoundRect()->changeVertices(_settings.playerBoundRectSize.x,_settings.playerBoundRectSize.y);
    for(unsigned int i = 0;i<_enemies.size();i++){
        _enemies.at(i)->getBoundRect()->changeVertices(_settings.enemyBoundRectSize.x,_settings.enemyBoundRectSize.y);
    }
}

void Playing::removeEnemy(const int& enemy){
	_enemies.erase(_enemies.begin() + enemy);
}

void Playing::makeEnemybullets(){
	for(unsigned int i = 0;i<_enemies.size();i++){
        if(_enemies[i]->getBullet() == NULL){
            _enemies[i]->addBullet();
        }
	}
}