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
  cout << x << " " << (y/2) << endl;
  cout << range << endl;
  int count = 0;
  for ( int i  = 0; i < 3*x*y; i++ ){
    if (i%(3*x) == 0){
      i = i+(3*x);
    }
    else {
      cout << (int)data[(i-50)] << " ";
    }  
  }
  cout << endl;
  delete [] data;
}
