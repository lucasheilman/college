#include<iostream>
using namespace std;
#include"DVD.h"
#include "StarTrekDVD.h"
 
int main()
{
  char str[] = "Gandhi";
  StarTrekDVD d1(4, str, "Richard Attenborough", 4, "William Shatner");
  StarTrekDVD d2;
  StarTrekDVD d3(d1);
  cout << "After constructors:" << endl;
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  cout << d2.getEpisode() << endl; // 0
  cout << d1.getCaptain() << endl; // Gandhi
 
  d1.setEpisode(2);
  d1.setCaptain("george");
 
  cout << "After state changes:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /Ingmar Bergman]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  d3 = d2;
  d2.setCaptain("Wild Strawberries");
 
  cout << "After more state changes:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  Wild Strawberries/Ingmar Bergman]
  d3.display(); cout << endl; // [0.  /Ingmar Bergman]
  
}
