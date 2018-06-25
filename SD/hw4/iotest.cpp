#include <iostream>
#include <string>
using namespace std;

int main()
{
  string name;
  float shoesize;
  float favnum;
  cout << "Enter your name: ";
  getline (cin, name);
  cout << "Enter your shoesize: ";
  cin >> shoesize;
  cout << "Enter your favorite number: ";
  cin >> favnum;
  float avg = (shoesize + favnum)/2;
  cout << "The average of your shoesize and your favorite number is: " << avg << endl;
  return 0;
}
  
