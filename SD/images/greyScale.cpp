#include<iostream>
using namespace std;

int main()
{ 
  string s;
  cin >> s; 
  int x, y, range; 
  cin >> x >> y >> range;
  cin.get();
  unsigned char *data = new unsigned char[3*x*y];
  cin.read((char *)data, 3*x*y);
  
  cout << "P3" << endl; 
  cout << x << " " << y << endl;
  cout << range << endl;
  for ( int i  = 0; i < 3*x*y; i = i+3 ){
    int avg = ((int)data[i] + (int)data[(i+1)] + (int)data[(i+2)])/3;
    cout << avg << " " << avg << " " << avg <<" ";
  }
  cout << endl;
  delete [] data;
}
