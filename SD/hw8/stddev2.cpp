#include <iostream>
using namespace std;
#include <math.h>

/** Compute stddev and minimum of an array
    @param dat Array of values
    @param nelts Non-negative number of elements in dat
    @param minVal Assigned minimum value in dat by this function
    @return stddev of values in dat */
double stddev(float dat[], int nelts, float &minVal, float avg)
{
  double result = 0;
  minVal = dat[0];
  for(int i = 0; i < nelts; ++i) {
    if ( dat[i] < minVal ) minVal = dat[i];
    result += pow((dat[i]-avg),2);
  }
  result /= nelts;
  return result;
}

int main()
{
  float minimum;
  float mydata[224];
  int x, y=0;
  float avg;
  cin >> avg;
  while (cin >>  x){
    mydata[y] = x;
    y++;
  }
  double dev;

  dev = stddev(mydata, 224, minimum, avg);

  cout << "dev " << dev << " minimum value " << minimum << endl;
}
