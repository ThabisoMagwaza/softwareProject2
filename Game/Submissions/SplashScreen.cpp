#include "SplashScreen.h"
void SplashScreen::show(sf::RenderWindow& window){
        sf::FileInputStream stream;
        stream.open("resources/im22.jpg");
        sf::Texture texture;
        texture.loadFromStream(stream);
        sf::Sprite sprite;
        sprite.setTexture(texture);    
        
        sf::Font font;
        font.loadFromFile("resources/stoz.ttf");
        sf::Text text;
        sf::Text text1;
        text.setFont(font);
        text.setString("Game controls: right arrow - rotate right, left arrow - rotate left");
        text.setPosition(0,100);
        
        text1.setFont(font);
        text1.setString("Click mouse to continue");
        text1.setPosition(0,400);
        
        //text.setColor(sf::Color::Black);
        text.setStyle(sf::Text::Italic);
        window.draw(sprite);
        window.draw(text1);
        window.draw(text);
        window.display();
    
    sf::Event Event1;
    while(true){
        while(window.pollEvent(Event1)){
        if(Event1.type == sf::Event::EventType::MouseButtonPressed)
            return;   
        else if(Event1.type == sf::Event::EventType::Closed)
            window.close();
        }        
    }
}