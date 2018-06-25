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
  for ( int i  = 0; i < 3*x*y; ++i ){
    if ((i+2)%3 ==0){
      cout << 2*((int)data[i]) << " ";
    }
    else{
      cout << (int)data[i] << " ";
    }
  }
  cout << endl;
  delete [] data;
}
