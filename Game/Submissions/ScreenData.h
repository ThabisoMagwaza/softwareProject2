#pragma once

#include "Position.h"
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

struct ScreenData{
     ScreenData();
    //Directories 
     string SplashDirectory("resources/im1.jpg");
     string GameOverDirectory("resources/im.jpg");
     string BackGroundDirectory("resources/im3.jpg");
     
     //Texts
     vector <string> GOtext{"Game Over","Press any key for Menu"};
     vector <string> SplashText{"Space Assault", "Game Controls: Right Arrow-Rotate Anticlockwise","Left Arrow-Rotate Clockwise", "X-Shoot enemy","Click Mouse to play Game"};
     auto GOptr = make_shared <vector<string>>(GOtext);
     auto Sptr = make_shared <vector<string>>(SplashText);
      
     //TextPosition
     vector <Position> GOpos {Position(0,100),Position(300,300)};
     vector <Position>SplashPos{Position(300,0),Position(0,100),Position(277,130),Position(277,170),Position(0,400)};
     auto Gops_ptr= make_shared <vector<Position>> (GOpos);
     auto SplashPosition_ptr= make_shared <vector<Position>> (SplashPos);
    
};