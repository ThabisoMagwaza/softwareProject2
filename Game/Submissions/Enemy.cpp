#include "Enemy.h"

Enemy::Enemy(){
    _imageDir = "";
}

void Enemy::initialize(std::string imageDir, Position& startPosition, Position& origin)
{
    _imageDir = imageDir;
    enemyMovement::initialize(startPosition,origin);
}

std::string Enemy::getImageDir() const {
    return _imageDir;
}

void Enemy::setImageDir(const std::string& imageDir){
    _imageDir = imageDir;
}