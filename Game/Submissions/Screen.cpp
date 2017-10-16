#include "Screen.h"

Screen::Screen(const string & _directory, shared_ptr<vector<string>> _text, shared_ptr <vector<Position>> _position): directory(_directory), text(_text), position(_position){}

string Screen::getDirectory()const{
    return directory;
}

shared_ptr <vector<string>> Screen::getText()const{
    return text;
}

shared_ptr <vector<Position>> Screen::getPosition()const{
    return position;
}