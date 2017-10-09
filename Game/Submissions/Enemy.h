#pragma once

#include "enemyMovement.h"
#include "Position.h"
#include "boundRect.h"
#include <iostream>
#include <memory>


class Enemy: public enemyMovement{
public:
    Enemy(Position& startPosition, const double& startDisplacement = 0, const double& startingAngle = 0, const int& health = 20);
    void setHealth(const int& lives);
    int getHealth() const;
    void damage(const int& damage);
    bool isAlive() const;
    double getDisplacement() const;
    void setDisplacement(const double& newDisp);
    void move(char dir, const Position& origin,  const double& speed = 0.5,const double& angle = 0);
    bool isMoving() const;
    void setLocation( std::shared_ptr<Position> newLocation);
    std::shared_ptr<Position> getLocation();
    std::shared_ptr<boundRect> GetBoundsRect();
private:
    double calculateDisplacement(const Position& origin) const;
    std::shared_ptr<Position> _location;
    std::shared_ptr<boundRect> _boundRect;
    double _displacement; //displacement from center of screen
    double _angle; //current angle on circular moving radius
    int _health;
};