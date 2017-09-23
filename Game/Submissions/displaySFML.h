#pragma once

//constract for game objects to be displaed in SFML

class displaySFML{
public:
    virtual void drawPlayer(sf::RenderWindow &window) = 0; 
    virtual void setScale(const sf::Vector2f& newScale) = 0;
    virtual void setPosition(const Position& newPosition) = 0;
    virtual void rotate(const double& angle) = 0;
    virtual sf::Vector2f getScale() const = 0;
    virtual void scale(const sf::Vector2f& scale) = 0;
    virtual double getGlobalBoundHeight() = 0;
    virtual std::shared_ptr<sf::Sprite> getSprite() = 0;
    
};