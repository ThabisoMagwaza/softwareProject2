#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "gameSettings.h"
#include "Position.h"
#include <iostream>
#include <vector>

class Playing{

public:
   Playing(const gameSettings& settings);
   bool playerBullet_Enemy_Collision(const int& bullet) const;
   bool player_Enemy_Collison(const int& enemy)  const;
   void setEnemyMovingAngles(std::vector<int> angles);
   void advanceEnemies();
   void advancePlayerBullets();
   void advanceEnemyBullet();
   void addEnemyBulllet();
   void addPlayerBullet();
   void resetGame();
   
private:
    std::unique_ptr<Player> _player;
    std::vector<std::shared_ptr<Enemy>> _enemies; 
    std::vector<int> _enemyMovingAngles;
    gameSettings _settings;
};