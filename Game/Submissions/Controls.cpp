#include "Controls.h"

char Controls::checkPress(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        return 'r';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        return 'l';
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
		return 'x';
	}
    else{
        return '~';
    }
}