#include "playerBulletSFML.h"


playerBulletSFML::playerBulletSFML(std::string imageDir, Position& startPosition, Position& origin,const double& startDisplacement, const double& angle,const sf::Vector2f& scale)
//:Player(imageDir,Position::Position(startPosition.x,startPosition.y),Position::Position(startPosition.x,startPosition.y),radius)
{
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

    _globalBoundHeight = _sprite->getGlobalBounds().height;
    //_sprite->setOrigin(_sprite->getOrigin().x,_sprite->getOrigin().y + _globalBoundHeight);
    auto temp = sf::Vector2f(startPosition.x,startPosition.y);
    _sprite->setPosition(temp);
    
//    Position startP;
//    startP.setPosition(temp.x,temp.y);
//    Position Origin;
//    Origin.setPosition(origin.x,origin.y);
    
    playerBullet::initialize(imageDir,startPosition,origin,startDisplacement,angle);
    //playerMovement::setRadius(radius-_globalBoundHeight);
    
}

void playerBulletSFML::drawPlayer(sf::RenderWindow &window){
    window.draw(*_sprite);
}


void playerBulletSFML::scale(const sf::Vector2f& scale){
    _scale = scale;
    _sprite->scale(_scale);
}

sf::Vector2f playerBulletSFML::getScale() const {
    return _scale;
}


double playerBulletSFML::getGlobalBoundHeight(){
    return _globalBoundHeight;
}

void playerBulletSFML::setScale(const sf::Vector2f& newScale){
    _scale = newScale;
    _sprite->setScale(newScale);
}

std::shared_ptr<sf::Sprite> playerBulletSFML::getSprite(){
    //std::shared_ptr<sf::Sprite> temp(&_sprite);
    return _sprite;
}

void playerBulletSFML::setPosition(const Position& newPos){
    _sprite->setPosition(sf::Vector2f(newPos.x,newPos.y));
}

void playerBulletSFML::rotate(const double& angle){
    _sprite->rotate(angle);
}