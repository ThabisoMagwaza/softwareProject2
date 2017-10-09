#pragma once

#include <iostream>

//structure to hold player positions on a window

class Position{
public:
    Position();
    Position(const double& _x, const double& _y);
    bool operator==(const Position& rhs);
    double x;
    double y;
};