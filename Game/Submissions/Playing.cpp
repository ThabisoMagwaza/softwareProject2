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


//bool Playing::play(){
            //srand(time(0));
            //sf::Event EventNow;
                 
                 //event loop
            //while(_window->pollEvent(EventNow)){
                //dispBackground();
//            if(EventNow.type == sf::Event::Closed){
//                     //Mode = Game::GameMode::Quiting;
//                     _window->close();
//                     return false;
//                }
//
//            }
            
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
//                _player->setPosition(_player->rotateRight(0.5));
//                _player->rotate(-0.5);
//            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
//                _player->setPosition(_player->rotateLeft(0.5));
//                _player->rotate(0.5);
//            }
//        
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
//                addBullet();
//            }
            
//            //advance enemies
//            for(unsigned int i = 0; i < _enemies.size();i++){
//                //if out of playing area
//                if(_enemies[i]->getDisplacement() > _playingRadius + 60)
//                    _enemies[i]->setDisplacement(0);
//                
//                //if enemy is not moving, i.e is recently initialized
//                if(!_enemies[i]->isMoving()){
//
//                    _enemyMovingAngles.at(i) = rand() % 361;
//
//                }
//                    
//                _enemies.at(i)->setPosition(_enemies[i]->moveStraightFromCentre(_enemyMovingAngles[i]));
//                //_enemies.at(i)->setRotation(-_enemyMovingAngles[i]);
//                //_enemies.at(i)->setPosition(_enemies[i]->spiralFromCenter(2));
//                
//                //if enemy colide with player
//                if(collision(_enemies[i]->getSprite(),_player->getSprite())){
//                    return false;
//                }
//                
//                //std::cout<<_enemies[i]->getDisplacement()<<std::endl;
//                //if enemy far enough from center, shoot enemy bullet
//                if(_enemies[i]->getDisplacement() == 100){
//                    addEnemyBulllet();
//                }
//                
//                
//                //std::cout<<_enemyBulluets.size()<<std::endl;
//            }
//            
//            
//            
//            if(_enemies.empty()){
//            //advance enemies
//                for(unsigned int i = 0; i < _spriralEnemy.size();i++){
//
//                    //if out of playing area
//                    if(_spriralEnemy[i]->getDisplacement() > _playingRadius + 60)
//                        _spriralEnemy[i]->setDisplacement(0);
//                
//                    _spriralEnemy.at(i)->setPosition(_spriralEnemy[i]->spiralFromCenter(0.5));
//                
//                //if enemy colide with player
//                    if(collision(_spriralEnemy[i]->getSprite(),_player->getSprite())){
//                        return false;
//                    }
//
//                }
//                //std::cout<<_spriralEnemy[0]->getLives()<<std::endl;
//            }
//            
//            advanceBullets();
//            
//            for(unsigned int i = 0; i<_enemyBulluets.size();i++){
//                if(collision(_enemyBulluets[i]->getSprite(),_player->getSprite())){
//                    return false;
//                }
//            }
//            
//            //
//            
//            
//            return _spriralEnemy[0]->isAlive();
//}

//void Playing::display() const{
//        //_window->clear();
//        //dispBackground();
//        _player->drawPlayer(*_window);
//        
//        for(unsigned int i = 0; i< _bullets.size();i++){
//            _bullets[i]->drawPlayer(*_window);
//        }
//        
//        for(unsigned int i = 0; i < _enemies.size();i++){
//            _enemies.at(i)->drawPlayer(*_window);
//        }
//        
//        for(unsigned int i = 0; i<_enemyBulluets.size();i++){
//            _enemyBulluets[i]->drawPlayer(*_window);
//        }
//        
//        if(_enemies.empty()){
//            for(unsigned int i = 0; i<_spriralEnemy.size();i++){
//                _spriralEnemy[i]->drawPlayer(*_window);
//            }
//        }
//    
//}


//bool Playing::collision(std::shared_ptr<sf::Sprite> sprite1, std::shared_ptr<sf::Sprite> sprite2) {
//    auto position = sf::Vector2f(sprite2->getGlobalBounds().left,sprite2->getGlobalBounds().top );
//    auto size = sf::Vector2f(sprite2->getGlobalBounds().width* 0.6 ,sprite2->getGlobalBounds().height * 0.6);
//    auto temp = sf::FloatRect(position,size);
//    
//    auto position1 = sf::Vector2f(sprite1->getGlobalBounds().left,sprite1->getGlobalBounds().top);
//    auto size1 = sf::Vector2f(sprite1->getGlobalBounds().width * 0.6 ,sprite1->getGlobalBounds().height * 0.6);
//    auto temp1 = sf::FloatRect(position1,size1);
//    //return sprite1->getGlobalBounds().intersects(temp);
//    return temp.intersects(temp1);
//}

//void Playing::advancePlayerBullets() {
//        //advance player bullet
//        for(unsigned int i= 0; i<_bullets.size();i++){
//            auto newPos = _bullets[i]->shootToCenter();
//                _bullets[i]->setPosition(newPos);
//                
//                
//                for(unsigned int j = 0 ; j<_enemies.size(); j++){
//                    if(collision(_bullets[i]->getSprite(),_enemies[j]->getSprite())){
//                        //if bullet collides with enemy remove enemy
//                        _bullets.erase(std::remove(_bullets.begin(), _bullets.end(), _bullets[i]), _bullets.end());
//                        _enemies.erase(std::remove(_enemies.begin(), _enemies.end(), _enemies[j]), _enemies.end());
//                        break;
//                    }
//                }
//                
//                //if bullet reaches center erase it
//                if(_bullets[i]->getDisplacement() < 3){
//                    //int int_to_remove = n;
//                    _bullets.erase(std::remove(_bullets.begin(), _bullets.end(), _bullets[i]), _bullets.end());
//                    break;
//                }
//                
//                if(_enemies.empty()){
//
//                    if(collision(_bullets[i]->getSprite(),_spriralEnemy[0]->getSprite())){
//                        _spriralEnemy[0]->damage(1);
//                        _bullets.erase(std::remove(_bullets.begin(), _bullets.end(), _bullets[i]), _bullets.end());
//                        break;
//                    }
//                }
//                
//        }
//        
//        //move enemy bullets
//        for(unsigned int i = 0; i<_enemyBulluets.size();i++){
//            auto newPos = _enemyBulluets[i]->shootFromEnemy();
//            _enemyBulluets[i]->setPosition(newPos);
//            _enemyBulluets[i]->setLocation(newPos);
//        }
//}
void Playing::addPlayerBullet() {
        //if(_player->_bullets.size() <= 1){
            _player->addBullet();
        //}
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

