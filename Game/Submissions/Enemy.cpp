#include "Enemy.h"
#include <cmath>

Enemy::Enemy(Position& startPosition, const double& startDisplacement, const double& startingAngle, const int& lives){
    _location = std::shared_ptr<Position> (new Position(startPosition.x,startPosition.y));
    _boundRect = std::shared_ptr<boundRect> (new boundRect(_location));
    _displacement = startDisplacement;
    _health = lives;
    _angle = startingAngle;
    _movement = std::unique_ptr<enemyMovement> (new enemyMovement);
    _bullet = NULL;
}


void Enemy::setHealth(const int& lives){
    _health = lives;
}

int Enemy::getHealth() const {
    return _health;
}

void Enemy::damage(const int& damage){
    _health -= damage;
}

bool Enemy::isAlive() const{
    return _health != 0;
}

void Enemy::setDisplacement(const double& newDisp){
    _displacement = newDisp;
}

double Enemy::getDisplacement() const {
    return _displacement;
}

void Enemy::move(char dir,const Position& origin,const double& speed, const double& angle){
    switch(dir){
        case 'l':
            _angle = angle;
            _movement->moveStraightFromCentre(_location,origin, _displacement, _angle,speed);
            break;
        case 's':
            _movement->spiralFromCenter(_location,origin,_angle, speed);
            _displacement =  calculateDisplacement(origin);
            break;
        default:
            break;
    }
    _boundRect->update(_location);
}

void Enemy::setLocation(std::shared_ptr<Position> newLocation){
    _location = newLocation;
    //_displacement = calculateDisplacement();
    _boundRect->update(_location);
}

std::shared_ptr<Position> Enemy::getLocation(){
    return _location;
}

double Enemy::calculateDisplacement(const Position& origin) const{
    return sqrt(pow(_location->x - origin.x,2) + pow(_location->y - origin.x,2));
}

std::shared_ptr<boundRect> Enemy::getBoundRect(){
    return _boundRect;
}

std::shared_ptr<enemyBullet> Enemy::getBullet(){
    return _bullet;
}

void Enemy::shoot( Position& origin, const double& speed){
    _bullet->shoot(origin,speed);
}

void Enemy::removeBullet(){
    _bullet = NULL;
}

void Enemy::addBullet(){
    _bullet = std::shared_ptr<enemyBullet> (new enemyBullet(_location,_displacement,_angle));
}

void Enemy::setAngle(const double& angle){
    _angle = angle;
}