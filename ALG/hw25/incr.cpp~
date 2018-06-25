#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

int lis2(vector <int> vec, int n){
  if(n == 0){
    return 1;
  }
  int current = 1;
  for(int i = 0; i < n; i++){
    int sub = lis2(vec, i);
    if(vec[i] < vec[n] && current < (1+sub)){
      current = 1+sub;
    }
    else if(current < sub){
      current = sub;
    }
  }
  return current;
}

int lis(vector <int> vec, int n){
  int x = lis2(vec,n);
  return x;
}

int main() {
  int in;
  vector <int> vec;
  while(cin >> in){
    vec.push_back(in);
  }
  cout << "Length of longest subsequence: " << lis(vec,vec.size()) << endl;
  return 0;
}
