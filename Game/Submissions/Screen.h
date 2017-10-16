#pragma once

#include <string>
#include <vector>
#include <memory>
#include "ScreenData.h"
#include "Position.h"

using std::string;
using std::vector;
using std::shared_ptr;

class Screen{
  public:  
    Screen(const string& _directory, vector<string> _text = vector<string>{}, vector<Position> _position = vector<Position>{});
    //void setText(const string& text, vector <string> _text); 
    //void setDirectory(const string& directory);
    string getDirectory() const;
    vector <string> getText() ;
    vector<Position> getPosition();
  private:  
    vector <string> text;
    string directory;
    vector<Position> position;
};