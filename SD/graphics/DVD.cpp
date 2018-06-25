#include <iostream>
using namespace std;
#include "DVD.h"

DVD::DVD(int i, const char *t, const char *dir){
  id = i;
  title = makecopy(t);
  director = makecopy(dir);
}

DVD::DVD(){
  id = 0;
  title = makecopy("");
  director = makecopy("");
}

DVD::DVD(const DVD &d){
  id = d.id;
  title = makecopy(d.title);
  director = makecopy(d.director);
}

DVD::~DVD(){
  delete [] title;
  delete [] director;
}

int DVD::getId(){
  return id;
}

char * DVD::getTitle(){
  return title;
}

char * DVD::getDirector(){
  return director;
}

void DVD::setId(int i){
  id = i;
}

void DVD::setTitle(const char *t){
  title = makecopy(t);
}

void DVD::setDirector(const char *dir){
  director = makecopy(dir);
}

void DVD::display(){
  cout << '[' << id << ". " << title << '/' << director << ']';
}

char *DVD::makecopy(const char *str){
  int len;
  char * newstr;
  for(len = 0; str[len] != '\0'; len++){}
  newstr = new char[len+1];
  for(int a = 0; a < len+1; a++){
    newstr[a] = str[a];
  }
  return newstr;
}

DVD& DVD::operator= (const DVD &dvd){
  id = dvd.id;
  title = makecopy(dvd.title);
  director = makecopy(dvd.director);
  return *this;
}
