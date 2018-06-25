#include <iostream>
using namespace std;
#include "MenuItem.h"

MenuItem::MenuItem(int init_val, const char *init_label){
  val = init_val;
  label = makeString(init_label);
}

MenuItem::MenuItem(){
  val = 0;
  label = makeString("");
}

MenuItem::MenuItem(const MenuItem &mi){
  val = mi.val;
  label = makeString(mi.label);
}

MenuItem::~MenuItem(){
  delete [] label;
}

int MenuItem::getId(){
  return id;
}

char * MenuItem::getTitle(){
  return title;
}

char * MenuItem::getDirector(){
  return director;
}

void MenuItem::setId(int i){
  id = i;
}

void MenuItem::setTitle(const char *t){
  title = makecopy(t);
}

void MenuItem::setDirector(const char *dir){
  director = makecopy(dir);
}

void MenuItem::display(){
  cout << '[' << id << ". " << title << '/' << director << ']';
}

char *MenuItem::makecopy(const char *str){
  int len;
  char * newstr;
  for(len = 0; str[len] != '\0'; len++){}
  newstr = new char[len+1];
  for(int a = 0; a < len+1; a++){
    newstr[a] = str[a];
  }
  return newstr;
}

MenuItem& MenuItem::operator= (const MenuItem &mi){
  val = mi.val;
  label = makeString(mi.label);
  return *this;
}
