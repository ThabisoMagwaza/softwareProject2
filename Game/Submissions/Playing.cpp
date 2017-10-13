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
        auto temp = std::shared_ptr<Enemy> (new Enemy(_settings.origin)); //all enemies star
        _enemies.push_back(temp);
    }
    
    _positions = std::shared_ptr<objectPositions> (new objectPositions);
}

void Playing::addPlayerBullet() {
    _player->addBullet();
}

void Playing::advancePlayerBullets(){
    for(unsigned int i = 0; i < _player->_bullets.size();i++){
        _player->_bullets.at(i)->shoot(_settings.origin);
    }
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

bool Playing::player_Enemy_Collison(const int& enemy) const{
    auto rect1 = _player->getBoundRect();
    auto rect2 = _enemies[enemy]->getBoundRect();
    
    return rect1->intersects(rect2);
}

void Playing::setEnemyMovingAngles(std::vector<int> angles){
    _enemyMovingAngles = angles;
    for(unsigned int i = 0;i<_enemies.size();i++){
        _enemies[i]->setAngle(_enemyMovingAngles[i]);
    }
}

void Playing::advanceEnemies() {
    for(unsigned int i = 0;i<_enemies.size();i++){
        _enemies[i]->move('l',_settings.origin,_settings.enemySpeed,_enemyMovingAngles[i]);
    }
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
    for(unsigned int i = 0; i< pBullets.size();i++){
        auto temp = _enemies.at(i)->getBullet();
        if(temp != NULL)
            _positions->playerBulletsPos.push_back(temp->getLocation());
    }
    
}

bool Playing::enemyBullet_player_collision(const int& enemy) const{
    auto rect1 = _player->getBoundRect();
    auto rect2 = _enemies[enemy]->getBullet()->getBoundRect();
    
    return rect1->intersects(rect2);
}

void Playing::advanceEnemyBullets(){
    for(unsigned int i = 0;i<_enemies.size();i++){
        if(_enemies[i]->getBullet() == NULL){
            _enemies[i]->addBullet();
        }
        _enemies[i]->shoot(_settings.origin,_settings.enemyBulletSpeed);
    }
}

std::shared_ptr<objectPositions> Playing::getPositions(){
    updatePositions();
    return _positions;
}

void Playing::movePlayer(char dir){
    _player->move(dir,_settings.origin,_settings.playerSpeed);
}
