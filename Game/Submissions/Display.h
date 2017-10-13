#pragma once 
#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "objectPositions.h"
#include "gameSettings.h"
#include "cannotLoadImage.h"

class Display{
public:
    Display(const gameSettings& _settings);
    void makePlayer(); // sets sprite and texture
    void drawPlayer(); 
    void updatePosition(std::shared_ptr<objectPositions> newPositions);
    void updatePlayer(); //updates sprite positions  
    void showGame(std::shared_ptr<objectPositions> newPositions);
    void closeWindow();
    std::shared_ptr<sf::RenderWindow> getWindow();
    
private:
    std::shared_ptr<sf::RenderWindow> _window;
    sf::Sprite _playerSprite;
    sf::Texture _playerTexture;
    std::vector<sf::Sprite> _enemySprites;
    std::vector<sf::Texture> _enemyTextures;
    std::vector<sf::Sprite> _playerBulletSprites;
    std::vector<sf::Texture> _playerBulletTextures;
    std::vector<sf::Sprite> _enemyBulletSprites;
    std::vector<sf::Texture> _enemyBulletTextures;
    std::shared_ptr<objectPositions> _positions;
    gameSettings _settings;
};