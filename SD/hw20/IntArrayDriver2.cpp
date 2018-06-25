#include<iostream>
using namespace std;
#include"IntArray.h"
 
int main()
{
  IntArray arr1, arr2(3);
  cout << "arr1 has size " << arr1.getSize() << endl;
  arr2.display(); cout << endl;
 
  arr2[1] = 24;
  arr2.display(); cout << endl;
  arr2[389]; // should display an error, but not crash
 
  IntArray arr3(arr2);
  arr3.display();
  arr1 = arr3;
  arr1.display();
  arr2[2] = 63;
  (arr1 = arr2)[0] = -99;
  arr1.display();
}
