#include <iostream>
using namespace std;
#include "Calendar.h"

int Calendar::DEFAULT_SIZE = 1000;

void Calendar::organize(){
  for(int y = 0; y < count; y++){
    for(int z = count-1; z > y; z--){
      if((calendar[z]).get_timestamp() < (calendar[y]).get_timestamp()){
        Event temp(calendar[z]);
	calendar[z] = calendar[y];
	calendar[y] = temp;
      }
    }
  }
}
Calendar::Calendar(const char*n,const char *a){
  count = 0;
  name = makeString(n);
  author = makeString(a);
  calendar = new Event[DEFAULT_SIZE];
}

Calendar::Calendar(){
  count = 0;
  name = makeString("");
  author = makeString("");
  calendar = new Event[DEFAULT_SIZE];
}

void Calendar::set_name(const char*n){
  delete[] name;
  name = makeString(n);
}

char *Calendar::get_name(){
  return name;
}

void Calendar::set_author(const char *a){
  delete [] author;
  author = makeString(a);
}

char *Calendar::get_author(){
  return author;
}

void Calendar::set_count(int c){
  count = c;
}

int Calendar::get_count(){
  return count; 
}

void Calendar::add_Event(const Event &e){
  calendar[count] = e;
  count++;
}  

Calendar::~Calendar(){
  delete [] name;
  delete [] author;
  delete [] calendar;
  }

char *Calendar::makeString(const char *str){
  int len;
  char * newstr;
  for(len = 0; str[len] != '\0'; len++){}
  newstr = new char[len+1];
  for(int a = 0; a < len+1; a++){
    newstr[a] = str[a];
  }
  return newstr;
}

void Calendar::display(){
  cout << name << " "<< author << endl;
}

void Calendar::display_event(){
  for (int i=0;i<count;i++){
    cout << i+1 << " " ;
    calendar[i].display();
    cout << endl;
  }
} 
