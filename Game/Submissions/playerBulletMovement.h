#pragma once

#include "Position.h"
#include <iostream>


class playerBulletMovement{
public:
    playerBulletMovement();
    void initialize(Position& startPosition , Position& origin,  const double& startDisplacement, const double& angle , const double& speed = 4);
    Position shootToCenter();
    Position shootFromEnemy(); //shoots bullet form enemy
    void setLocation( Position& newLocation);
    Position getLocation() const;
    void setDisplacement(const double& newDisp);
    double getDisplacement() const ;
    void setAngle(const double& newAngle);
    double getCurrentAngle() const ;
    bool isMoving() const;
    void setSpeed(const double& speed);
    double getSpeed() const;
private:
    Position _location;
    Position _origin;
    double _displacement; //displacement from center of screen
    double _angle; //firing angle
    double _speed;
    
};