#include "Playing.h"
#include <iostream>
#include <ctime>

Playing::Playing(){
    //auto temp = std::shared_ptr<sf::RenderWindow> (&window);
    _player = 0;
    _window = 0;
}

void Playing::initializeWindow(sf::RenderWindow& window){
    auto temp = std::shared_ptr<sf::RenderWindow> (&window);
    _window = temp;
}

void Playing::initializePlayer(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin,const double& radius){
    _player = std::shared_ptr<playerSFML> (new playerSFML(imageDir,startPosition,origin,radius));
}

void Playing::initializeEemey(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin, const int& numEnemies){
    for(auto i = 0;i<numEnemies;i++){
        auto newEnemy = std::shared_ptr<enemySFML> (new enemySFML(imageDir,startPosition,origin));
        _enemies.push_back(newEnemy);
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
            
            for(auto i = 0; i < _enemies.size();i++){
                auto angle = rand() % 361;
                _enemies.at(i)->setPosition(_enemies[i]->moveStraightFromCentre(angle));
            }
            return true;
}

void Playing::display() const{
        //_window->clear();
        //dispBackground();
        _player->drawPlayer(*_window);
        for(auto i = 0; i < _enemies.size();i++){
            _enemies.at(i)->drawPlayer(*_window);
        }
    
}