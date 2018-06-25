#include<iostream>
using namespace std;

int datalen = 3453884/4;

void quieter(signed short val[], signed short val2[])
{

  for( int i = 100; i < datalen; ++i ){
    val[i+100] = val[i];
  }
  for (int i = 0; i < 100; ++i){
    val[i] = 0;
  }
  for (int i = 0; i < datalen; ++i){
    val[i] = val[i]+val2[i];
  }
}

int main()
{
  signed short val[datalen+100];  // make an array to hold the data
  signed short val2[datalen+100];

  cin.read( (char *)val, 2*datalen); // read the data into the array
  for (int i = 0; i < (datalen+100); i++){ 
      val2[i] = val[i];
  }

  quieter(val,val2);  // modify the array elements

  cout.write( (char *)val, 2*(datalen+100) ); // write the data back out
  return 0;
}
