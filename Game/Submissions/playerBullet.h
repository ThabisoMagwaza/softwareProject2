#pragma once

#include "playerBulletMovement.h"
#include <iostream>

class playerBullet: public playerBulletMovement{
public:
    playerBullet();
    void initialize(std::string imageDir,Position& startPosition, Position& origin, const double& startDisplacement, const double& angle);
    std::string getImageDir() const;
    void setImageDir(const std::string& imageDir);
private:
    std::string _imageDir;
    
};