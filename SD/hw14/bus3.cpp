#include <iostream>
using namespace std;

struct Bus{
  long int phonenumber;
  const char *name;
  const char *location;
  float rating;
  int initial(long int pn, const char *nm,
	      const char *lc, float rt){
    phonenumber = pn;
    name = nm;
    location = lc;
    rating = rt;
  }
  int getinfo(){
    cout << "phonenumber = " << phonenumber << " name = " << name
	 << " location = " << location << " rating = " << rating
	 << endl;
  }
};

int main(){
  Bus school;
  school.initial(5555555555,"shialabeou","forest",10);
  school.getinfo();
  Bus greyhound;
  greyhound.initial(1111111111, "franchesca","france",0);
  greyhound.getinfo();
}
