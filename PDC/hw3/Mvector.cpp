#include <iostream>
using namespace std;
#include "Mvector.h"
#include <cassert>

int Mvector::default_len = 10;

Mvector::Mvector(){
  len = default_len;
  arr = new float[len];
  for(int i = 0; i<len;i++){
    arr[i] = 0;
  }
}

Mvector::Mvector(int length){
  len = length;
  arr = new float[len];
  for(int i = 0; i<len;i++){
    arr[i] = 0;
  }
}

int Mvector::get_len(){
  return len;
}

Mvector::~Mvector(){
  delete [] arr;
}

Mvector& Mvector::operator= (const Mvector &mvec){
  len = mvec.len;
  for(int a = 0; a < len+1; a++){
    arr[a] = mvec.arr[a];
  }
  return *this;
}

float& Mvector::operator[] (int index){
  assert(index >= 0 && index < len);
    return arr[index];
}

Mvector Mvector::operator* (float val){
  Mvector mv(len);
  for(int i = 0; i<len; i++){
    mv.arr[i] = arr[i] * val;
  }
  return mv;
}

Mvector Mvector::operator* (const Mvector &vec){
  assert(len == vec.len);
  Mvector mv(len);
  for(int i = 0; i<len; i++){
    mv[i] = arr[i]*vec.arr[i];
  }
  return mv;
}

Mvector Mvector::operator+ (const Mvector &vec){
  assert(len == vec.len);
  Mvector mv(len);
  for(int i = 0; i<len; i++){
    mv[i] = arr[i]+vec.arr[i];
  }
  return mv;
}

void Mvector::dump(){
  for(int i = 0; i<len;i++){
    cout << arr[i] << " ";
  }
  cout<< endl;
}
