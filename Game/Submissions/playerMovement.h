#pragma once

#include <iostream>
#include <memory>
#include "Position.h"

class playerMovement{
public:
    playerMovement();
    void initialize(Position& startPosition , Position& origin,  const double& radius, const double& startAngle = 90);
    Position rotateRight(const double& rotationAngle = 1);
    Position rotateLeft(const double& rotationAngle = 1);
    void setLocation( Position& newLocation);
    Position getLocation() const;
    void setRadius(const double& newRadius);
    double getRadius() const ;
    void setCurrentAngle(const double& newAngle);
    double getCurrentAngle() const ;
    
private:
    Position _location;
    Position _origin;
    //double _displacement;
    double _radius; //radius of movement circle
    double _currentAngle; //current angle on circular moving radius
};