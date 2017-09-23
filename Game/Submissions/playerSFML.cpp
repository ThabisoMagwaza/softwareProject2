#include "playerSFML.h"

playerSFML::playerSFML(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin,const double& radius,const sf::Vector2f& scale)
//:Player(imageDir,Position::Position(startPosition.x,startPosition.y),Position::Position(startPosition.x,startPosition.y),radius)
{
    if(!_texture.loadFromFile(imageDir)){
        cannotLoadImage err;
        throw err;
        std::cerr<<"Cannot load image";
    }
    _sprite.setTexture(_texture);
    _scale = scale;
    _sprite.setScale(_scale);

    _globalBoundHeight = _sprite.getGlobalBounds().height;
    _sprite.setOrigin(_sprite.getOrigin().x,_sprite.getOrigin().y + _globalBoundHeight);
    auto temp = sf::Vector2f(startPosition.x,startPosition.y);
    _sprite.setPosition(temp);
    
    Position startP;
    startP.setPosition(temp.x,temp.y);
    Position Origin;
    Origin.setPosition(origin.x,origin.y);
    
    Player::initialize(imageDir,startP,Origin,radius);
    //playerMovement::setRadius(radius-_globalBoundHeight);
    
}

void playerSFML::drawPlayer(sf::RenderWindow &window){
    window.draw(_sprite);
}


void playerSFML::scale(const sf::Vector2f& scale){
    _scale = scale;
    _sprite.scale(_scale);
}

sf::Vector2f playerSFML::getScale() const {
    return _scale;
}


double playerSFML::getGlobalBoundHeight(){
    return _globalBoundHeight;
}

void playerSFML::setScale(const sf::Vector2f& newScale){
    _scale = newScale;
    _sprite.setScale(newScale);
}

std::shared_ptr<sf::Sprite> playerSFML::getSprite(){
    std::shared_ptr<sf::Sprite> temp(&_sprite);
    return temp;
}

void playerSFML::setPosition(const Position& newPos){
    _sprite.setPosition(sf::Vector2f(newPos.x,newPos.y));
}

void playerSFML::rotate(const double& angle){
    _sprite.rotate(angle);
}