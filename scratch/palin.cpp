#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool palin(string str){
  size_t count;
  vector <int> vec;
  int div = 0;
  for(int i = 0; i < str.length(); i++){
    count = std::count(str.begin(),str.end(),str[i]);
    vec.push_back(count);
  }
  for(int i = 0; i < vec.size(); i++){
    if(vec[i]%2 == 1){
      div = div + 1;
    }
  }
  if(div > 1){
    return false;
  }
  else{
    return true;
  }
}

int main(){
  string str1 = "banana";
  cout << palin(str1) << endl;
  str1 = "tacocat";
  cout << palin(str1) << endl;
  str1 = "ok";
  cout << palin(str1) << endl;
  str1 = "";
  cout << palin(str1) << endl;
  str1 = "aannaa";
  cout << palin(str1) << endl;
}
