#include "playerBullet.h"
#include <iostream>

playerBullet::playerBullet(Position& startPosition, const double& startDisplacement, const double& startAngle){
    _location = std::shared_ptr<Position> (new Position(startPosition.x,startPosition.y));
    _boundRect = std::shared_ptr<boundRect> (new boundRect(_location));
    _displacement = startDisplacement;
    _angle = startAngle;
}

void playerBullet::setLocation(Position& newLocation){
    _location->x = newLocation.x;
    _location->y = newLocation.y;
    _boundRect->update(_location);
}

std::shared_ptr<Position> playerBullet::getLocation(){
    return _location;
}

std::shared_ptr<boundRect> playerBullet::GetBoundsRect(){
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
    playerBulletMovement::shootToCenter(_location,origin,_angle,_displacement,speed);
    _boundRect->update(_location);
}