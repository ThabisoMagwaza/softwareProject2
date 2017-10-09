#pragma once
//#include "Movement.h"
#include "playerMovement.h"
//player for the game

//#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "boundRect.h"


class Player : public playerMovement{

public:
    Player(Position& startPosition, const double& startingAngle, const double& startingRadius, const int& lives = 3);
    void setLocation(Position& newLocation);
    std::shared_ptr<Position> getLocation();
    std::shared_ptr<boundRect> getBoundRect();
    double getAngle() const;
    void setRadius(const double& newRadius);
    double getRadius() const;
    void move(char dir, Position& origin, const double& speed = 1);
    void damage();
    void addLives(const int& lives);
    void setLives(const int& lives);
    int getLives() const;
    bool isAlive() const;
    

private:
    std::shared_ptr<Position> _location;
    std::shared_ptr<boundRect> _boundRect;
    double _angle; //angle on the playing circle of the player
    double _radius; // radius on the playing circle
    int _lives;
};
