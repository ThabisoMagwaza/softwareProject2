#include "enemyMovement.h"
#include <cmath>


void enemyMovement::moveStraightFromCentre(std::shared_ptr<Position> location,const Position& origin, double& currentDisp,const double& angle, const double& speed){
    currentDisp +=speed;
    location->x = origin.x + ((currentDisp) * cos(angle*(3.14/180)));
    location->y = origin.y + ((currentDisp) * sin(angle*(3.14/180)));
}


void enemyMovement::spiralFromCenter(std::shared_ptr<Position> location,const Position& origin, double& currentAngle,const double& speed){
    currentAngle += speed;
    location->x = origin.x + (0.2*(currentAngle )*cos(currentAngle *(3.14/180)));
    location->y = origin.y + (0.2*(currentAngle)*sin(currentAngle *(3.14/180)));
}
