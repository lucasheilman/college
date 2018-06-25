#include <iostream>
using namespace std;
#include "Image.h"

int main(){
  Image arg1("newfile.ppm");
  arg1.horizSqueeze();
  arg1.print();
  return 0;
}
