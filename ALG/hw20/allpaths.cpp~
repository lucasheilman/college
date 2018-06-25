#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string recur(vector <vector <int>> vect, string visited, int currentval){
  int count = 0;
  int gotval = 0;
  int count1 = 0;
  visited.append(to_string(currentval));
  visited.push_back(',');
  for(int i = 0; i < vect[currentval].size();i++){
    size_t found1 = visited.find(to_string(vect[currentval][i]));
    if(found1 != string::npos){
      count = count+1;
    }
  }
  char startingval = visited[0];
  int startingvalint = startingval - '0';
  if(((count == vect[currentval].size())&& (currentval == startingvalint))){
    size_t countofstart = std::count(visited.begin(), visited.end(), startingval);
    if(countofstart > vect[startingvalint].size()){
      visited.pop_back();
      visited.pop_back();
    }
    gotval = 1;
    return visited;
  }
  else if((count == vect[currentval].size()) && (currentval != startingvalint)){
    int subtract = 4;
    char prevval = visited[visited.size() - subtract];
    int prevvalint = prevval - '0';
    size_t found1 = visited.find(to_string(prevvalint));
    size_t found3 = string::npos;
    if(visited.size() >=4){
      string first;
      first.push_back(startingval);
      first.push_back(',');
      first.push_back((visited[2]));
      found3 = visited.find(first);
    }
    while((found1 != string::npos) && ((visited.size()-subtract) >= 2)){
      subtract = subtract + 2;
      prevval = visited[visited.size() - subtract];
      prevvalint = prevval - '0';
      found1 = visited.find(to_string(prevvalint));
    }
    gotval = 1;
    return recur(vect,visited,prevvalint);
  }
  else{
    while((count1 < vect[currentval].size()) && (gotval == 0)){
      size_t found = visited.find(to_string(vect[currentval][count1]));
      if ((found == string::npos) && (find(vect[currentval].begin(),vect[currentval].end(),vect[currentval][count1])!=vect[currentval].end())){
	gotval = 1;
	return recur(vect,visited,vect[currentval][count1]);
      }
      count1 = count1 + 1;
    }
  }
}

bool myfunction (int i,int j) {
  return (i<j);
}   
    
int main(){
  string junk;
  cin >> junk;
  cin >> junk;
  int vertice_count;
  cin >> vertice_count;
  int edge_count;
  cin >> edge_count;
  int first_vert;
  int second_vert;
  vector <vector <int>> adlst;
  adlst.resize(vertice_count);
  for(int i = 0; i < edge_count; i++){
    cin >> junk;
    cin >> first_vert;
    cin >> second_vert;
    adlst[first_vert].push_back(second_vert);
    adlst[second_vert].push_back(first_vert);
  }
  for(int i = 0; i < adlst.size(); i++){
    sort(adlst[i].begin(), adlst[i].end(), myfunction);
  }
  int start;
  cin >> start;
  string visited ("");
  string visited2 = recur(adlst, visited, start);
  cout << "Path taken: ";
  for(int i = 0; i < visited2.size()-2;i = i + 2){
    cout << visited2[i] << " --> ";
  }
  cout << visited2[visited2.size()-2] << endl;
}
      
