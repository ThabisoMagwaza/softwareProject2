#pragma once

#include "Position.h"
#include <string>
#include <vector>
#include <memory>

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

struct ScreenData{
     string SplashDirectory = "resources/im1.jpg";
     string GameOverDirectory ="resources/im3.jpg" ;
     string BackGroundDirectory ="resources/im.jpg";
     
     //Texts
     vector <string> GOtext{"Game Over","Press any key for Menu"};
	 vector <string> SplashText{"Space Assault", "Game Controls: Right Arrow-Rotate Anticlockwise","Left Arrow-Rotate Clockwise", "X-Shoot enemy","Click Mouse to play Game"};
      
     //TextPosition
     vector <Position> GOpos{Position(0,100),Position(300,300)};
     vector <Position> SplashPos{Position(300,0),Position(0,100),Position(277,130),Position(277,170),Position(0,400)};
    
};