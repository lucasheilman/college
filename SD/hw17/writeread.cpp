#include<fstream>
#include<iostream>
using namespace std;

int main()
{
  ifstream g("in.txt");
  ofstream f("writereadout.txt");
  int i, j;
  g >> i >> j;
  g.close();

  for(int a = 0; a < i; a++){
    f  << "hello" << endl;
  }
  for(int b = 0; b<j;b++){
    f << "world" << endl;
  }
}
