#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "gameSettings.h"
#include "Position.h"
#include "objectPositions.h"
#include <iostream>
#include <vector>

class Playing{

public:
   Playing(const gameSettings& settings);
   bool playerBullet_Enemy_Collision(const int& bullet) const;
   bool player_Enemy_Collison()  const;
   bool enemyBullet_player_collision(const int& enemy) const;
   void setEnemyMovingAngles(std::vector<int> angles);
   bool advanceEnemies();
   bool advancePlayerBullets();
   bool advanceEnemyBullets();
   void addEnemyBulllet();
   void addPlayerBullet();
   void movePlayer(char dir);
   std::shared_ptr<objectPositions> getPositions();
	void makeEnemybullets();
private:

    void removeEnemy(const int& enemy);
    void setBoundsRects();
    void updatePositions();
    std::unique_ptr<Player> _player;
    std::vector<std::shared_ptr<Enemy>> _enemies; 
    std::vector<int> _enemyMovingAngles;
    gameSettings _settings;
    std::shared_ptr<objectPositions> _positions;
};