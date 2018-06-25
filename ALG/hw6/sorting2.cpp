#include <iostream>
using namespace std;
#include <stdlib.h>
#include "elapsed_time.h"

int main() {
  int array_size;
  cin >> array_size;
  int *array = new int[array_size];
  for (int i = 0; i < array_size; i++)
    array[i] = rand()%1000;

  int isChanged = 1;
  start_timer();
  while (isChanged != 0) {
    isChanged = 0;
    int first = 0;
    int second = 1;
    for(int i = 0; i < array_size-1; ++i) {
      if(array[first] > array[second]) {
	int holder = array[first];
	array[first] = array[second];
	array[second] = holder;
	first++; second++;
	isChanged++;
      } 
      else {
	first++; second++;
      }
    }
  }
  double cycles = elapsed_time();
  for (int m = 0; m < array_size; m++)
    cout << array[m] << " ";

  cout << endl << "Total cycles: " << cycles << endl;
  delete [] array;
  
  return 0;
}
