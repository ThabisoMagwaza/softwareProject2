#include "playerBullet.h"
#include <iostream>

int playerBullet::_numberOfbullets = 0;

playerBullet::playerBullet(std::shared_ptr<Position> startPosition, const double& startDisplacement, const double& startAngle){
    _location = std::shared_ptr<Position> (new Position(startPosition->x,startPosition->y));
    //_location = startPosition;
    _boundRect = std::shared_ptr<boundRect> (new boundRect(_location));
    _displacement = startDisplacement;
    _angle = startAngle;
    _movement = std::unique_ptr<playerBulletMovement> (new playerBulletMovement);
    _numberOfbullets++;
}

playerBullet::~playerBullet(){
    _numberOfbullets--;
}

int playerBullet::getNumberOfBullets() {
    return _numberOfbullets;
}

//void playerBullet::setLocation(Position& newLocation){
//    _location->x = newLocation.x;
//    _location->y = newLocation.y;
//    _boundRect->update(_location);
//}

std::shared_ptr<Position> playerBullet::getLocation(){
    return _location;
}

std::shared_ptr<boundRect> playerBullet::getBoundRect(){
    return _boundRect;
}

//void playerBullet::setDisplacement(const double& newDisp){
//    _displacement = newDisp;
//}


double playerBullet::getDisplacement() const{
    return _displacement;
}

double playerBullet::getAngle() const{
    return _angle;
}


bool playerBullet::isMoving() const {
    return _displacement != 0;
}

void playerBullet::shoot(Position& origin,const double& speed){
    _movement->shootToCenter(_location,origin,_angle,_displacement,speed);
    _boundRect->update(_location);
}