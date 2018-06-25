#include <iostream>
using namespace std;
#include "DVDArrayP.h"

int DVDArrayP::DEFAULT_SIZE = 3;

DVDArrayP::DVDArrayP(int sz){
  size = sz;
  elt = new DVD*[size];
  for(int i = 0; i<size;i++){
    elt[i]=0;
  }
}

DVDArrayP::DVDArrayP(){
  size = DEFAULT_SIZE;
  elt = new DVD*[size];
  for(int i = 0; i<size;i++){
    elt[i]=0;
  }
}

DVDArrayP::DVDArrayP(const DVDArrayP &d){
  size = d.size;
  elt = new DVD*[size];
  for(int i = 0; i < size; i++){
    if (d.elt[i] == 0){
      elt[i] = 0;
    }
    else{
      elt[i] = new DVD;
      *elt[i] = *d.elt[i];
    }
  }
}

DVDArrayP::~DVDArrayP(){
  for(int i =0;i<size;i++){
    delete elt[i];
  }
  delete[] elt;
}

int DVDArrayP::getSize(){
  return size;
}

void DVDArrayP::display(){
  for(int i = 0;i<size;i++){
    if ((elt[i])!=0){
      cout << i<< ":  " << '[' << elt[i]->id << ". " << elt[i]->getTitle() << '/' << elt[i]->getDirector() << ']' << endl;
    }
  }
}

DVDArrayP& DVDArrayP::operator= (const DVDArrayP &arr){
  for(int i =0;i<size;i++){
    delete elt[i];
  }
  delete[] elt;
  size = arr.size;
  elt = new DVD*[size];
  for(int i = 0;i<size;i++){
    if(elt[i] == 0){
      elt[i] = 0;
    }
    else{
      elt[i] = new DVD;
      *elt[i] = *arr.elt[i];
    }
  }
  return *this;
}

DVD &DVDArrayP::operator[](int i){
  if(i<0){
    cout << "The value inputed was too low" << endl;
    return *elt[0];
  }
  else if(i>(size-1)){
    cout << "The value inputed was too high" << endl;
    return *elt[size-1];
  }
  if(elt[i] == 0){
    elt[i] = new DVD;
    return *elt[i];
  }
  else{
    return *elt[i];
  }
}
