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
    Screen(const string& _directory, shared_ptr <vector<string>> _text, shared_ptr <vector<Position>> _position);
    //void setText(const string& text, vector <string> _text); 
    //void setDirectory(const string& directory);
    string getDirectory() const;
    shared_ptr <vector <string>> getText() const;
    shared_ptr <vector<Position>> getPosition()const;
  private:  
    shared_ptr <vector <string>>text;
    string directory;
    shared_ptr<Position> position;
};