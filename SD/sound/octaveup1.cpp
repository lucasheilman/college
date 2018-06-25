#include<iostream>
using namespace std;

const int datalen = 3453884/4;


void octaveup(signed short val[], signed int bigval[])
{
  for( int i = 0; i < datalen; i=i+4 ){
    bigval[i/2]=val[i];
    bigval[i/2+1]=val[i+1];
  }
}

int main()
{
  int bigdata[datalen/2];
  signed short val[datalen];  // make an array to hold the data
  cin.read( (char *)val, 2*datalen ); // read the data into the array

  octaveup(val,bigdata);  // modify the array elements

  cout.write( (char *)bigdata, datalen ); // write the data back out
  return 0;
}
