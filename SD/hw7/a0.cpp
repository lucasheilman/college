#include <iostream>
using namespace std;

void printarray (int arg[], int length) {
 for (int n=0; n<length; n++)
 cout << arg[n] << " ";
 cout << "\n";
}

int main(){
  int arr[20];
  printarray(arr,20);
}
