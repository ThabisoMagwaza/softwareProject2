#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
//controls movement of game objects


class Movement{
public:
    Movement();
    void initialize(const sf::Vector2f& startPosition , const sf::Vector2f& origin,  const double& radius,const double& globalBoundsHeight , const double& startAngle = 90);
    void rotateRight(const double rotationAngle = 1);
    void rotateLeft(const double& rotationAngle = 1);
    void setLocation(const sf::Vector2f& newLocation);
    void moveStraightFromCentre(const double& angle, const double& speed = 1);
    void moveStraightToCentre(const double& angle, const double& speed = 1);
    void setDisplacement(const double& disp);
    double getDisplacement() const;
    double getCurrentAngle() const;
    double getRadius() const;
    sf::Vector2f getLocation() const;
    std::shared_ptr<sf::Sprite> getSprite();
private:
    sf::Sprite _sprite;
    sf::Vector2f _location;
    sf::Vector2f _origin; //center of screen
    double _displacement;
    double _radius; //radius of movement circle
    double _currentAngle; //current angle on circular moving radius
    
};