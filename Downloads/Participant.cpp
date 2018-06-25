#include <iostream>
using namespace std;
#include "Participant.h"

char *Participant::copystring(const char *str){
  int len;
  char * newstr;
  for(len = 0; str[len] != '\0'; len++){}
  newstr = new char[len+1];
  for(int a = 0; a < len+1; a++){
    newstr[a] = str[a];
  }
  return newstr;
}

Participant::Participant(const char* n){
  name = copystring(n);
}

Participant::Participant(const char* n, const char* dest){
  name = copystring(n);
  destination = copystring(dest);
}

Participant::Participant(const char*n, const char* dest, float dist){
  name = copystring(n);
  destination = copystring(dest);
  distance = dist;
}

Participant::Participant(){
  name = copystring("");
  destination = copystring("");
  distance = 0;
}

Participant::~Participant(){
  delete [] name;
  delete [] destination;
}

void Participant::set_name(const char* n){
  delete [] name;
  name = copystring(n);
}

void Participant::set_destination(const char* dest){
  delete [] destination;
  destination = copystring(dest);
}

void Participant::set_distance(float dist){
  distance = dist;
}

char* Participant::get_name(){
  return name;
}

char* Participant::get_destination(){
  return destination;
}

float Participant::get_distance(){
  return distance;
}

void Participant::display(){
    cout << name << " " << destination << " " << distance << " ";
}

float Participant::get_gasmoney(float gc,int pa,float mpg){
  return (((distance/mpg)/pa)*gc);
}
