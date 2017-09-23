#include "Player.h"
#include<cmath>
#include<iostream>

Player::Player(){
    _imageDir = "";
}

void Player::initialize(std::string imageDir, Position& startPosition, Position& origin,const double& radius)
{
    _imageDir = imageDir;
    playerMovement::initialize(startPosition,origin,radius);
//    if(!pTexture.loadFromFile(imDirectory)){
//        std::cerr <<"Cannot load image";
//    }
//    _scale = scale;
//    _sprite = Movement::getSprite();
//    _sprite->setTexture(pTexture);
//    _sprite->setScale(_scale);
//    _globalBoundHeight = _sprite->getGlobalBounds().height;
    //Movement::initialize(startPosition,origin,radius-_globalBoundHeight,_globalBoundHeight);
}

std::string Player::getImageDir() const {
    return _imageDir;
}

void Player::setImageDir(const std::string& imageDir){
    _imageDir = imageDir;
}


//void Player::drawPlayer(sf::RenderWindow &window){
//    window.draw(*_sprite);
//}
//
//
//void Player::scale(const sf::Vector2f& scale){
//    //_scale = newScale;
//    _sprite->scale(scale);
//    _scale = _sprite->getScale();
//}
//
//sf::Vector2f Player::getScale() const {
//    return _scale;
//}
//
//
//double Player::getGlobalBoundHeight(){
//    return _globalBoundHeight;
//}
//
//void Player::setScale(const sf::Vector2f& newScale){
//    _scale = newScale;
//    _sprite->setScale(newScale);
//}
//
