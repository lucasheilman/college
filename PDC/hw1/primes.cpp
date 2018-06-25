#include <iostream>
using namespace std;

int main(){
  int n = 1000000;
  int num[n];
  for(int i = 2; i <= n; i++){
    num[i] = 1;
  }
  num[0] = 0;
  num[1] = 0;
  for(int p = 2; p<=n; p++){
    if(num[p] == 1){
      for(int i = 2; p*i <= n; i++){
	num[p*i] = 0;
      }
    }
  }
  int count = 0;
  for(int m = 0; m <=n; m++){
    if(num[m] == 1){
      count++;
    }
  }
  cout << count << endl;
}
