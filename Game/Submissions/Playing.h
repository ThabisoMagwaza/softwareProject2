#pragma once

#include <SFML/Graphics.hpp>
#include "playerSFML.h"
#include "enemySFML.h"
#include <iostream>

class Playing{
public:
   Playing();
   void initializeWindow(sf::RenderWindow& window);
   void initializePlayer(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin,const double& radius);
   void initializeEemey(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin,const int& numEnemies = 3);
   bool play();
   void display() const;
   
private:
    std::shared_ptr<playerSFML> _player;
    std::vector< std::shared_ptr<enemySFML> > _enemies; 
    std::shared_ptr<sf::RenderWindow> _window;
};