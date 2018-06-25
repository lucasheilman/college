/* A program to correctly write vertex cover w/
 * branch and bound */

//First read in graph to adList, then make possible vertex covers of size
//1/2 Edge count or smaller.

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


struct edge{
  int a;
  int b;
  edge(int s, int t){
    a = s;
    b = t;
  }
};


bool coverCheck(vector<int> coverSet, vector <edge> edges){
  bool check = true;
  int iter;
  for(int ej = 0; ej < edges.size(); ++ej){
    iter = 0;
    for(int select = 0; select < coverSet.size(); ++select){
      if(coverSet[select] != edges[ej].a && coverSet[select] != edges[ej].b){
	++iter;
      }
    }
    if(iter == coverSet.size()){
      check = false;
      //cout << "False edges: " << edges[ej].a << " " << edges[ej].b << endl;
    }

  }

  //cout <<endl;
  //cout << "All edges covered: ";
  //if(check == true) cout << "True";
  //else cout << "False";
  //cout <<endl << endl;
  return check;
}

vector< vector <int> >  makeAdList(vector <edge> edges, int verts){
  //init adlist
  vector< vector <int> > adList;
  for(int init = 0; init < verts; init++){
    vector <int> columns;
    adList.push_back(columns);
  }
  //make adjacency list
  for(int y = 0; y < edges.size(); y++){
    bool check1 = true;
    bool check2 = true;
    int checker;
    for(checker = 0; checker < adList[edges[y].a].size(); ++checker){
      if(adList[edges[y].a][checker] == edges[y].b){
	check1 = false;
      }
    }
    for(checker = 0; checker < adList[edges[y].b].size(); ++checker){
      if(adList[edges[y].b][checker] == edges[y].a){
	check2 = false;
      }
    }
    if(check1) adList[edges[y].a].push_back(edges[y].b);
    if(check2) adList[edges[y].b].push_back(edges[y].a);
  }

  // Cout adjacency list
  cout << "Adjacency list: " << endl;
  for(int checkrow = 0; checkrow < adList.size(); checkrow++){
    cout << checkrow << ": ";
    for(int checkcolumn = 0; checkcolumn < adList[checkrow].size(); checkcolumn++){
      cout << adList[checkrow][checkcolumn] << " ";
    }
    cout << endl;
  }
  cout << endl;
  return adList;
}


void dispAd(vector< vector <int> > adList){
  cout << "Adjacency list: " << endl;
  for(int checkrow = 0; checkrow < adList.size(); checkrow++){
    cout << checkrow << ": ";
    for(int checkcolumn = 0; checkcolumn < adList[checkrow].size(); checkcolumn++){
      cout << adList[checkrow][checkcolumn] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool notInChosen(vector<int> selected, int bestNbr){
  bool check = true;
  for(int i = 0; i < selected.size(); ++i){
    if(bestNbr == selected[i]){
      check = false;
    }
  }
  return check;
}


vector <int> cover(int edge_count, vector <edge> edges, int nedge, vector <int> current, vector <int> &chosen){
  while( ! coverCheck(current, edges) && current.size() < edge_count/2){
    if(notInChosen(current, edges[nedge].a) && notInChosen(current, edges[nedge].b)){
      current.push_back(edges[nedge].a);
      cover(edge_count, edges, nedge + 1, current, chosen);
      current.pop_back();
      current.push_back(edges[nedge].b);
      cover(edge_count, edges, nedge + 1, current, chosen);
    }
    nedge++;
  }

  if(coverCheck(current, edges) && ((current.size() < chosen.size()) || chosen.size() == 0)){
    chosen = current;
  }
  return chosen;
}


int main(){
  ifstream f("test3.txt");
  string junk;
  f >> junk;
  f >> junk;
  int vertice_count;
  f >> vertice_count;
  int edge_count;
  f >> edge_count;
  int first_vert;
  int second_vert;
  vector <edge> edges;
  for(int i = 0; i < edge_count; i++){
    f >> junk; //Only use for files using e for edge
    f >> first_vert;
    f >> second_vert;
    edge newEdge = edge(first_vert, second_vert);
    edges.push_back(newEdge);
  }
  cout << "The edges are: " << endl;
  for(int x = 0; x < edges.size(); x++){
    cout << edges[x].a << " " << edges[x].b << endl;
  }
  cout << endl;

  vector< vector <int> >  adList;
  adList = makeAdList(edges, vertice_count);
  vector <bool> visited(vertice_count, false);
  vector <int> coverSet;
  vector <int> current;
  coverSet = cover(edge_count, edges, 0, current, coverSet);

  cout << "The cover set: " << endl;
  for(int set = 0; set < coverSet.size(); ++set){
    cout << coverSet[set] << " ";
  }
  cout << endl;
  return 0;
}
