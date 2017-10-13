#include "Display.h"

Display::Display(const gameSettings& settings){
    _settings = settings;
    _window = std::shared_ptr<sf::RenderWindow> (new sf::RenderWindow(sf::VideoMode(_settings.screenWidth,_settings.screenHeight,32),"Game",sf::Style::Close | sf::Style::Titlebar));
    //_window.create(sf::VideoMode(_settings.screenWidth,_settings.screenHeight,32),"Game",sf::Style::Close | sf::Style::Titlebar);
    //_window.setKeyRepeatEnabled(false);
    
    makePlayer();
}

void Display::makePlayer(){
    //_playerTexture = std::shared_ptr<sf::Texture> (new sf::Texture);
    if(!_playerTexture.loadFromFile(_settings.playerImageDirectory)){
        cannotLoadImage err;
        throw err;
    }
    
    _playerSprite.setTexture(_playerTexture);
}

void Display::drawPlayer(){
    _window->draw(_playerSprite);
}

void Display::updatePlayer(){
    //auto temp = sf::Vector2f(_positions->playerPos->x,_positions->playerPos->y);
    auto temp = sf::Vector2f(0,0);
    _playerSprite.setPosition(temp);
}

void Display::showGame(std::shared_ptr<objectPositions> newPositions){
    _window->clear();
    updatePosition(newPositions);
    updatePlayer();
    drawPlayer();
    
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