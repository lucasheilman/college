#include <iostream>
using namespace std;
#include <math.h>
 
int main(){
  int x, count =0;
  int avg;
  cin >> avg;
  int sum = 0;
  while (cin >> x) {
    sum = sum + pow((x-avg),2);
    count +=1;
  }
  float avg2;
  avg2 = sum/count;
  float stddev;
  stddev = sqrt(avg2);
  cout << stddev << endl;
}
