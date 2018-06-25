#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

int main() {
  int in;
  int max = 0;
  vector <int> vec;
  while(cin >> in){
    vec.push_back(in);
  }
  vector <int> out(vec.size(),1);
  for(int i = 1; i < vec.size(); i++){
    for(int j = 0; j < i; j++){
      if(vec[i] > vec[j] && out[i] < out[j] + 1){
	out[i] = out[j] + 1;
      }
    }
  }
  for(int i = 0; i < vec.size(); i++){
    if(max < out[i]){
      max = out[i];
    }
  }
  cout << "Length of longest subsequence: " << max << endl;
  return 0;
}
