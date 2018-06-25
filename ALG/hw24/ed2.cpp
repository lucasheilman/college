#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

int diff(string firstword, string secondword, int i, int j){
  if(firstword[j-1] == secondword[i-1]){
    return 0;
  }
  else {
    return 1;
  }
}

vector <vector <int>> minimum (vector <vector <int>> fin_t, string firstword, string secondword ){
  for(int i = 0; i < fin_t[0].size(); i++) {
    fin_t[0][i] = i;
  }
  for (int j = 1; j < fin_t.size(); j++) {
    fin_t[j][0] = j;
  }
  for (int i = 1; i < fin_t.size(); i++) {
    for (int j = 1; j < fin_t[0].size(); j++) {
      fin_t[i][j] = min(min((fin_t[i-1][j]+1)*2,(fin_t[i][j-1]+1)*2), diff(firstword, secondword, i, j)+fin_t[i-1][j-1]);
    }
  }
  return fin_t;
}

int main() {
  string firstword;
  cout << "Enter the first word: ";
  cin >> firstword;
  cout << "Enter the second word: ";
  string secondword;
  cin >> secondword;
  vector <vector <int>> fin_t(secondword.size()+1, vector<int> (firstword.size()+1, secondword.size()+1));
  vector <vector <int>> bin_t = minimum(fin_t,firstword, secondword);
  cout << "Edit distance: " << bin_t[secondword.size()][firstword.size()] << endl;
  return 0;
}



