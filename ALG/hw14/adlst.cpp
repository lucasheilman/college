#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
  vector <vector <int> > adlst;
  adlst.resize(vertice_count);
  for(int i = 0; i < vertice_count-1; i++){
    cin >> junk;
    cin >> first_vert;
    cin >> second_vert;
    adlst[first_vert].push_back(second_vert);
    adlst[second_vert].push_back(first_vert); 
  }
  cout << "p edge\t" << vertice_count << "\t" << edge_count << endl;
  for(int i = 0; i < adlst.size(); i++){
    for(int j = 0; j < adlst[i].size();j++){
      if(i < adlst[i][j]){
	cout << "e" <<"\t" <<  i << "\t" << adlst[i][j] << endl;
      }
    }
  }
}
      
