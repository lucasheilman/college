#include <iostream>
using namespace std;

int main(){
  int i;
  int *p;
  int **pp;
  i = 5;
  p = &i;
  pp = &p;
  cout << "i = " << i << ", *p = " << *p << ", **pp = " << **pp << endl; 
}
