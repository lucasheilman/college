/* Example program for CS 251
   R. Brown, rev 1/15 */

#include <iostream>
using namespace std;

#include "Dog.h"


/* main program */

int main() {
  Dog mydog("Fido", 3);

  cout << "Hello, world!" << endl;
  cout << "My dog is named " << mydog.get_name()
       <<", and it is " << mydog.get_age() << " years old." << endl;
  return 0; /* indicates successful run of the program */
}
