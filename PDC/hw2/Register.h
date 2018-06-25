#include <queue>
#include <iostream>
#include <stdlib.h>
using namespace std;
#ifndef _REGISTER_H_
#define _REGISTER_H_

class Register : private std::queue<int> {
 protected:
  int remaining;
  static const int transactTime = 10;
 public:
  void advanceTime(int t);
  void push(const int val);
};

void Register::advanceTime(int t){
  while((t>0) && !(empty())){
    if(remaining > t){
      remaining = remaining - t;
      t = 0;
      cout << "Made progress on " << front() << " item cart; ";
    }
    else{
      t = t-remaining;
      cout << "Completed " << front() << " item cart; ";
      pop();
      if(!(empty())){
	remaining = transactTime + front();
      }
    }
  }
  if(empty()){
    cout << "No carts remain";
  }
}

void Register::push(const int val){
  if(empty()){
    remaining = 0;
  }
  queue::push(val);
}

#endif
