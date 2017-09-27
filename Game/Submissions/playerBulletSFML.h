#pragma once 

//#include "displaySFML.h"
#include "Position.h"
#include "playerBullet.h"
#include "cannotLoadImage.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

//SFML presentation of player

class playerBulletSFML: public playerBullet{
public:
    playerBulletSFML(std::string imageDir, Position& startPosition, Position& origin,const double& startDisplacement, const double& angle,const sf::Vector2f& scale = sf::Vector2f(0.1,0.1));
    void drawPlayer(sf::RenderWindow &window) ; 
    void setScale(const sf::Vector2f& newScale) ;
    void setPosition(const Position& newPosition) ;
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