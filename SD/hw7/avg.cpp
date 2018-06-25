#include<iostream>
using namespace std;
 
int main(){
  float x, count = 0.0 , sum = 0.0;
  while ( cin >> x ) {
    sum = sum + x;
    count += 1;
  }
  float avg;
  avg = sum/count;
  cout << avg << endl;
}
