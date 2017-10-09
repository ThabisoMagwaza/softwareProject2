#pragma once

#include <SFML/Graphics.hpp>
#include "playerSFML.h"
#include "enemySFML.h"
#include "playerBulletSFML.h"
#include <iostream>
#include <queue>

class Playing{
public:
   Playing();
   void initializeWindow(sf::RenderWindow& window, const double& playingRadius);
   void initializePlayer(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin,const double& radius);
   void initializeEemey(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin,const int& numEnemies = 3);
   void initializeSpiralEnemy(std::string imageDir,const sf::Vector2f& startPosition, const sf::Vector2f& origin,const int& numEnemies = 1);
   bool collision(std::shared_ptr<sf::Sprite> sprite1, std::shared_ptr<sf::Sprite> sprite2) ;
   bool playerBullet_EnemyCollision(std::shared_ptr<playerBulletSFML> bullet);
   bool play();
   void display() const;
   void reset();
   void advanceBullets();
   void addEnemyBulllet();
   void addBullet();
   void resetGame(std::string p_imageDir,const sf::Vector2f& p_startPosition, const sf::Vector2f& p_origin,const double& p_radius,std::string e_imageDir,const sf::Vector2f& e_startPosition, const sf::Vector2f& e_origin,const std::string& se_imageDir,const int& numEnemies = 1);
   
private:
    std::shared_ptr<playerSFML> _player;
    std::vector< std::shared_ptr<enemySFML> > _enemies; 
    std::vector< std::shared_ptr<enemySFML> > _spriralEnemy;
    std::vector< std::shared_ptr<playerBulletSFML>> _enemyBulluets;
    std::shared_ptr<sf::RenderWindow> _window;
    std::vector<int> _enemyMovingAngles;
    std::vector<std::shared_ptr<playerBulletSFML>> _bullets;
    double _playingRadius;
};