#pragma once

#include <iostream>

//structure to hold player positions on a window

class Position{
public:
    Position();
    void setPosition(const double& _x, const double& _y);
//private:
    double x;
    double y;
};