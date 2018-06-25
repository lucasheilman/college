#include <iostream>
using namespace std;
#include "Mvector.h"
#include "Poly.h"

int main(){
  Mvector mv(5);
  cout << mv.get_len() << endl;
  Mvector mv2;
  mv2 = mv;
  cout << mv2.get_len() << endl;
  mv.dump();
  mv2.dump();
  mv[1] = 1;
  mv[2] = 2;
  mv[3] = 3;
  mv[4] = 4;
  mv[0] = 5;
  mv2[0] = 4;
  mv2[1] = 2;
  mv2[2] = 9;
  mv2[3] = 7;
  mv2[4] = 1;
  mv.dump();
  mv2.dump();
  Mvector mv3;
  mv3 = mv*2;
  mv3.dump();
  Mvector mv4;
  mv4 = mv*mv2;
  mv4.dump();
  Mvector mv5;
  mv5 = mv3+mv2;
  mv5.dump();
  Poly pl;
  pl[0] = 4;
  pl[1] = 2;
  pl[2] = 9;
  pl[3] = 7;
  pl[4] = 1;
  cout << pl(3)<< endl;
  
}
