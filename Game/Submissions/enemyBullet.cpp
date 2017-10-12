#include "enemyBullet.h"
#include <iostream>

int enemyBullet::_numberOfbullets = 0;

enemyBullet::enemyBullet(std::shared_ptr<Position> startPosition, const double& startDisplacement, const double& startAngle){
   // _location = std::shared_ptr<Position> (new Position(startPosition.x,startPosition.y));
    _location = startPosition;
    _boundRect = std::shared_ptr<boundRect> (new boundRect(_location));
    _displacement = startDisplacement;
    _angle = startAngle;
    _movement = std::unique_ptr<enemyBulletMovement> (new enemyBulletMovement);
    _numberOfbullets++;
}

enemyBullet::~enemyBullet(){
    _numberOfbullets--;
}

int enemyBullet::getNumberOfBullets() {
    return _numberOfbullets;
}

//void playerBullet::setLocation(Position& newLocation){
//    _location->x = newLocation.x;
//    _location->y = newLocation.y;
//    _boundRect->update(_location);
//}

std::shared_ptr<Position> enemyBullet::getLocation(){
    return _location;
}

std::shared_ptr<boundRect> enemyBullet::getBoundRect(){
    return _boundRect;
}

//void playerBullet::setDisplacement(const double& newDisp){
//    _displacement = newDisp;
//}


double enemyBullet::getDisplacement() const{
    return _displacement;
}

double enemyBullet::getAngle() const{
    return _angle;
}


bool enemyBullet::isMoving() const {
    return _displacement != 0;
}

void enemyBullet::shoot(Position& origin,const double& speed){
    _movement->shoot(_location,origin,_angle,_displacement,speed);
    _boundRect->update(_location);
}