#pragma once 
#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "objectPositions.h"
#include "gameSettings.h"
#include "cannotLoadImage.h"
#include "GameMode.h"
#include "Screen.h"

class Display{
public:
    Display(const gameSettings& _settings);
    void makePlayer(); // sets sprite and texture
    void drawPlayer(); 
    void updatePosition(std::shared_ptr<objectPositions> newPositions);
    void updatePlayer(); //updates sprite positions  
    void showGame(std::shared_ptr<objectPositions> newPositions,const GameMode& mode);
    void closeWindow();
    std::shared_ptr<sf::RenderWindow> getWindow();
    void makeEnemies();
    void drawEnemies();
	void updateEnemies();
	void makePlayerBullets();
	void drawPlayerBullets();
	void updatePlayerBullets();
	void makeEnemyBullets();
	void drawEnemyBullets();
	void updateEnemyBullets();
	void makeScreens(std::vector<Screen> screens);
	void drawScreen(const int& screen);
    
private:
	int _splashScreen;
	int _background;
	int _gameOverScreen;
	void setText( Screen& screen);
	void drawText(const int& screen);
    std::shared_ptr<sf::RenderWindow> _window;
	std::vector<std::shared_ptr<sf::Sprite>> _screenSprites;
	std::vector<std::shared_ptr<sf::Texture>> _screenTextures;
	std::vector<std::vector<std::shared_ptr<sf::Text>>> _screenText;
    sf::Sprite _playerSprite;
    sf::Texture _playerTexture;
    std::vector<std::shared_ptr<sf::Sprite>> _enemySprites;
    std::vector<std::shared_ptr<sf::Texture>> _enemyTextures;
    std::vector<std::shared_ptr<sf::Sprite>> _playerBulletSprites;
    std::vector<std::shared_ptr<sf::Texture>> _playerBulletTextures;
    std::vector<std::shared_ptr<sf::Sprite>> _enemyBulletSprites;
    std::vector<std::shared_ptr<sf::Texture>> _enemyBulletTextures;
    std::shared_ptr<objectPositions> _positions;
    gameSettings _settings;
	sf::Font _font;
};