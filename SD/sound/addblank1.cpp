#include<iostream>
using namespace std;

int datalen = 3453884;

void quieter(signed short val[])
{

  for( int i = 44000; i < datalen; ++i ){
    val[i+44000] =val[i];
  }
  for (int i = 0; i < 44000; ++i){
    val[i] = 1;
  }
}

int main()
{
  signed short val[datalen+44000];  // make an array to hold the data
  cin.read( (char *)val, 2*datalen); // read the data into the array

  quieter(val);  // modify the array elements

  cout.write( (char *)val, 2*(datalen+44000) ); // write the data back out
  return 0;
}
