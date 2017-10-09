#include "playerMovement.h"
#include <cmath>

void playerMovement::anticlockwise(std::shared_ptr<Position> currentLocation, Position& origin, double& currentAngle, const double& radius, const double& speed){
    currentAngle -= speed;

    currentLocation->x = origin.x + (radius * cos(currentAngle*(3.14/180)));
    currentLocation->y = origin.y + (radius * sin(currentAngle *(3.14/180)));
    
}

void playerMovement::clockwise(std::shared_ptr<Position> currentLocation, Position& origin, double& currentAngle, const double& radius, const double& speed){
    currentAngle += speed;

    currentLocation->x = origin.x + (radius * cos(currentAngle*(3.14/180)));
    currentLocation->y = origin.y + (radius * sin(currentAngle *(3.14/180)));
}
