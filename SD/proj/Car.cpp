#include <iostream>
using namespace std;
#include "Car.h"

int Car::DEFAULT_SIZE = 100;

Car::Car(){
  count = 0;
  name = makeString("");
  mpg =0;
  passengers = new Participant[DEFAULT_SIZE];
}

Car::Car(const char *n){
  count = 0;
  name = makeString(n);
  mpg = 0;
  passengers = new Participant[DEFAULT_SIZE];
}

Car::Car(const char*n,float m){
  count = 0;
  name = makeString(n);
  mpg = m;
  passengers = new Participant[DEFAULT_SIZE];
}

void Car::set_name(const char*n){
  delete[] name;
  name = makeString(n);
}

char *Car::get_name(){
  return name;
}

void Car::set_mpg(float m){
  mpg = m;
}

float Car::get_mpg(){
  return mpg;
}

int Car::get_count(){
  return count;
}

void Car::set_count(int c){
  count = c;
}

void Car::add_participant(const Participant &p){
  passengers[count] = p;
  count++;
} 

void Car::display_participant(){
  for (int i=0;i<count;i++){
    cout << i+1 << " " ;
    passengers[i].display();
    cout << endl;
  }
} 

void Car::display(){
  cout << name << " " << endl;
  Car::display_participant();
}



Car::~Car(){
  delete [] name;
  delete [] passengers;
}

char *Car::makeString(const char *str){
  int len;
  char * newstr;
  for(len = 0; str[len] != '\0'; len++){}
  newstr = new char[len+1];
  for(int a = 0; a < len+1; a++){
    newstr[a] = str[a];
  }
  return newstr;
}

