#include<iostream>
using namespace std;

int main()
{
  signed short val;
   do{
    val *= 2;
    cout << val << " ";
   }while ( cin >> val );
  cout << endl;
  return 0;
}
