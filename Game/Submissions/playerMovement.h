#pragma once

#include <iostream>
#include <memory>
#include "Position.h"

class playerMovement{
    friend class Player;
private:
    playerMovement(){};
    void anticlockwise(std::shared_ptr<Position> currentLocation, Position& origin,  double& currentAngle, const double& radius, const double& speed = 1);
    void clockwise(std::shared_ptr<Position> currentLocation, Position& origin, double& currentAngle, const double& radius, const double& speed = 1);
};