#include "playerBullet.h"
#include <iostream>

playerBullet::playerBullet(){
    _imageDir = "";
}

void playerBullet::initialize(std::string imageDir, Position& startPosition, Position& origin, const double& startDisplacement, const double& angle)
{
    _imageDir = imageDir;
    playerBulletMovement::initialize(startPosition,origin,startDisplacement,angle);
}

std::string playerBullet::getImageDir() const {
    return _imageDir;
}

void playerBullet::setImageDir(const std::string& imageDir){
    _imageDir = imageDir;
}