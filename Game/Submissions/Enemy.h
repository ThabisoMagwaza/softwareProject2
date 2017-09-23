#pragma once

#include "enemyMovement.h"
#include <iostream>


class Enemy: public enemyMovement{
public:
    Enemy();
    void initialize(std::string imageDir,Position& startPosition, Position& origin);
    std::string getImageDir() const;
    void setImageDir(const std::string& imageDir);
private:
    std::string _imageDir;
};