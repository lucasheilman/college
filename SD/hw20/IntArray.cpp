#include <iostream>
using namespace std;
#include "IntArray.h"

int IntArray::DEFAULT_SIZE = 3;

IntArray::IntArray(int sz){
  size = sz;
  elt = new int[size];
}

IntArray::IntArray(){
  size = DEFAULT_SIZE;
  elt = new int[size];
}

IntArray::IntArray(const IntArray &d){
  size = d.size;
  elt = new int[size];
  for(int i = 0; i < size; i++){
    elt[i] = d.elt[i];
  }
}

IntArray::~IntArray(){
  delete [] elt;
}

int IntArray::getSize(){
  return size;
}

void IntArray::display(){
  for(int i = 0;i<size;i++){
    cout << i << ":  " << elt[i] << endl;
  }
}

IntArray& IntArray::operator= (const IntArray &arr){
  size = arr.size;
  elt = new int[size];
  for(int i = 0;i<size;i++){
    elt[i] = arr.elt[i];
  }
  return *this;
}

int &IntArray::operator[](int i){
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
