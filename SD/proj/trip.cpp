#include"trip.h"
#include<iostream>
using namespace std;

Trip::Trip(){}

Trip::Trip(const char *t){
  int len = 0;
  for(int i = 0; t[i]!='\0'; i++){
    len++;
  }

  title = new char[len+1];
  for(int i = 0; i<=len; i++){
    title[i] = t[i];
  }
}

Trip::Trip(const char *t, const char *a, float g){
  int tlen = 0;
  int alen = 0;

  for(int i = 0; t[i]!='\0'; i++){
    tlen++;
  }

  title= new char[tlen+1];
  for(int i = 0; i<=tlen; i++){
    title[i] = t[i];
  }

  for(int i = 0; a[i]!='\0'; i++){
    alen++;
  }

  author= new char[alen+1];
  for(int i = 0; i<=alen; i++){
    author[i] = a[i];
  }
  gas = g;
}

Trip::~Trip(){
  delete[] title;
  delete[] author;
}

void Trip:: set_trip(const char *t){
  delete [] title;
  int len = 0;
  for(int i = 0; t[i]!='\0'; i++){
    len++;
  }

  title= new char[len+1];
  for(int i = 0; i<=len; i++){
    title[i] = t[i];
  }
}

char * Trip::get_trip(){
  return title;
}

float Trip::get_gas(){
  return gas;
}

void Trip::set_gas(float g){
  gas = g;
}

void Trip::set_author(const char *a){
  delete [] author;
  int alen = 0;
  for(int i = 0; a[i]!='\0'; i++){
    alen++;
  }

  author= new char[alen+1];
  for(int i = 0; i<=alen; i++){
    author[i] = a[i];
  }
}

char * Trip::get_author(){
  return author;
}

void Trip::print(){
  cout << "The trip you are on is "<<title<<endl;
  cout << "This trip is under the name  of "<<author<<endl;
}

  
