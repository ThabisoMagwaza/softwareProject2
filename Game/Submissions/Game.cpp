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
    Window1.create(sf::VideoMode(_screenWidth,_screenHeight,32),"Game",sf::Style::Default);
    Window1.setKeyRepeatEnabled(true);
    Mode = Game::GameMode::Splash;
    
    _playing.initializeWindow(Window1);
    _playing.initializePlayer("resources/ship.png",sf::Vector2f((_screenWidth/2),_screenHeight),sf::Vector2f((_screenWidth/2),(_screenHeight/2)),(_screenHeight/2));
    _playing.initializeEemey("resources/villain.png",sf::Vector2f((_screenWidth/2),(_screenHeight/2)),sf::Vector2f((_screenWidth/2),(_screenHeight/2)));
    
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
            
                if(!_playing.play()){
                    Mode = Game::GameMode::Quiting;
                    break;
                }
                
                
                Window1.clear();
                dispBackground();
                _playing.display();
                Window1.display();
                
//                 sf::Event EventNow;
//                 
//                 //event loop
//                while(Window1.pollEvent(EventNow)){
//                //dispBackground();
//                if(EventNow.type == sf::Event::Closed){
//                     Mode = Game::GameMode::Quiting;
//                     Window1.close();
//                }
//
//            }
//            
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
//                _player.setPosition(_player.rotateRight(0.5));
//                _player.rotate(-0.5);
//            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
//                _player.setPosition(_player.rotateLeft(0.5));
//                _player.rotate(0.5);
//            }
//            
//            
//            _enemy.setPosition(_enemy.moveStraightFromCentre(50));
//            
//            Window1.clear();
//            dispBackground();
//            _player.drawPlayer(Window1);
//            _enemy.drawPlayer(Window1);
//            Window1.display();

            
            break;
        default:
            break;
        }
}


void Game::dispBackground(){
    _background.drawBackground(Window1);
    Mode = Game::GameMode::Playing;
}




Game::GameMode Game::Mode = Game::GameMode::Uninitialized;
sf::RenderWindow Game::Window1;