#pragma once 

#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

//SFML presentation of player

class cannotLoadImage{};

class playerSFML: public Player{
public:
    playerSFML(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin,const double& radius,const sf::Vector2f& scale = sf::Vector2f(0.3,0.3));
    void drawPlayer(sf::RenderWindow &window); 
    void setScale(const sf::Vector2f& newScale);
    void setPosition(const Position& newPosition);
    void rotate(const double& angle);
    sf::Vector2f getScale() const;
    void scale(const sf::Vector2f& scale);
    double getGlobalBoundHeight();
    std::shared_ptr<sf::Sprite> getSprite();
private:
    sf::Texture _texture;
    sf::Vector2f _scale;
    sf::Sprite _sprite;
    double _globalBoundHeight; 
};