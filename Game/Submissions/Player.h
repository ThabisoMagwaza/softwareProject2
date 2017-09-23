#pragma once
//#include "Movement.h"
#include "playerMovement.h"
//player for the game

//#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>


class Player : public playerMovement{

public:
    Player();
    void initialize(std::string imageDir,Position& startPosition, Position& origin,const double& radius);
    std::string getImageDir() const;
    void setImageDir(const std::string& imageDir);
    //void drawPlayer(sf::RenderWindow &window); 
    //void setScale(const sf::Vector2f& newScale);
    //sf::Vector2f getScale() const;
    //void scale(const sf::Vector2f& scale);
    //double getGlobalBoundHeight();
private:
    //sf::Texture pTexture;
    //sf::Vector2f _scale;
    //std::shared_ptr<sf::Sprite> _sprite;
    std::string _imageDir;
    
    //double _globalBoundHeight; 
};
