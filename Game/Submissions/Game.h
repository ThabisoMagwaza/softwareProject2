#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Background.h"
#include <iostream>
#include <memory>
#include "Playing.h"
#include "GameOver.h"
#include "Display.h"
#include "Controls.h"
#include "GameMode.h"
#include "Screen.h"
#include "ScreenData.h"

class Game{
public:
     static void GameStart();
     static gameSettings getSettings() ;
private:
	static void makeScreens();
    static bool play();
    static void resetGame();
    static void MainLoop();
    static bool isQuiting();
    static void dispSplash();
    static void dispBackground();
    static void dispGameOver();
    static Background _background;
    static GameMode Mode;
    static std::unique_ptr<Playing> _playing;
    static gameSettings _settings;
    static Display _display;
    static Controls _controls;
	static std::vector<Screen> _screens;
	static ScreenData _screenData;
};