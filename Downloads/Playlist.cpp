#include <iostream>
using namespace std;
#include "Playlist.h"

int Playlist::DEFAULT_SIZE = 1000;

Playlist::Playlist(){
  count = 0;
  name = makeString("");
  author = makeString("");
  playlist = new Song[DEFAULT_SIZE];
}

Playlist::Playlist(const char*n,const char *a){
  count = 0;
  name = makeString(n);
  author = makeString(a);
  playlist = new Song[DEFAULT_SIZE];
}

void Playlist::set_name(const char*n){
  delete[] name;
  name = makeString(n);
}

char *Playlist::get_name(){
  return name;
}

void Playlist::set_author(const char *a){
  delete [] author;
  author = makeString(a);
}

char *Playlist::get_author(){
  return author;
}

void Playlist::set_count(int c){
  count = c;
}

int Playlist::get_count(){
  return count; 
}

void Playlist::add_Song(const Song &s){
  playlist[count] = s;
  count++;
}  

Playlist::~Playlist(){
  delete [] name;
  delete [] author;
  delete [] playlist;
}

char *Playlist::makeString(const char *str){
  int len;
  char * newstr;
  for(len = 0; str[len] != '\0'; len++){}
  newstr = new char[len+1];
  for(int a = 0; a < len+1; a++){
    newstr[a] = str[a];
  }
  return newstr;
}

void Playlist::add_song(const Song &p){
  playlist[count] = p;
  count++;
} 

void Playlist::display_song(){
  for (int i=0;i<count;i++){
    cout << i+1 << " " ;
    playlist[i].display();
    cout << endl;
  }
} 

void Playlist::display(){
  cout << name << " " << author << " : " << endl;
  for (int i=0;i<count;i++){
    playlist[i].display();
  }
}

