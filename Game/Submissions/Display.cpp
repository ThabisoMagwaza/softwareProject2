#include "Display.h"

Display::Display(const gameSettings& settings){
    _settings = settings;
    _window = std::shared_ptr<sf::RenderWindow> (new sf::RenderWindow(sf::VideoMode(_settings.screenWidth,_settings.screenHeight,32),"Game",sf::Style::Close | sf::Style::Titlebar));
    _window->setKeyRepeatEnabled(false);
    
    makePlayer();
    makeEnemies();
	makePlayerBullets();
	makeEnemyBullets();
}

void Display::makePlayer(){
    //_playerTexture = std::shared_ptr<sf::Texture> (new sf::Texture);
    if(!_playerTexture.loadFromFile(_settings.playerImageDirectory)){
        cannotLoadImage err;
        throw err;
    }
    
    _playerSprite.setTexture(_playerTexture);
    _playerSprite.setOrigin(_settings.playerImageCenter.x,_settings.playerImageCenter.y);
    
    _playerSprite.scale(sf::Vector2f(0.25,0.25));
}

void Display::drawPlayer(){
    _window->draw(_playerSprite);
}

void Display::updatePlayer(){
    auto temp = sf::Vector2f(_positions->playerPos->x,_positions->playerPos->y);
    _playerSprite.setPosition(temp);
}

void Display::showGame(std::shared_ptr<objectPositions> newPositions,const GameMode& mode){
    _window->clear();
    switch(mode){
        case GameMode::Playing:
            updatePosition(newPositions);
            updatePlayer();
            drawPlayer();
			updateEnemies();
			drawEnemies();
			updatePlayerBullets();
			drawPlayerBullets();
			updateEnemyBullets();
			drawEnemyBullets();
            break;
        case GameMode::Splash:
            break;
        case GameMode::GameOver:
            break;
        default:
            break;
    }
    _window->display();
}

void Display::closeWindow(){
    _window->close();
}

std::shared_ptr<sf::RenderWindow> Display::getWindow(){
    return _window;
}

void Display::updatePosition(std::shared_ptr<objectPositions> newPositions){
    _positions = newPositions;
}

void Display::makeEnemies(){
	
    for(auto i = 0;i<_settings.numberOfEnemies;i++){
		auto tempTexture = std::make_shared<sf::Texture>();
		
        if(!tempTexture->loadFromFile(_settings.enemyImageDirectory)){
            cannotLoadImage err;
            throw err;
        }
		_enemyTextures.push_back(tempTexture);
        auto tempSprite = std::make_shared<sf::Sprite>();
		tempSprite->setTexture(*tempTexture);
		tempSprite->setOrigin(_settings.enemyImageCenter.x,_settings.enemyImageCenter.y);
		tempSprite->scale(sf::Vector2f(0.3,0.3));
		
		_enemySprites.push_back(tempSprite);
    }

}

void Display::updateEnemies(){
	for(unsigned int i = 0;i<_positions->enemyPos.size();i++){
		_enemySprites.at(i)->setPosition(_positions->enemyPos.at(i)->x,_positions->enemyPos.at(i)->y);
	}
}

void Display::drawEnemies(){
	for(unsigned int i = 0;i<_positions->enemyPos.size();i++){
		_window->draw(*(_enemySprites.at(i)));
	}
}

void Display::makePlayerBullets(){
	for(unsigned int i = 0;i<_settings.maxPlayerBullets;i++){
		auto tempTexture = std::make_shared<sf::Texture>();
		
		if(!tempTexture->loadFromFile(_settings.playerBulletImageDir)){
			cannotLoadImage err;
            throw err;
		}
		
		_playerBulletTextures.push_back(tempTexture);
		auto tempSprite = std::make_shared<sf::Sprite>();
		tempSprite->setTexture(*tempTexture);
		tempSprite->setOrigin(_settings.playerBulletImageCenter.x,_settings.playerBulletImageCenter.y);
		tempSprite->scale(sf::Vector2f(0.1,0.1));
		_playerBulletSprites.push_back(tempSprite);
	}
}

void Display::drawPlayerBullets(){
	for(unsigned int i = 0;i<_positions->playerBulletsPos.size();i++){
		_window->draw(*(_playerBulletSprites.at(i)));
	}
}

void Display::updatePlayerBullets(){
	for(unsigned int i = 0;i<_positions->playerBulletsPos.size();i++){
		_playerBulletSprites.at(i)->setPosition(_positions->playerBulletsPos.at(i)->x,_positions->playerBulletsPos.at(i)->y);
	}
}

void Display::makeEnemyBullets(){
	for(auto i = 0; i<_settings.numberOfEnemies;i++){
		auto tempTexture = std::make_shared<sf::Texture>();
		
		if(!tempTexture->loadFromFile(_settings.enemyBulletImageDir)){
			cannotLoadImage err;
			throw err;
		}
		
		_enemyBulletTextures.push_back(tempTexture);
		
		auto tempSprite = std::make_shared<sf::Sprite>();
		tempSprite->setTexture(*tempTexture);
		tempSprite->setOrigin(_settings.enemyBulletImageCenter.x,_settings.enemyBulletImageCenter.y);
		tempSprite->scale(sf::Vector2f(0.3,0.3));
		
		_enemyBulletSprites.push_back(tempSprite);
	}
}

void Display::drawEnemyBullets(){
	for(unsigned int i = 0; i<_positions->enemyBulletsPos.size();i++){
		_window->draw(*(_enemyBulletSprites.at(i)));
	}
}

void Display::updateEnemyBullets(){
	for(unsigned int i = 0; i<_positions->enemyBulletsPos.size();i++){
		_enemyBulletSprites.at(i)->setPosition(_positions->enemyBulletsPos.at(i)->x,_positions->enemyBulletsPos.at(i)->y);
	}
}
