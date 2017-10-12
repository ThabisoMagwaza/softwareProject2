#pragma once

#include "Position.h"
#include <iostream>
#include <memory>


class enemyBulletMovement{
    friend class enemyBullet;
protected:
    enemyBulletMovement(){};
    void shoot(std::shared_ptr<Position> currentLocation,const Position& origin,const  double& angle, double& currentDisplacement, const double& speed =1);
};