#include<iostream>
using namespace std;

int main()
{
  int x = 0;
  signed short val1, val2;
  while ( cin >> val1 >> val2 ) {
    ++x;
    if (x%2 ==0){
      cout << val1 << " " << val2 << " ";
    }
  }
  cout << endl;
  return 0;
}
