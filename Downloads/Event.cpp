#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Event.h"

char *Event::copystring(const char *str){
  int len;
  char * newstr;
  for(len = 0; str[len] != '\0'; len++){}
  newstr = new char[len+1];
  for(int a = 0; a < len+1; a++){
    newstr[a] = str[a];
  }
  return newstr;
}

void Event::findtimestamp(const char *t){
  char dayarray[2];
  dayarray[0] = t[3];
  dayarray[1] = t[4];
  int day = atoi(dayarray);
  char montharray[2];
  montharray[0] = t[0];
  montharray[1] = t[1];
  int month = atoi(montharray);
  char yeararray[2];
  yeararray[0] = t[6];
  yeararray[1] = t[7];
  int year = atoi(yeararray);
  char hourarray[2];
  hourarray[0] = t[9];
  hourarray[1] = t[10];
  int hour = atoi(hourarray);
  if(t[14] == 'p'){
    hour = hour+12;
  }
  if(t[14] == 'a'){
    if(hour == 12){
      hour = 0;
    }
  }
  char minutearray[2];
  minutearray[0] = t[12];
  minutearray[1] = t[13];
  int minute = atoi(minutearray);
  year = year*100000000;
  month = month*1000000;
  day = day*10000;
  hour = hour*100;
  timestamp =  year+month+day+hour+minute;
}


Event::Event(const char*t, const char*ti, const char *pla,const char*n){
  title = copystring(t);
  time = copystring(ti);
  place = copystring(pla);
  note = copystring(n);
}

Event::Event(){
  title = copystring("");
  time = copystring("");
  place = copystring("");
  note = copystring("");
  timestamp = 0;
}

Event::~Event(){
  delete [] place;
  delete [] title;
  delete [] time;
  //delete [] note;
}

void Event::set_title(const char* t){
  delete [] title;
  title = copystring(t);
}

void Event::set_place(const char* pla){
  delete [] place;
  place = copystring(pla);
}

void Event::set_time(const char* ti){
  delete [] time;
  time = copystring(ti);
}

void Event::set_note(const char* n){
  delete [] note;
  note  = copystring(n);
}

char* Event::get_title(){
  return title;
}

char* Event::get_place(){
  return place;
}

char* Event::get_time(){
  return time;
}

char* Event::get_note(){
  return note;
}

void Event::display(){
  cout << title << "/" << time << "/" << place << "/" << note << endl << endl;
}

long Event::get_timestamp(){
  return timestamp;
}

Event::Event(const Event &e){
  title = copystring(e.title);
  time = copystring(e.time);
  place = copystring(e.place);
  note = copystring(e.note);
  timestamp = e.timestamp;
}

Event& Event::operator= (const Event &e){
  title = copystring(e.title);
  time = copystring(e.time);
  place = copystring(e.place);
  note = copystring(e.note);
  timestamp = e.timestamp;
  return *this;
}
