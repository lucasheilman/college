#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge{
  int begin;
  int end;
  edge(int b, int e){
    begin = b;
    end = e;
  }
};

bool notvisited(edge check, vector <edge> visited){
  for(int i = 0; i < visited.size(); i++){
    if(check.begin == visited[i].begin && check.end == visited[i].end){
      return false;
    }
  }
  return true;
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
   
  vector <edge> edges;
  for(int i = 0; i < edge_count; i++){
    cin >> junk;
    cin >> first_vert;
    cin >> second_vert;
      
    edges.push_back(edge(first_vert, second_vert));
  }
  vector <int> subverts;
  int n = vertice_count;
  int nSub = 1<<n; 
  int minverts;
  vector <int> minsubverts;
  vector <edge> visited;
  for(int i=0; i<nSub; i++){
    subverts.clear();
    for(int k=0; k<n; k++){
      if( (1<<k) & i){
	subverts.push_back(k);
      } 
    }
    if(subverts.size() > 0){
      cout << "Subvert: [";
      for(int x = 0; x < subverts.size()-1; x++){
	cout << subverts[x] << ',';
      }
      cout << subverts[subverts.size()-1] << ']' << endl;
    }
    else{
      cout << "Subvert: []" << endl;
    }
    for(int j = 0; j < subverts.size(); j++){
      for(int a = 0; a < edges.size(); a++){
	if((subverts[j] == edges[a].begin || subverts[j] == edges[a].end) && notvisited(edges[a],visited)){
	  cout << "Adding edge: Begin: " << edges[a].begin << " End: " << edges[a].end << endl;
	  visited.push_back(edges[a]);
	}
      }
    }
    if(visited.size() == edges.size()){
      if(subverts.size() < minverts){
	minverts = subverts.size();
	minsubverts = subverts;
      }
    }
    visited.clear();
  }
  cout << "Minumum number of vertices: " << minverts << endl;
  cout << "Vertices chosen: [";
  for(int i = 0; i < minsubverts.size()-1; i++){
    cout << minsubverts[i] << ',';
  }
  cout << minsubverts[minsubverts.size()-1] << ']' << endl;
        
  return 0;
}



