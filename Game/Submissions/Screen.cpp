#include "Screen.h"

Screen::Screen(const string & _directory, vector<string> _text, vector<Position> _position){
	directory = _directory;
	text = _text;
	position = _position;
}	

string Screen::getDirectory()const{
    return directory;
}

vector<string> Screen::getText(){
    return text;
}

vector<Position> Screen::getPosition(){
    return position;
}