#include<iostream>
using namespace std;

const int datalen = 3453884/4;

void octavedown(signed short val[], signed short bigval[])
{
  int j=0;
  for( int i = 0; i < datalen; i+=2 ){
    bigval[j]=val[i];
    bigval[j+1]=val[i+1];
    bigval[j+2]=val[i];
    bigval[j+3]=val[i+1];
    j=j+4;
  }
}

int main()
{
  signed short bigval[datalen*2];
  signed short val[datalen];  // make an array to hold the data
  cin.read( (char *)val, 2*datalen ); // read the data into the array

  octavedown(val,bigval);  // modify the array elements

  cout.write( (char *)bigval, 4*datalen ); // write the data back out
  return 0;
}
