#include <iostream>
using namespace std;

struct Bus{
  long int phonenumber;
  const char *name;
  const char *location;
  float rating;
};

int main(){
  Bus school;
  school.phonenumber = 5555555555;
  school.name = new char[12];
  school.name = "shialabeouf";
  school.location = new char[7];
  school.location = "forest";
  school.rating = 10;
  Bus greyhound;
  greyhound.phonenumber = 1111111111;
  greyhound.name = new char[4];
  greyhound.name = "bag";
  greyhound.location = new char[5];
  greyhound.location = "road";
  greyhound.rating = 0;
}
