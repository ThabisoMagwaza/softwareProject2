#include "Game.h"
#include "SplashScreen.h"
#include "Background.h"

double Game::_screenWidth = 1024;
double Game::_screenHeight = 640;
Playing Game::_playing;
//playerSFML Game::_player{"resources/ship.png",sf::Vector2f((_screenWidth/2),_screenHeight),sf::Vector2f((_screenWidth/2),(_screenHeight/2)),(_screenHeight/2)};
//enemySFML Game::_enemy{"resources/villain.png",sf::Vector2f((_screenWidth/2),(_screenHeight/2)),sf::Vector2f((_screenWidth/2),(_screenHeight/2))};
Background Game::_background;

//This function initializes the game!
void Game::GameStart(){
    Window1.create(sf::VideoMode(_screenWidth,_screenHeight,32),"Game",sf::Style::Close | sf::Style::Titlebar);
    Window1.setKeyRepeatEnabled(false);
    
    
    _playing.initializeWindow(Window1, _screenHeight/2);
    //_playing.initializePlayer("resources/ship.png",sf::Vector2f((_screenWidth/2),_screenHeight),sf::Vector2f((_screenWidth/2),(_screenHeight/2)),(_screenHeight/2));
    //_playing.initializeEemey("resources/villain.png",sf::Vector2f((_screenWidth/2),(_screenHeight/2)),sf::Vector2f((_screenWidth/2),(_screenHeight/2)));
    _playing.resetGame("resources/ship.png",sf::Vector2f((_screenWidth/2),_screenHeight),sf::Vector2f((_screenWidth/2),(_screenHeight/2)),(_screenHeight/2),"resources/villain2.png",sf::Vector2f((_screenWidth/2),(_screenHeight/2)),sf::Vector2f((_screenWidth/2),(_screenHeight/2)),"resources/villain.png");
    
    while(!isQuiting()){
    MainLoop();
    }   
    Window1.close();
}
//Checks if the game is still played or no!
bool Game::isQuiting(){ return (Mode==Game::GameMode::Quiting);}


void Game::dispSplash(){
    SplashScreen screen;
    screen.show(Window1);
    //After displaying the splash screen, the game must display the menu!
    Mode = Game::GameMode::Playing;
}



void Game::MainLoop(){
        
        switch (Mode){
            //Case Handler for the splash in the initialization.
            case Game::GameMode::Splash:
                dispSplash();
                break;
            
            case Game::GameMode::Playing:
                dispBackground();
            
                if(!_playing.play()){
                    Mode = Game::GameMode::GameOver;
                    //_playing.initializeWindow(Window1, _screenHeight/2);
                    _playing.resetGame("resources/ship.png",sf::Vector2f((_screenWidth/2),_screenHeight),sf::Vector2f((_screenWidth/2),(_screenHeight/2)),(_screenHeight/2),"resources/villain2.png",sf::Vector2f((_screenWidth/2),(_screenHeight/2)),sf::Vector2f((_screenWidth/2),(_screenHeight/2)),"resources/villain.png");
                    
                }
               // Window1.clear();
                
                _playing.display();
                 Window1.display();

                break;
            case Game::GameMode::GameOver:
                dispGameOver();
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


void Game::dispBackground(){
    _background.drawBackground(Window1);
    Mode = Game::GameMode::Playing;
}

void Game::dispGameOver(){
    GameOver screen;
    screen.display(Window1);
    Game::Mode = Game::GameMode::Splash;
}



Game::GameMode Game::Mode = Game::GameMode::Splash;
sf::RenderWindow Game::Window1;