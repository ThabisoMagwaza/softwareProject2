#include "ScreenData.h"

//The default values of screen data
ScreenData::ScreenData(){
    //default directories
     string SplashDirectory(" ");
     string GameOverDirectory(" ");
     string BackGroundDirectory(" ");
     
     //default text
     vector <string> GOtext{" "};
     vector <string> SplashText{""};
     auto GOptr = make_shared <vector<string>>(GOtext);
     auto Sptr = make_shared <vector<string>>(SplashText);
      
     //default positions
     vector <Position> GOpos {Position(0,0),Position(0,0)};
     vector <Position>SplashPos{Position(0,0),Position(0,0),Position(0,0),Position(0,0),Position(0,0)};
     auto Gops_ptr= make_shared <vector<Position>> (GOpos);
     auto SplashPosition_ptr= make_shared <vector<Position>> (SplashPos);
}