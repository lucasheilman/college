#include <iostream>
using namespace std;
#include "StarTrekDVD.h"
#include "DVD.h"

StarTrekDVD::StarTrekDVD(int i, const char *t, const char *dir,int n,const char *cap): DVD::DVD(i,t,dir){

  episode = n;
  captain = makecopy(cap);
}

StarTrekDVD::StarTrekDVD(): DVD::DVD(){
  episode = -1;
  captain = makecopy("");
}

StarTrekDVD::StarTrekDVD(const StarTrekDVD &d): DVD::DVD(d){
  episode = d.episode;
  captain = makecopy(d.captain);
}

StarTrekDVD::~StarTrekDVD(){
  delete [] captain;
}

int StarTrekDVD::getEpisode(){
  return episode;
}

char * StarTrekDVD::getCaptain(){
  return captain;
}

void StarTrekDVD::setEpisode(int i){
  episode = i;
}

void StarTrekDVD::setCaptain(const char *t){
  captain = makecopy(t);
}

void StarTrekDVD::display(){
  cout << '[' << id << ". ST" << episode << ": " << title << '/' << director << '/' << captain << ']';
}

char *StarTrekDVD::makecopy(const char *str){
  int len;
  char * newstr;
  for(len = 0; str[len] != '\0'; len++){}
  newstr = new char[len+1];
  for(int a = 0; a < len+1; a++){
    newstr[a] = str[a];
  }
  return newstr;
}

StarTrekDVD& StarTrekDVD::operator= (const StarTrekDVD &dvd){
  DVD::operator=(dvd);
  episode = dvd.episode;
  captain = makecopy(dvd.captain);
  return *this;
}
