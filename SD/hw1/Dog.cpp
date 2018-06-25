/* Example implementation module for CS 251
   R. Brown, rev 2/15 */

#include <cstring>
#include <iostream>
using namespace std;

/** Dog Class
    @param a state variable representing the name (as a C-style string) of an object of type Dog (i.e., an object in the Dog class)
    @param a state variable representing the age in years of an object of type Dog
    get_name() a method that returns the name of an object of type Dog
    get_age() a method that returns the age of a object of type Dog
    set_name() a method that assigns a new name to an object of type Dog
    birthday() a method that adds 1 to the age of an object of type Dog
*/
#include "Dog.h"

/* helper -- create a newly allocated copy of a string */
char * Dog::helper(const char *str) {
  char *copy = new char[strlen(str) + 1];
  strcpy(copy, str);
  return copy;
}

/* destructor */
Dog::~Dog() {
  //cout << "~Dog() called" << endl;
  if (name != 0)
    delete [] name;
  name = 0;
}

/* assignment operator */
Dog &Dog::operator=(const Dog &dog) {
  delete [] name;
  name = helper(dog.name);
  age = dog.age;
  return *this;
}

/* display -- print this instance of Dog, formatted as  name (age)    */
void Dog::set_name(const char *new_name) {
  delete [] name;
  name = helper(new_name);
}
