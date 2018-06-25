#include <iostream>
using namespace std;
int main(){
  int arr[9] = {9,8,7,6,5,4,3,2,1};
  int arraySize = 9;
  int temp;
  for(int y = 0; y < arraySize; y++){
    for(int z = arraySize-1; z > y; z--){
      if(arr[z] < arr[y]){
	//swap them
	temp = arr[z];
	arr[z] = arr[y];
	arr[y] = temp;
      }
    }
  }
  for(int i = 0;i<arraySize;i++){
    cout << arr[i] <<  endl;
  }
}
