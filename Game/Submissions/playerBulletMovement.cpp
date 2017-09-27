#include "playerBulletMovement.h"
#include <cmath>

playerBulletMovement::playerBulletMovement(){
    _displacement = 0;
    _angle = 0;
    Position loc;
    Position orig;
    _location = loc;
    _origin = orig;
    _speed = 0;
}

void playerBulletMovement::initialize(Position& startPosition , Position& origin,  const double& startDisplacement, const double& angle, const double& speed){
    _angle = angle;
    _origin = origin;
    _displacement = startDisplacement;
    _location = startPosition;
    _speed = speed;
}

void playerBulletMovement::setLocation(Position& newLocation){
    _location = newLocation;
}

Position playerBulletMovement::getLocation() const {
    return _location;
}

void playerBulletMovement::setDisplacement(const double& newDisp){
    _displacement = newDisp;
}

double playerBulletMovement::getDisplacement() const {
    return _displacement;
}

void playerBulletMovement::setAngle(const double& newAngle){
    _angle = newAngle;
}

double playerBulletMovement::getCurrentAngle() const {
    return _angle;
}

Position playerBulletMovement::shootToCenter(){
    _displacement -=_speed;
    _location.x = _origin.x + ((_displacement) * cos(_angle*(3.14/180)));
    _location.y = _origin.y + ((_displacement) * sin(_angle*(3.14/180)));
    
    return _location;
}

bool playerBulletMovement::isMoving() const {
    return _displacement != 0;
}

Position playerBulletMovement::shootFromEnemy(){
    _displacement +=_speed;
    _location.x = _origin.x + ((_displacement) * cos(_angle*(3.14/180)));
    _location.y = _origin.y + ((_displacement) * sin(_angle*(3.14/180)));
    
    return _location;
}

void playerBulletMovement::setSpeed(const double& speed){
    _speed = speed;
}

double playerBulletMovement::getSpeed() const{
    return _speed;
}