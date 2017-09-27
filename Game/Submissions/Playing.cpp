#include "Playing.h"
#include <iostream>
#include <ctime>

Playing::Playing(){
    //auto temp = std::shared_ptr<sf::RenderWindow> (&window);
    _window = 0;
    _player = 0;
    _playingRadius = 0;
}

void Playing::initializeWindow(sf::RenderWindow& window, const double& playingRadius){
    auto temp = std::shared_ptr<sf::RenderWindow> (&window);
    _window = temp;
    _playingRadius = playingRadius;
    
}

void Playing::initializePlayer(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin,const double& radius){
    _player = std::shared_ptr<playerSFML> (new playerSFML(imageDir,startPosition,origin,radius));
}

void Playing::initializeEemey(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin, const int& numEnemies){
    
    //make enemies
    for(auto i = 0;i<numEnemies;i++){
        auto newEnemy = std::shared_ptr<enemySFML> (new enemySFML(imageDir,startPosition,origin));
        _enemies.push_back(newEnemy);
    }

    for(unsigned int i = 0; i < _enemies.size();i++){
        //auto angle = rand() % 361;
        _enemyMovingAngles.push_back(rand() % 361);  //make them move at random angles
    }
}

void Playing::initializeSpiralEnemy(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin, const int& numEnemies){
    for(auto i = 0;i<numEnemies;i++){
        auto newEnemy = std::shared_ptr<enemySFML> (new enemySFML(imageDir,startPosition,origin));
        _spriralEnemy.push_back(newEnemy);
    }
}

bool Playing::play(){
            srand(time(0));
            sf::Event EventNow;
                 
                 //event loop
            while(_window->pollEvent(EventNow)){
                //dispBackground();
            if(EventNow.type == sf::Event::Closed){
                     //Mode = Game::GameMode::Quiting;
                     _window->close();
                     return false;
                }

            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                _player->setPosition(_player->rotateRight(0.5));
                _player->rotate(-0.5);
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                _player->setPosition(_player->rotateLeft(0.5));
                _player->rotate(0.5);
            }
        
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
                addBullet();
            }
            
            //advance enemies
            for(unsigned int i = 0; i < _enemies.size();i++){
                //if out of playing area
                if(_enemies[i]->getDisplacement() > _playingRadius + 60)
                    _enemies[i]->setDisplacement(0);
                
                //if enemy is not moving, i.e is recently initialized
                if(!_enemies[i]->isMoving()){

                    _enemyMovingAngles.at(i) = rand() % 361;

                }
                    
                _enemies.at(i)->setPosition(_enemies[i]->moveStraightFromCentre(_enemyMovingAngles[i]));
                //_enemies.at(i)->setRotation(-_enemyMovingAngles[i]);
                //_enemies.at(i)->setPosition(_enemies[i]->spiralFromCenter(2));
                
                //if enemy colide with player
                if(collision(_enemies[i]->getSprite(),_player->getSprite())){
                    return false;
                }
                
                //std::cout<<_enemies[i]->getDisplacement()<<std::endl;
                //if enemy far enough from center, shoot enemy bullet
                if(_enemies[i]->getDisplacement() == 100){
                    addEnemyBulllet();
                }
                
                
                //std::cout<<_enemyBulluets.size()<<std::endl;
            }
            
            
            
            if(_enemies.empty()){
            //advance enemies
            for(unsigned int i = 0; i < _spriralEnemy.size();i++){
                //if out of playing area
                if(_spriralEnemy[i]->getDisplacement() > _playingRadius + 60)
                    _spriralEnemy[i]->setDisplacement(0);
                
                _spriralEnemy.at(i)->setPosition(_spriralEnemy[i]->spiralFromCenter(2));
                
                //if enemy colide with player
                if(collision(_spriralEnemy[i]->getSprite(),_player->getSprite())){
                    return false;
                }
                
                //std::cout<<_enemies[i]->getDisplacement()<<std::endl;
                //if enemy far enough from center, shoot enemy bullet
                if(_spriralEnemy[i]->getDisplacement() == 100){
                    addEnemyBulllet();
                }
                
                
                //std::cout<<_enemyBulluets.size()<<std::endl;
            }
            }
            
            advanceBullets();
            
            for(unsigned int i = 0; i<_enemyBulluets.size();i++){
                if(collision(_enemyBulluets[i]->getSprite(),_player->getSprite())){
                    return false;
                }
            }
            
            //
            
            
            return _spriralEnemy.size() != 0;
}

void Playing::display() const{
        //_window->clear();
        //dispBackground();
        _player->drawPlayer(*_window);
        for(unsigned int i = 0; i < _enemies.size();i++){
            _enemies.at(i)->drawPlayer(*_window);
        }
        
        for(unsigned int i = 0; i< _bullets.size();i++){
            _bullets[i]->drawPlayer(*_window);
        }
        
        for(unsigned int i = 0; i<_enemyBulluets.size();i++){
            _enemyBulluets[i]->drawPlayer(*_window);
        }
        
        if(_enemies.empty()){
            for(unsigned int i = 0; i<_spriralEnemy.size();i++){
                _spriralEnemy[i]->drawPlayer(*_window);
            }
        }
    
}


bool Playing::collision(std::shared_ptr<sf::Sprite> sprite1, std::shared_ptr<sf::Sprite> sprite2) {
    auto position = sf::Vector2f(sprite2->getGlobalBounds().left,sprite2->getGlobalBounds().top );
    auto size = sf::Vector2f(sprite2->getGlobalBounds().width* 0.6 ,sprite2->getGlobalBounds().height * 0.6);
    auto temp = sf::FloatRect(position,size);
    
    auto position1 = sf::Vector2f(sprite1->getGlobalBounds().left,sprite1->getGlobalBounds().top);
    auto size1 = sf::Vector2f(sprite1->getGlobalBounds().width * 0.6 ,sprite1->getGlobalBounds().height * 0.6);
    auto temp1 = sf::FloatRect(position1,size1);
    //return sprite1->getGlobalBounds().intersects(temp);
    return temp.intersects(temp1);
}

void Playing::resetGame(std::string p_imageDir,const sf::Vector2f& p_startPosition, const sf::Vector2f& p_origin,const double& p_radius,std::string e_imageDir,const sf::Vector2f& e_startPosition, const sf::Vector2f& e_origin,const std::string& se_imageDir,const int& numEnemies){
    _player = 0;
    //_playingRadius = 0;
    _enemies.clear();
    _enemyMovingAngles.clear();
    _bullets.clear();
    _enemyBulluets.clear();
    _spriralEnemy.clear();
    
    initializePlayer(p_imageDir,p_startPosition,p_origin,p_radius);
    initializeEemey(e_imageDir,e_startPosition,e_origin);
    initializeSpiralEnemy(se_imageDir,e_startPosition,e_origin);
}

void Playing::advanceBullets() {
        //advance player bullet
        for(unsigned int i= 0; i<_bullets.size();i++){
            auto newPos = _bullets[i]->shootToCenter();
                _bullets[i]->setPosition(newPos);
                
                
                for(unsigned int j = 0 ; j<_enemies.size(); j++){
                    if(collision(_bullets[i]->getSprite(),_enemies[j]->getSprite())){
                        //if bullet collides with enemy remove enemy
                        _bullets.erase(std::remove(_bullets.begin(), _bullets.end(), _bullets[i]), _bullets.end());
                        _enemies.erase(std::remove(_enemies.begin(), _enemies.end(), _enemies[j]), _enemies.end());
                        break;
                    }
                }
                
                //if bullet reaches center erase it
                if(_bullets[i]->getDisplacement() < 3){
                    //int int_to_remove = n;
                    _bullets.erase(std::remove(_bullets.begin(), _bullets.end(), _bullets[i]), _bullets.end());
                }
                
        }
        
        //move enemy bullets
        for(unsigned int i = 0; i<_enemyBulluets.size();i++){
            auto newPos = _enemyBulluets[i]->shootFromEnemy();
            _enemyBulluets[i]->setPosition(newPos);
            _enemyBulluets[i]->setLocation(newPos);
        }
}
void Playing::addBullet() {
        if(_bullets.size() <= 1){
            auto pos = _player->getLocation();
            auto orig = _player->getOrigin();
            auto newBullet = std::shared_ptr<playerBulletSFML> (new playerBulletSFML("resources/playerBullet.png",pos,orig,_player->getRadius(),_player->getCurrentAngle()));
            _bullets.push_back(newBullet);
        }
}

bool Playing::playerBullet_EnemyCollision(std::shared_ptr<playerBulletSFML> bullet){
    for(unsigned int j = 0 ; j<_enemies.size(); j++){
        if(collision(bullet->getSprite(),_enemies[j]->getSprite())){
            //if bullet collides with enemy remove enemy
            _enemies.erase(std::remove(_enemies.begin(), _enemies.end(), _enemies[j]), _enemies.end());
            return true;
        }
    }
    return false;
}

void Playing::addEnemyBulllet(){
    
    for(unsigned int i = 0 ; i<_enemies.size();i++){
            auto pos = _enemies[i]->getLocation();
            auto orig = _enemies[i]->getOrigin();
            auto newBullet = std::shared_ptr<playerBulletSFML> (new playerBulletSFML("resources/enemyBullet.png",pos,orig,_enemies[i]->getDisplacement(),_enemies[i]->getCurrentAngle()));
            newBullet->setScale(sf::Vector2f(0.5,0.5));
            newBullet->setSpeed(1);
            _enemyBulluets.push_back(newBullet);
    }
    
}