#include "enemySFML.h"


enemySFML::enemySFML(std::string imageDir, const sf::Vector2f& startPosition,const sf::Vector2f& origin,const sf::Vector2f& scale){
        _texture = std::shared_ptr<sf::Texture> (new sf::Texture);
        _sprite = std::shared_ptr<sf::Sprite> (new sf::Sprite);
        
        
        if(!_texture->loadFromFile(imageDir)){
        cannotLoadImage err;
        throw err;
        std::cerr<<"Cannot load image";
    }
    
    _sprite->setTexture(*_texture);
    _scale = scale;
    _sprite->setScale(_scale);
    
    auto temp = sf::Vector2f(startPosition.x,startPosition.y);
    _sprite->setPosition(temp);
    
    Position startP(temp.x,temp.y);
    //startP.setPosition(temp.x,temp.y);
    Position Origin(origin.x,origin.y);
    //Origin.setPosition(origin.x,origin.y);
    
    Enemy::initialize(imageDir,startP,Origin);
}

void enemySFML::drawPlayer(sf::RenderWindow &window){
    window.draw(*_sprite);
}


void enemySFML::scale(const sf::Vector2f& scale){
    _scale = scale;
    _sprite->scale(_scale);
}

sf::Vector2f enemySFML::getScale() const {
    return _scale;
}


double enemySFML::getGlobalBoundHeight(){
    return _globalBoundHeight;
}

void enemySFML::setScale(const sf::Vector2f& newScale){
    _scale = newScale;
    _sprite->setScale(newScale);
}

std::shared_ptr<sf::Sprite> enemySFML::getSprite(){
    //std::shared_ptr<sf::Sprite> temp(&_sprite);
    return _sprite;
}

void enemySFML::setPosition(const Position& newPos){
    _sprite->setPosition(sf::Vector2f(newPos.x,newPos.y));
}

void enemySFML::rotate(const double& angle){
    _sprite->rotate(angle);
}

void enemySFML::setRotation(const double& angle){
    _sprite->setRotation(angle);
}