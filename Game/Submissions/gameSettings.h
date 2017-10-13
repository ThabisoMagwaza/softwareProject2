#pragma once

#include <iostream>
#include "Position.h"

class gameSettings{
public:
    gameSettings(const double& w = 1080, const double& h = 640);
    double screenWidth ;
    double screenHeight ;
    double playingRadius ;
    double playerStartingAngle ;
    int playerBulletSpeed;
    int enemyBulletSpeed;
    int enemySpeed;
    int numberOfEnemies ;
    Position playerStartingPosition;
    Position origin ;
};



