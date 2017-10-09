#pragma once 

#include "Position.h"
#include "iostream"
#include "memory"

class enemyMovement{
public:
    enemyMovement(){};
    void moveStraightFromCentre(std::shared_ptr<Position> location,const Position& origin, double& currentDisp,const double& angle, const double& speed = 0.5);
    void spiralFromCenter(std::shared_ptr<Position> location, const Position& origin, double& currentAngle, const double& speed);
};