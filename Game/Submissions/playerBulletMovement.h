#pragma once

#include "Position.h"
#include <iostream>
#include <memory>


class playerBulletMovement{
    friend class playerBullet;
protected:
    playerBulletMovement(){};
    void shootToCenter(std::shared_ptr<Position> currentLocation,const Position& origin,const  double& angle, double& currentDisplacement, const double& speed =1);
};