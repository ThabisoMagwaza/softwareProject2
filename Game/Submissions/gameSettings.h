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
    int playerSpeed;
    int enemyBulletSpeed;
    int enemySpeed;
    int numberOfEnemies ;
	unsigned int maxPlayerBullets;
	int enemyBulletShootingDistance;
    Position playerBoundRectSize;
    Position enemyBoundRectSize;
//    Position playerBulletBoundRectSize;
//    Position enemyBulletBoundRectSize;
    Position playerStartingPosition;
    Position origin ;
    std::string playerImageDirectory;
    std::string enemyImageDirectory;
	std::string playerBulletImageDir;
	std::string enemyBulletImageDir;
    Position playerImageCenter;
    Position enemyImageCenter;
	Position playerBulletImageCenter;
	Position enemyBulletImageCenter;
};



