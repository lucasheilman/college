#include <iostream>
using namespace std;

#include "elapsed_time.h"

int main(){
  bool sortd = false;
  int arr[] = {6,5,7,2,8,1,435,657,32,756,22,0,434,7,323,65};
  start_timer();
  while(sortd == false){
    for(int i = 1; i<sizeof(arr)/4;i++){
      if(arr[i] < arr[i-1]){
	int a = arr[i];
	int b = arr[i-1];
	arr[i] = b;
	arr[i-1] = a;
      }
    }
    bool valgood = true;
    for(int i = 1; i<sizeof(arr)/4;i++){
      for(int x = i - 1; x >= 0; x--){
	if(arr[i] < arr[x]){
	  valgood = false;
	}
      }
    }
    sortd = valgood;
  }
  double cycles = elapsed_time();
  for(int i = 0;i < sizeof(arr)/4;i++){
    cout << arr[i] << endl;
  }
  cout << "Total cycles: " << cycles << endl;
}
