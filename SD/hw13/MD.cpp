#include<iostream>
using namespace std;

/** An item of baggage */
struct Suitcase {
  int id; /**< An identifying number for this Suitcase */
  char *contents; /**< Characters contained in this suitcase */
};

/** Selected information about a plane */
struct Airplane {
  int equipment;  /**< Model number of this airplane */
  Suitcase *luggage; /**< Array of Suitcases on this airplane */
};

/** Pack a copy of string c into the Suitcase s using id number i */
void packSuitcase(Suitcase &s, int i, const char *c)
{
  s.id = i;
  int len;
  for ( len = 0; c[len] != '\0'; ++len ) { }
  s.contents = new char[len+1];
  for ( int i = 0; i < len+1; ++i ) s.contents[i] = c[i];
}

/** Load suitcases packed with substrings of d onto Airplane a, having model eq */ 
void boardAirplane(Airplane &a, int eq, const char *d)
{
  a.equipment = eq;
  a.luggage = new Suitcase[3];
  packSuitcase(a.luggage[0], 1, d+2);
  packSuitcase(a.luggage[1], 2, d+1);
  packSuitcase(a.luggage[2], 3, d+0);
}

int main()
{
  Airplane whale1;

  boardAirplane(whale1, 747, "stripe");

  cout << "second luggage piece contains: "
       << whale1.luggage[1].contents << endl;
  return 0;
}
