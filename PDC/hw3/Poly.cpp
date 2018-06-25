#include <iostream>
using namespace std;
#include <cmath>
#include "Poly.h"

float Poly::operator() (float x){
  float total = 0;
  for(int i = 0; i<len; i++){
    total = total + arr[i]*pow(x,i);
  }
  return total;
}

