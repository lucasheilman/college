#include<iostream>
using namespace std;

const int datalen = 3453884;

void quieter(signed short val[])
{
  for( int i = 0; i < datalen; ++i )
    val[i] *= 2;
}

int main()
{
  signed short val[datalen];  // make an array to hold the data
  cin.read( (char *)val, 2*datalen ); // read the data into the array

  quieter(val);  // modify the array elements

  cout.write( (char *)val, 2*datalen ); // write the data back out
  return 0;
}
