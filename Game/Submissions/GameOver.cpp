#include "GameOver.h"
void GameOver::display(sf::RenderWindow& window){
        sf::FileInputStream stream;
        stream.open("resources/im3.jpg");
        sf::Texture texture;
        texture.loadFromStream(stream);
        sf::Sprite sprite;
        sprite.setTexture(texture);    
        
        sf::Font font;
        font.loadFromFile("resources/mbhele.ttf");
        sf::Text text;
        sf::Text text1;
        
        text.setFont(font);
        text.setString("Game Over");
        text.setPosition(0,100);
        text1.setFont(font);
        text1.setString("Press any key for Menu");
        text1.setPosition(300,300);
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