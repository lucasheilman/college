#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){
  vector<int> vec;
  int randy = rand() % 100;
  for(int i = 0; i < randy; i++){
    vec.push_back(0);
    cout << "position " << i << " has value 0"<< endl;
  }
}
