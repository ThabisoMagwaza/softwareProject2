#include "Position.h"

Position::Position(){
    x = 0;
    y = 0;
}

Position::Position(const double& _x, const double& _y){
    x = _x;
    y = _y;
}

bool Position::operator==( const Position& rhs){
    return ((x == rhs.x) && (y == rhs.y));
}