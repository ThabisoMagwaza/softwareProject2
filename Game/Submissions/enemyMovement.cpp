#include "enemyMovement.h"
#include <cmath>

enemyMovement::enemyMovement(){
    _displacement = 0;
    _currentAngle = 0;
    Position loc;
    Position orig;
    _location = loc;
    _origin = orig;
}

void enemyMovement::initialize(Position& startPosition , Position& origin,  const double& startDisplacement, const double& startAngle){
    _currentAngle = startAngle;
    _origin = origin;
    _displacement = startDisplacement;
    _location = startPosition;
}

void enemyMovement::setLocation(Position& newLocation){
    _location = newLocation;
    _displacement = calculateDisplacement();
}

Position enemyMovement::getLocation() const {
    return _location;
}

void enemyMovement::setDisplacement(const double& newDisp){
    _displacement = newDisp;
}

double enemyMovement::getDisplacement() const {
    return _displacement;
}

void enemyMovement::setCurrentAngle(const double& newAngle){
    _currentAngle = newAngle;
}

double enemyMovement::getCurrentAngle() const {
    return _currentAngle;
}

Position enemyMovement::moveStraightFromCentre(const double& angle, const double& speed){
    _displacement +=speed;
    _location.x = _origin.x + ((_displacement) * cos(angle*(3.14/180)));
    _location.y = _origin.y + ((_displacement) * sin(angle*(3.14/180)));
    
    _currentAngle = angle;
    
    return _location;
}

bool enemyMovement::isMoving() const {
    return _displacement != 0;
}

Position enemyMovement::spiralFromCenter(const double& speed){
    _currentAngle += speed;
    _location.x = _origin.x + (0.6*(_currentAngle *(3.14/180))*cos(_currentAngle *(3.14/180)));
    _location.y = _origin.y + (0.6*(_currentAngle *(3.14/180))*sin(_currentAngle *(3.14/180)));
    
    _displacement = calculateDisplacement();
    
    return _location;
}

double enemyMovement::calculateDisplacement() const{
    return sqrt(pow(_location.x - _origin.x,2) + pow(_location.y - _origin.x,2));
}

Position enemyMovement::getOrigin() const{
    return _origin;
}