#include <iostream>
using namespace std;
#include "DVDArray.h"

int DVDArray::DEFAULT_SIZE = 3;

DVDArray::DVDArray(int sz){
  size = sz;
  elt = new DVD[size];
}

DVDArray::DVDArray(){
  size = DEFAULT_SIZE;
  elt = new DVD[size];
}

DVDArray::DVDArray(const DVDArray &d){
  size = d.size;
  elt = new DVD[size];
  for(int i = 0; i < size; i++){
    elt[i] = d.elt[i];
  }
}

DVDArray::~DVDArray(){
  delete [] elt;
}

int DVDArray::getSize(){
  return size;
}

void DVDArray::display(){
  for(int i = 0;i<size;i++){
    cout << i << ":  " << '[' << elt[i].id << ". " << elt[i].title << '/' << elt[i].director << ']' << endl;
  }
}

DVDArray& DVDArray::operator= (const DVDArray &arr){
  size = arr.size;
  elt = new DVD[size];
  for(int i = 0;i<size;i++){
    elt[i] = arr.elt[i];
  }
  return *this;
}

DVD &DVDArray::operator[](int i){
  if(i<0){
    cout << "The value inputed was too low" << endl;
    return elt[0];
  }
  else if(i>(size-1)){
    cout << "The value inputed was too high" << endl;
    return elt[size-1];
  }
  else{
    return elt[i];
  }
}
