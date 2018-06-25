#include<iostream>
using namespace std;
#include "DVDArray.h"
 
int main()
{
  char str[] = "Gandhi";
  DVD d1(4, str, "Richard Attenborough");
  DVD d2;
  DVD d3(d1);
  DVDArray ar1(3);
  ar1[-8] = d1;
  ar1[1] = d2;
  ar1[8] = d3;
  DVDArray ar2;
  ar2[0] = d1;
  ar2[1] = d2;
  ar2[2] = d3;
  DVDArray ar3(ar1);
  cout << "After constructors:" << endl;
  ar1.display();
  ar2.display(); 
  ar3.display();
 
  cout << ar2.getSize() << endl; // 3
 
  ar3 = ar2;

  ar3.display();
}
