#include "Movement.h"
#include <cmath> 



Movement::Movement(){
    _displacement = 512;
    _currentAngle = 0;
    _location = sf::Vector2f(0,0);
    _sprite.setPosition(_location);
}

void Movement::initialize( const sf::Vector2f& startPosition, const sf::Vector2f& origin, const double& radius,const double& globalBoundsHeight, const double& startAngle){
    _currentAngle = startAngle;
    _origin = origin;
    _radius = radius;
    _location = sf::Vector2f(startPosition.x,startPosition.y - globalBoundsHeight);
    _sprite.setPosition(_location);
}

void Movement::rotateRight( const double rotationAngle){
    _currentAngle -= rotationAngle;

    _location.x = _origin.x + (_radius * cos(_currentAngle*(3.14/180)));
    _location.y = _origin.y + (_radius * sin(_currentAngle *(3.14/180)));
    _sprite.setPosition(_location);
    
    _sprite.rotate(-rotationAngle);
}

void Movement::rotateLeft( const double& rotationAngle){
    _currentAngle += rotationAngle;
    _location.x = _origin.x + (_radius * cos(_currentAngle*(3.14/180)));
    _location.y = _origin.y + (_radius * sin(_currentAngle *(3.14/180)));
    _sprite.setPosition(_location);
    
    _sprite.rotate(rotationAngle);
}

sf::Vector2f Movement::getLocation() const {
    return _location;
}

void Movement::setLocation(const sf::Vector2f& newLocation){
    _location = newLocation;
    _sprite.setPosition(newLocation);
}

std::shared_ptr<sf::Sprite> Movement::getSprite(){
    std::shared_ptr<sf::Sprite> temp(&_sprite);
    return temp;
}

void Movement::moveStraightFromCentre(const double& angle, const double& speed){
    _displacement +=speed;
    _location.x = _origin.x + ((_displacement) * cos(angle*(3.14/180)));
    _location.y = _origin.y + ((_displacement) * sin(angle*(3.14/180)));
    
    setLocation(_location);
}

void Movement::moveStraightToCentre(const double& angle, const double& speed ){
    _displacement -=speed;
    _location.x = _origin.x + ((_displacement) * cos(angle*(3.14/180)));
    _location.y = _origin.y + ((_displacement) * sin(angle*(3.14/180)));
    
    setLocation(_location);
}

void Movement::setDisplacement(const double& disp){
    _displacement = disp;
}

double Movement::getDisplacement() const {
    return _displacement;
}

double Movement::getCurrentAngle() const {
    return _currentAngle;
}

double Movement::getRadius() const {
    return _radius;
}