#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Background.h"
#include "Movement.h"
#include "playerSFML.h"
#include <iostream>
#include <memory>

class Game{
    public:
     static void GameStart();
     
     private:
     static void MainLoop();
     static bool isQuiting();
     static void dispSplash();
     static void dispBackground();
     static Background _background;
     enum class GameMode {Playing, Quiting, Splash, Menu, Uninitialized};
     static sf::RenderWindow Window1;
     static GameMode Mode;
     static playerSFML _player;
     static double _screenWidth;
     static double _screenHeight;
     
     //static Player _player1;
     //static Player _player2;
};