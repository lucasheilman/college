#include <iostream>
using namespace std;

int main(){
  short a;
  int b;
  double c;
  short *d;
  int *e;
  double *f;
  cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c) << " "
       << sizeof(d) << " " << sizeof (e) << " " << sizeof (f) << endl;
}
