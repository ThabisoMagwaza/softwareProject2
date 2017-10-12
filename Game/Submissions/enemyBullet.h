#pragma once

#include <iostream>
#include <memory>
#include "enemyBulletMovement.h"
#include "boundRect.h"

class enemyBullet{
public:
    enemyBullet(std::shared_ptr<Position> startPosition, const double& startDisplacement, const double& startAngle);
    ~enemyBullet();
    std::shared_ptr<Position> getLocation();
    std::shared_ptr<boundRect> getBoundRect();
    double getDisplacement() const;
    double getAngle() const;
    bool isMoving() const;
    void shoot(Position& origin,const double& speed = 1 );
    static int getNumberOfBullets();

private:
    static int _numberOfbullets;
    std::shared_ptr<Position> _location;
    std::shared_ptr<boundRect> _boundRect;
    double _displacement;
    double _angle; //moving angle 
    std::unique_ptr<enemyBulletMovement> _movement;
};