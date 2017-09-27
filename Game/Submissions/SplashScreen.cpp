#include "SplashScreen.h"
void SplashScreen::show(sf::RenderWindow& window){
        sf::FileInputStream stream;
        stream.open("resources/im1.jpg");
        sf::Texture texture;
        texture.loadFromStream(stream);
        sf::Sprite sprite;
        sprite.setTexture(texture);    
        
        sf::Font font;
        font.loadFromFile("resources/mbhele.ttf");
        sf::Text text;
        sf::Text text1;
        sf::Text text2;
        sf::Text text3;
        sf::Text text4;
        text.setFont(font);
        text.setString("Game controls: right arrow - rotate rnticlockwise");
        text.setPosition(0,100);
        
        text2.setFont(font);
        text2.setString(" left arrow- rotate clockwise");
        text2.setPosition(277,130);
        
        text3.setFont(font);
        text3.setString(" X - shoot enemy");
        text3.setPosition(277,170);
        
        text1.setFont(font);
        text1.setString("Click mouse to play game");
        text1.setPosition(0,400);
        
        text4.setFont(font);
        text4.setString(" Space Assault");
        text4.setPosition(300,0);
        
        
        text4.setColor(sf::Color::Black);
        text4.setStyle(sf::Text::Italic);
        window.draw(sprite);
        window.draw(text2);
        window.draw(text1);
        window.draw(text);
        window.draw(text3);
        window.draw(text4);
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