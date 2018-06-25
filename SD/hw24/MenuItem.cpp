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

int MenuItem::get_val(){
  return val;
}

char * MenuItem::get_label(){
  return label;
}

void MenuItem::set_val(int new_val){
  val = new_val;
}

void MenuItem::set_label(const char *new_label){
  label = makeString(new_label);
}

void MenuItem::display(ostream &ostr) const{
  ostr << '[' << val <<"] " << label;
}

char *MenuItem::makeString(const char *str){
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
