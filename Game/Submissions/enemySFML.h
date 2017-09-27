#pragma once 

#include "Enemy.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "cannotLoadImage.h"

class enemySFML: public Enemy{
public:
    enemySFML(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin,const sf::Vector2f& scale = sf::Vector2f(0.3,0.3));
    void drawPlayer(sf::RenderWindow &window) ; 
    void setScale(const sf::Vector2f& newScale) ;
    void setPosition(const Position& newPosition) ;
    void setRotation(const double& angle) ;
    void rotate(const double& angle) ;
    sf::Vector2f getScale() const ;
    void scale(const sf::Vector2f& scale) ;
    double getGlobalBoundHeight() ;
    std::shared_ptr<sf::Sprite> getSprite() ;
private:
    std::shared_ptr<sf::Texture> _texture;
    sf::Vector2f _scale;
    std::shared_ptr<sf::Sprite> _sprite;
    double _globalBoundHeight; 
};