#include "Player.h"


Player::Player(Position& startPosition, const double& startingAngle, const double& startingRadius, const int& lives){
    _location = std::shared_ptr<Position> ( new Position(startPosition.x,startPosition.y));
    _angle = startingAngle;
    _radius = startingRadius;
    _boundRect = std::shared_ptr<boundRect> (new boundRect(_location));
    _lives = lives;
    _movement = std::unique_ptr<playerMovement> (new playerMovement);
}

void Player::setLocation(Position& newLocation){
    _location->x = newLocation.x;
    _location->y = newLocation.y;\
    _boundRect->update(_location);
}

std::shared_ptr<Position> Player::getLocation(){
    return _location;
}

std::shared_ptr<boundRect> Player::getBoundRect() {
    return _boundRect;
}

double Player::getAngle() const{
    return _angle;
}

void Player::setRadius(const double& newRadius){
    _radius = newRadius;
}

double Player::getRadius() const {
    return _radius;
}

void Player::move(char dir, Position& origin, const double& speed){
    switch(dir){
        case 'r':
            _movement->anticlockwise(_location,origin,_angle,_radius,speed);
            break;
        case 'l':
            _movement->clockwise(_location,origin,_angle,_radius,speed);
            break;
        default:
            break;
    }
    _boundRect->update(_location);
}

void Player::damage(){
    _lives--;
}

void Player::addLives(const int& lives){
    _lives+= lives;
}

void Player::setLives(const int& lives){
    _lives = lives;
}

int Player::getLives() const {
    return _lives;
}

bool Player::isAlive() const{
    return _lives != 0;
}

void Player::addBullet(){
    _bullets.push_back(std::shared_ptr<playerBullet> (new playerBullet(_location,_radius,_angle)));
}

void Player::removeBullet(const int& bullet){
    _bullets.erase(_bullets.begin() + (bullet -1));
}

std::vector<std::shared_ptr<playerBullet>> Player::getBullets(){
    return _bullets;
}