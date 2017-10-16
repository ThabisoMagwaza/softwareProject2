#include "Game.h"
#include "SplashScreen.h"
#include "Background.h"

Background Game::_background;

gameSettings Game::_settings;
Controls Game::_controls;
std::unique_ptr<Playing> Game::_playing = std::unique_ptr<Playing>(new Playing(Game::getSettings()));
Display Game::_display = Display(Game::_settings);
GameMode Game::Mode = GameMode::Splash;
ScreenData Game::_screenData;
std::vector<Screen> Game::_screens;

//This function initializes the game!
void Game::GameStart(){
    Mode = GameMode::Playing;
	makeScreens();
	_display.makeScreens(_screens);
    while(!isQuiting()){
    MainLoop();
    }   
    _display.closeWindow();
}
//Checks if the game is still played or no!
bool Game::isQuiting(){ return (Mode == GameMode::Quiting);}

void Game::MainLoop(){
        
        switch (Mode){
            //Case Handler for the splash in the initialization.
            case GameMode::Splash:
                //dispSplash();
                break;
            
            case GameMode::Playing:
                //dispBackground();
            
                if(!play()){
                    Mode = GameMode::GameOver;
                }
                
                _display.showGame(_playing->getPositions(),Mode);

                break;
            case GameMode::GameOver:
                //dispGameOver();
                break;
                
        default:
            break;
        }

}


void Game::resetGame(){
    _playing = NULL;
    _playing = std::unique_ptr<Playing>(new Playing(_settings));
}

gameSettings Game::getSettings() {
    return _settings;
}

bool Game::play(){
    sf::Event EventNow;
    
    while(_display.getWindow()->pollEvent(EventNow)){
        if(EventNow.type == sf::Event::Closed){
            Mode = GameMode::Quiting;
            _display.closeWindow();
            return false;
        }
    }
    
    if(_controls.checkPress() == 'r'){
        _playing->movePlayer('r');
    }else if(_controls.checkPress() == 'l'){
        _playing->movePlayer('l');
    }else 
		
	if(_controls.checkPress() == 'x'){
		_playing->addPlayerBullet();
	}
    
	_playing->advancePlayerBullets();
    _playing->advanceEnemies();
    
    return true;
}

void Game::makeScreens(){
	_screens.push_back(Screen(_screenData.SplashDirectory,_screenData.SplashText,_screenData.SplashPos)); //splashscreen
	_screens.push_back(Screen(_screenData.BackGroundDirectory)); //background
	_screens.push_back(Screen(_screenData.GameOverDirectory,_screenData.GOtext,_screenData.GOpos)); //Game over
}

