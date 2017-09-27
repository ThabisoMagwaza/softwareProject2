#pragma once 

#include "Position.h"
#include "iostream"

class enemyMovement{
public:
    enemyMovement();
    void initialize(Position& startPosition , Position& origin,  const double& startDisplacement = 0, const double& startAngle = 90);
    Position moveStraightFromCentre(const double& angle, const double& speed = 0.5);
    Position spiralFromCenter(const double& speed);
    void setLocation( Position& newLocation);
    Position getLocation() const;
    Position getOrigin() const;
    void setDisplacement(const double& newDisp);
    double getDisplacement() const ;
    void setCurrentAngle(const double& newAngle);
    double getCurrentAngle() const ;
    bool isMoving() const;
private:
    double calculateDisplacement() const;
    Position _location;
    Position _origin;
    double _displacement; //displacement from center of screen
    double _currentAngle; //current angle on circular moving radius
};