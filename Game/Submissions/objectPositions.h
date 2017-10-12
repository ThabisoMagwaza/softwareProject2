#pragma once
#include "Position.h"
#include <iostream>
#include <vector>

class objectPositions{
    friend class Playing;
private:
    std::shared_ptr<Position> playerPos = NULL;
    std::vector<std::shared_ptr<Position>> enemyPos;
    std::vector<std::shared_ptr<Position>> playerBulletsPos;
    std::vector<std::shared_ptr<Position>> enemyBulletsPos;
};