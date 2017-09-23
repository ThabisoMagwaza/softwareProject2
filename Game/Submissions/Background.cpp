#include "Background.h"
#include <iostream>


Background::Background(){
        sf::FileInputStream input;
        input.open("resources/im.jpg");
        _texture.loadFromStream(input);
        _sprite.setTexture(_texture);    
  
    //sf::Event localEvent;
//    while(true){
//        while(window1.pollEvent(localEvent)){
//        if(localEvent.type == sf::Event::EventType::KeyPressed || localEvent.type == sf::Event::EventType::MouseButtonPressed || localEvent.type == sf::Event::EventType::Closed)
//            return;   
//    
//        }        
//    }
}

void Background::drawBackground(sf::RenderWindow& window1){
    window1.draw(_sprite);
}