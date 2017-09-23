#include "playerMovement.h"
#include <cmath>

playerMovement::playerMovement(){
    //_displacement = 0;
    _currentAngle = 0;
    Position loc;
    Position orig;
    _location = loc;
    _origin = orig;
}

void playerMovement::initialize(Position& startPosition, Position& origin,const double& radius,const double& startAngle){
    _currentAngle = startAngle;
    _origin = origin;
    _radius = radius;
    _location = startPosition;
}

Position playerMovement::rotateRight( const double& rotationAngle){
    _currentAngle -= rotationAngle;

    _location.x = _origin.x + (_radius * cos(_currentAngle*(3.14/180)));
    _location.y = _origin.y + (_radius * sin(_currentAngle *(3.14/180)));
    
    return _location;
}

Position playerMovement::rotateLeft( const double& rotationAngle){
    _currentAngle += rotationAngle;

    _location.x = _origin.x + (_radius * cos(_currentAngle*(3.14/180)));
    _location.y = _origin.y + (_radius * sin(_currentAngle *(3.14/180)));
    
    return _location;
}

void playerMovement::setLocation(Position& newLocation){
    _location = newLocation;
}

Position playerMovement::getLocation() const {
    return _location;
}

void playerMovement::setRadius(const double& newRadius){
    _radius = newRadius;
}

double playerMovement::getRadius() const {
    return _radius;
}

void playerMovement::setCurrentAngle(const double& newAngle){
    _currentAngle = newAngle;
}

double playerMovement::getCurrentAngle() const {
    return _currentAngle;
}