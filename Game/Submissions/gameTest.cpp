
#include "Player.h"
#include<cmath>
#include <SFML/Graphics.hpp>
//#include<iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Player starting position set correctly"){
    auto screenWidth = 1024;
    auto screenHeight = 640;
    Player testPlayer("resources/ship.png", sf::Vector2f((screenWidth/2),screenHeight));
    CHECK(testPlayer.getLocation() == sf::Vector2f(512,640-testPlayer.getGlobalBoundHeight()));
}

TEST_CASE("Right rotation correct"){
    auto screenWidth = 1024;
    auto screenHeight = 640;
    Player testPlayer("resources/ship.png", sf::Vector2f((screenWidth/2),screenHeight));
    testPlayer.rotateRight();
    
    double rotationRadius = 320 - testPlayer.getGlobalBoundHeight();
    auto centerRotation = sf::Vector2f(512,320); //center of screen
    double newAngle = 89; //staring angle is 90 degrees which is decremented by 1 as the angle increases clockwise
    //polar coordinates used 
    auto newPosition = sf::Vector2f(centerRotation.x + (rotationRadius * cos(newAngle*(M_PI/180))), centerRotation.y + (rotationRadius * sin(newAngle *(M_PI/180))));

    CHECK(testPlayer.getLocation() == newPosition);
}

TEST_CASE("Left rotation correct"){
    auto screenWidth = 1024;
    auto screenHeight = 640;
    Player testPlayer("resources/ship.png", sf::Vector2f((screenWidth/2),screenHeight));
    testPlayer.rotateLeft();
    
    double rotationRadius = 320 - testPlayer.getGlobalBoundHeight();
    auto centerRotation = sf::Vector2f(512,320); //center of screen
    double newAngle = 91; //staring angle is 90 degrees which is incremented by 1 as the angle increases clockwise
    //polar coordinates used 
    auto newPosition = sf::Vector2f(centerRotation.x + (rotationRadius * cos(newAngle*(M_PI/180))), centerRotation.y + (rotationRadius * sin(newAngle *(M_PI/180))));
    
    
    CHECK(testPlayer.getLocation() == newPosition);
}
