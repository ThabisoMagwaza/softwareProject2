#include "Game.h"
#include "SplashScreen.h"
#include "Background.h"

Background Game::_background;

gameSettings Game::_settings;
Controls Game::_controls;
std::unique_ptr<Playing> Game::_playing = std::unique_ptr<Playing>(new Playing(Game::getSettings()));
Display Game::_display = Display(Game::_settings);

//This function initializes the game!
void Game::GameStart(){
    Game::Mode = Game::GameMode::Playing;
    while(!isQuiting()){
    MainLoop();
    }   
    _display.closeWindow();
}
//Checks if the game is still played or no!
bool Game::isQuiting(){ return (Mode==Game::GameMode::Quiting);}


//void Game::dispSplash(){
//    SplashScreen screen;
//    screen.show(Window1);
//    //After displaying the splash screen, the game must display the menu!
//    Mode = Game::GameMode::Playing;
//}



void Game::MainLoop(){
        
        switch (Mode){
            //Case Handler for the splash in the initialization.
            case Game::GameMode::Splash:
                //dispSplash();
                break;
            
            case Game::GameMode::Playing:
                //dispBackground();
            
                if(!play()){
                    Mode = Game::GameMode::GameOver;
                }
                
                _display.showGame(_playing->getPositions());
               // Window1.clear();
//                
//                _playing.display();
//                 Window1.display();

                break;
            case Game::GameMode::GameOver:
                //dispGameOver();
                break;
                
//                Window1.clear();
//                dispBackground();
//                _playing.display();
//                Window1.display();
            
            //break;
        default:
            break;
        }
//                Window1.clear();
//                dispBackground();
//                _playing.display();
//                 Window1.display();
}


//void Game::dispBackground(){
//    _background.drawBackground(Window1);
//    Mode = Game::GameMode::Playing;
//}

//void Game::dispGameOver(){
//    GameOver screen;
//    screen.display(Window1);
//    Game::Mode = Game::GameMode::Splash;
//}

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
            Mode = Game::GameMode::Quiting;
            _display.closeWindow();
            return false;
        }
    }
    
    if(_controls.checkPress() == 'r'){
        _playing->movePlayer('r');
    }else if(_controls.checkPress() == 'l'){
        _playing->movePlayer('l');
    }
    
    return true;
}

Game::GameMode Game::Mode = Game::GameMode::Splash;
//sf::RenderWindow Game::Window1;