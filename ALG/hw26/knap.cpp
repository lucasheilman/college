#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> items;

int knapsack(vector <int> v, vector <int> w, int n, int W){
  int dimension = n+1;
  vector<vector<int> > table(dimension, vector<int>(W+1));
  vector<vector<int> > keep(dimension, vector<int>(W+1));
  int x;
  for(x = 0; x <= W; ++x)
    table[0][x] = 0;
  for(int i = 1; i <= n; ++i){
    for(x = 0; x <= W; ++x){
      if((w[i-1] <= x) && (v[i-1] + table[i-1][x-w[i-1]] > table[i-1][x])){
	table[i][x] = v[i-1] + table[i-1][x-w[i-1]];
	keep[i][x] = 1;
      }
      else{
	table[i][x] = table[i-1][x];
	keep[i][x] = 0;
      }
    }
  }
  int K = W;
  for (int j = n; j > 0; j--){
    if(keep[j][K] == 1){
      cout << items[j-1] << " is in knapsack" << endl;
      K = K - w[j-1];
    }
  }
  return table[n][W];
}

int main(){
  vector <int> v = {8,10,11,2,3};
  vector <int> w = {12,8,7,2,3};
  items.push_back("sock");
  items.push_back("pencil");
  items.push_back("pen");
  items.push_back("desk");
  items.push_back("chair");
  int n = v.size();
  int W = 20;
  cout << "Best Value: " << knapsack(v,w,n,W) << endl;
  return 0;
}
