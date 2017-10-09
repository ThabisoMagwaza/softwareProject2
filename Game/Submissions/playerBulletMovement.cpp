#include "playerBulletMovement.h"
#include <cmath>


void playerBulletMovement::shootToCenter(std::shared_ptr<Position> currentLocation,const Position& origin, const double& angle, double& currentDisplacement, const double& speed){
    currentDisplacement -=speed;
    currentLocation->x = origin.x + ((currentDisplacement) * cos(angle*(3.14/180)));
    currentLocation->y = origin.y + ((currentDisplacement) * sin(angle*(3.14/180)));
}



//Position playerBulletMovement::shootFromEnemy(){
//    _displacement +=_speed;
//    _location.x = _origin.x + ((_displacement) * cos(_angle*(3.14/180)));
//    _location.y = _origin.y + ((_displacement) * sin(_angle*(3.14/180)));
//    
//    return _location;
//}

