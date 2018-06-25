#include <iostream>
using namespace std;
#include "Song.h"

char *Song::copystring(const char *str){
  int len;
  char * newstr;
  for(len = 0; str[len] != '\0'; len++){}
  newstr = new char[len+1];
  for(int a = 0; a < len+1; a++){
    newstr[a] = str[a];
  }
  return newstr;
}

Song::Song(const char*t, const char*art, const char *alb){
  title = copystring(t);
  artist = copystring(art);
  album = copystring(alb);
}

Song::Song(){
  title = copystring("");
  artist = copystring("");
  album = copystring("");
}

Song::~Song(){
  delete [] artist;
  delete [] title;
  delete [] album;
}

void Song::set_title(const char* t){
  delete [] title;
  title = copystring(t);
}

void Song::set_artist(const char* art){
  delete [] artist;
  artist = copystring(art);
}

void Song::set_album(const char* alb){
  delete [] album;
  album = copystring(alb);
}

char* Song::get_title(){
  return title;
}

char* Song::get_album(){
  return album;
}

char* Song::get_artist(){
  return artist;
}

void Song::display(){
  cout << title << "/" << artist << "/" << album << endl;
}
