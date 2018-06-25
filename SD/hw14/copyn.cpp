#include <iostream>
using namespace std;

int copyn(char *&pchar, const char *char1, int x){
  pchar = new char[x];
  for (int i = 0; i<x; i++){
    pchar[i] = char1[i];
  }
}

int main(){
  char *buff;
  copyn(buff, "St. Olaf", 5);
  cout << buff << endl;
}
