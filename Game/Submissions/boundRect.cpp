#include "boundRect.h"

boundRect::boundRect(std::shared_ptr<Position> pos, const double& w, const double& h){
    addVertice(pos->x - w,pos->y - h); //topLeft
    addVertice(pos->x + w,pos->y - h); //topRight
    addVertice(pos->x - w,pos->y + h); //bottomLeft
    addVertice(pos->x + w,pos->y + h); //bottomRight
    
    _width = w;
    _height = h;
    _center = pos;
}

//bool boundRect::operator ==(const boundRect& rhs){
//    for(unsigned int i = 0; i<_vertices.size();i++ ){
//        if(!((*_vertices[i]) == (*(rhs._vertices[i]))))
//            return false;
//    }
//    return true;
//}

bool boundRect::intersects(std::shared_ptr<boundRect> rhs){
    auto numVertices = _vertices.size();
    
    auto lhs_tl_x = _vertices[0]->x; //x-value of topLeft Vertice
    auto lhs_tr_x = _vertices[1]->x; // x-value of topRight vertcice
    auto lhs_tr_y = _vertices[1]->y; // y_value of topRight vertice
    auto lhs_br_y = _vertices[3]->y; // y_value of bottomRight vertice
    
    // for the ith vertice of rectable rhs to lie in the rectangle lhs
    // for the rectangles to intersect, at least one vertice of rectangle rhs must lie in rectangle lhs
    // (lhs_tl_x <= rhs[i]_x <= lhs_tr_x) && (lhs_tr_y <= rhs[i]_y <= lhs_br_y) 
    
    // return true if any of the vertices of rectangle rhs lie in rectange lhs
    for(unsigned int i = 0;i<numVertices;i++){
        auto rhs_x = rhs->_vertices[i]->x;
        auto rhs_y = rhs->_vertices[i]->y;
        if((lhs_tl_x <= rhs_x && rhs_x <= lhs_tr_x) && (lhs_tr_y <= rhs_y && rhs_y <= lhs_br_y)){
            return true;
        }
    }
    return false;
}

std::vector<std::shared_ptr<Position>> boundRect::getVertices(){
    return _vertices;
}

void boundRect::addVertice(double x, double y){
    auto temp = std::shared_ptr<Position>(new Position(x,y));
    _vertices.push_back(temp);
}

void boundRect::scale(const double& factor){
    
    changeVertices((_width*factor),(_height*factor));
}

void boundRect::changeVertices(const double& w, const double& h){
    _vertices.clear();

    addVertice(_center->x - w,_center->y - h); //topLeft
    addVertice(_center->x + w,_center->y - h); //topRight
    addVertice(_center->x - w,_center->y + h); //bottomLeft
    addVertice(_center->x + w,_center->y + h); //bottomRight
    
    _width = w;
    _height = h;
}

void boundRect::update(std::shared_ptr<Position> newPos){
    _center = newPos;
    changeVertices(_width,_height);
}