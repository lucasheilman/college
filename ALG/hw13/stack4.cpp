#include <iostream>
#include "elapsed_time.h"
using namespace std;

template <class T>
class Stack{
protected:
  T pointer = 0;
  T size;
public:
  T *a;
  
  Stack(){
    size = 1;
    a = new T[size];
  }
  void push(T i){
    if(pointer > size-1){
      T temp[size];
      for(int x = 0; x < pointer; x++){
	temp[x] = a[x];
      }
      a = new T[size+100];
      for(int y = 0; y < size;y++){
	a[y] = temp[y];
      }
      size = size + 100;
      //cout << "Increased size" << endl;
    }
    a[pointer] = i;
    //cout << i << " is now in spot " << pointer << " and the size of the array is: " << size << endl;
    pointer = pointer+1;
  }
  void pop(){
    if(pointer != 0){
      cout << "Removed value " << a[pointer-1] << " from spot " << pointer << endl;
      a[pointer-1] = 0;
      pointer = pointer - 1;
    }
    else{
      cout << "No value to pop" << endl;
    }
  }
  void print(){
    if(pointer >=1){
      cout << '[';
      for(int i = 0; i < pointer-1; i++){
	cout << a[i] << ',';
      }
      cout << a[pointer-1] << ']' << endl;
    }
    else{
      cout << "Empty" << endl;
    }
  }
  bool empty(){
    return (pointer == 0);
  }
  ~Stack(){
    delete [] a;
  }
};

int main(){
  Stack<int> st;
  start_timer();
  for(int i = 0; i < 1000000; i++){
    st.push(3);
  }
  double cycles = elapsed_time();
  cout << "Cycles per push : " << cycles << endl;
}
  
