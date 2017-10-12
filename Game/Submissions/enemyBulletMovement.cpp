
#include "enemyBulletMovement.h"
#include <cmath>

void enemyBulletMovement::shoot(std::shared_ptr<Position> currentLocation,const Position& origin, const double& angle, double& currentDisplacement, const double& speed){
    currentDisplacement +=speed;
    currentLocation->x = origin.x + ((currentDisplacement) * cos(angle*(3.14/180)));
    currentLocation->y = origin.y + ((currentDisplacement) * sin(angle*(3.14/180)));
}