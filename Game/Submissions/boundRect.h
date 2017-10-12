#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Position.h"

class boundRect{
public:
    //creates a bounding rectanle around position 'pos' with height 'h' and width 'w'
    boundRect(std::shared_ptr<Position> pos, const double& w = 10, const double& h = 10);
    bool intersects(std::shared_ptr<boundRect> rhs);
    void scale(const double& factor);
    void update(std::shared_ptr<Position> newPos);
//    bool operator==(const boundRect& rhs); //checks if all the vertices are the same
    std::vector<std::shared_ptr<Position>> getVertices();

private:
    void addVertice(double x, double y);
    void changeVertices(const double& w, const double& h);
    std::vector<std::shared_ptr<Position>> _vertices;
    std::shared_ptr<Position> _center;
    double _width;
    double _height;
};