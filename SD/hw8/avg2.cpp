#include <iostream>
using namespace std;

/** Compute mean and minimum of an array
    @param dat Array of values
    @param nelts Non-negative number of elements in dat
    @param minVal Assigned minimum value in dat by this function
    @return Mean (average) of values in dat */
double averageOf(float dat[], int nelts, float &minVal)
{
  double result = 0;
  minVal = dat[0];
  for(int i = 0; i < nelts; ++i) {
    if ( dat[i] < minVal ) minVal = dat[i];
    result += dat[i];
  }
  result /= nelts;
  return result;
}

int main()
{
  float minimum;
  float mydata[225];
  int x, y=0;
  while (cin >>  x){
    mydata[y] = x;
    y++;
  }
  double avg;

  avg = averageOf(mydata, 225, minimum);

  cout << "avg " << avg << " minimum value " << minimum << endl;
}
