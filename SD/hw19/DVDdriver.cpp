#include<iostream>
using namespace std;
#include"DVD.h"
 
int main()
{
  char str[] = "Gandhi";
  DVD d1(4, str, "Richard Attenborough");
  DVD d2;
  DVD d3(d1);
  cout << "After constructors:" << endl;
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  
  str[0] = 'X';
 
  cout << "Test for dynamically allocated copies" << endl;
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  cout << d2.getId() << endl; // 0
  cout << d1.getTitle() << endl; // Gandhi
  cout << d1.getDirector() << endl; // Richard Attenborough
 
  d1.setId(2);
  d1.setTitle("Shadowlands");
  d2.setDirector("Ingmar Bergman");
 
  cout << "After state changes:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /Ingmar Bergman]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  d3 = d2;
  d2.setTitle("Wild Strawberries");
 
  cout << "After more state changes:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  Wild Strawberries/Ingmar Bergman]
  d3.display(); cout << endl; // [0.  /Ingmar Bergman]

  cout << "Test of increment operators:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  cout << ++d1 << endl; // 3
  d1.display(); cout << endl; // [3.  Shadowlands/Richard Attenborough]
  
  cout << d1++ << endl; // 3
  d1.display(); cout << endl; // [4.  Shadowlands/Richard Attenborough]
  
}
