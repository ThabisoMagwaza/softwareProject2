#pragma once

#include "playerBulletMovement.h"
#include "Position.h"
#include "boundRect.h"
#include <iostream>

class playerBullet: public playerBulletMovement{
public:
    playerBullet(Position& startPosition, const double& startDisplacement, const double& startAngle);
    void setLocation( Position& newLocation);
    std::shared_ptr<Position> getLocation();
    std::shared_ptr<boundRect> GetBoundsRect();
//    void setDisplacement(const double& newDisp);
    double getDisplacement() const ;
//    void setAngle(const double& newAngle);
    double getAngle() const ;
    bool isMoving() const;
    void shoot(Position& origin, const double& speed = 1);
private:
    std::shared_ptr<Position> _location;
    std::shared_ptr<boundRect> _boundRect;
    double _angle; //angle on the playing circle of the player
    double _displacement; // distance from origin
};