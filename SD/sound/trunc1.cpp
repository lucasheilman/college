#include<iostream>
using namespace std;

int datalen = 3453884;

void trunc(signed short val[])
{
  for( int i = 44000; i < datalen; ++i )
    val[i-44000] =val[i];
}

int main()
{
  signed short val[datalen];  // make an array to hold the data
  cin.read( (char *)val, 2*datalen); // read the data into the array

  trunc(val);  // modify the array elements

  cout.write( (char *)val, 2*(datalen-44000) ); // write the data back out
  return 0;
}
