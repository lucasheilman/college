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
  cout << x << " " << (y+20) << endl;
  cout << range << endl;
  for (int a = 0; a < 4000; ++a){
    cout << 0 << " " << 0 << " " << 0 << " ";
  }
  for ( int i  = 0; i < 3*x*y; ++i ){
    cout << (int)data[i] << " ";
  }
  cout << endl;
  delete [] data;
}
