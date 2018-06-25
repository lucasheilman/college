#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector <int> vec;
  for(int x = 0; x < 20; x++){
    vec.push_back(x);
  }
  int n = vec.size();
  int nSub = 1<<n; 
  vector <int> subverts;
  for(int i=0; i<nSub; i++){
    subverts.clear();
    for(int k=0; k<n; k++){
      if( (1<<k) & i){
	subverts.push_back(vec[k]);
      } 
    }
    if(subverts.size() == 1){
      cout << '[';
      for(int j = 0; j < subverts.size()-1; j++){
	cout << subverts[j] << ',';
      }
      cout << subverts[subverts.size()-1] << ']' << endl;
    }
    if(subverts.size() == 0){
      cout << "[]" << endl;
    }
  }
}
