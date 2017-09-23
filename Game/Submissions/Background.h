#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Background{

public:
    Background();
    void drawBackground(sf::RenderWindow& window1);
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    
};

