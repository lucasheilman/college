#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

int issame(vector <vector <int>> fin_t, string firstword, string secondword, int i, int j){
  if(firstword[j-1] == secondword[i-1]){
    return fin_t[i-1][j-1] + 1;
  }
  else {
    return max(fin_t[i-1][j], fin_t[i][j-1]);
  }
}

vector <vector <int>> minimum (vector <vector <int>> fin_t, string firstword, string secondword ){
  for(int i = 0; i < fin_t[0].size(); i++) {
    fin_t[0][i] = 0;
  }
  for (int j = 1; j < fin_t.size(); j++) {
    fin_t[j][0] = 0;
  }
  for (int i = 1; i < fin_t.size(); i++) {
    for (int j = 1; j < fin_t[0].size(); j++) {
      fin_t[i][j] = issame(fin_t, firstword, secondword, i, j);
    }
  }
  return fin_t;
}

int main() {

  cout << "Enter the first word: ";
  string firstword;
  cin >> firstword;
  cout << "Enter the second word: ";
  string secondword;
  cin >> secondword;

  vector <vector <int>> fin_t(secondword.size()+1, vector<int> (firstword.size()+1, secondword.size()+1));
  vector <vector <int>> bin_t = minimum(fin_t,firstword, secondword);
  int length = bin_t[secondword.size()][firstword.size()];
  int currentval = length;
  int row = bin_t.size() - 1;
  int col = bin_t[0].size() - 1;
  string build;
  for(int i = 0; i < length; i++){
   
    while(bin_t[row][col] == bin_t[row-1][col]){
      row = row-1;
 
    }
    while(bin_t[row][col] == bin_t[row][col-1]){
      col = col-1;
   
    }
    build.insert(build.begin(),firstword[col-1]);
    row = row - 1;
    col--;
  }
  cout << "Longest subsequence is: " << build << endl;  
  return 0;
}




