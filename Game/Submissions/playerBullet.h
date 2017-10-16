#pragma once 

#include "Position.h"
#include "boundRect.h"
#include "playerBulletMovement.h"
#include <iostream>
#include <memory>

class playerBullet{
public:
    playerBullet(std::shared_ptr<Position> startPosition, const double& startDisplacement, const double& startAngle);
    ~playerBullet();
    std::shared_ptr<Position> getLocation();
    std::shared_ptr<boundRect> getBoundRect();
    double getDisplacement() const;
	void setDisplacement(const double& disp);
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
    std::unique_ptr<playerBulletMovement> _movement;
};