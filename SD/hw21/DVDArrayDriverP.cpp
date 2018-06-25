#include<iostream>
using namespace std;
#include"DVDArrayP.h"
 
int main()
{
  DVDArrayP arr1, arr2(5);
  cout << "arr1 has size " << arr1.getSize() << endl;
  arr2.display();cout << endl;
  DVD d1(1, "Gandhi", "Richard Attenborough");
  arr2[1] = d1;
  arr2.display(); cout << endl;
  arr2[389]; // should display an error, but not crash.
    //  in this case, arr2[389] default-constructs element arr2[4]
  arr2.display(); cout << endl;
 
  DVDArrayP arr3(arr2);
  arr3.display();
  arr1 = arr3;
  arr1.display();
  DVD d2(8, "The Fellowship of the Ring", "Peter Jackson");
  arr2[2] = d2;
  (arr1 = arr2)[0] = d2;
  arr1.display();
}
