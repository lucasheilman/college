#include <iostream>
#include <vector>

using namespace std;

struct edge{
  int begin;
  int end;
  int len;
  bool taken = false;
  edge(int b, int e, int l){
    begin = b;
    end = e;
    len = l;
  }
};

bool allvisited(vector <bool> visited){
  bool allvisited = true;
  for(int i = 0; i < visited.size(); i++){
    if(visited[i] == false){
      return false;
    }
  }
  return true;
}


bool dijkstra(vector <edge> edges, int start, vector <bool> visited, vector <int> distance){
  vector <edge> queue;   // all the edges to check for their distances
  int startstart = start;
  visited[start] = true; 
  distance[start] = 0;
  
  bool allvisit = allvisited(visited);
  while(allvisit == false){
    queue.clear();
    //cout << "here" << endl;
    for(int i = 0; i < edges.size(); i++){
      if(edges[i].begin == start){       
	queue.push_back(edges[i]);
      }    
    }
    for(int i = 0; i < queue.size(); i++){
      if(((queue[i].len + distance[queue[i].begin]) < distance[queue[i].end]) ||distance[queue[i].end] == -1){
	distance[queue[i].end] = queue[i].len + distance[queue[i].begin];
	cout << "changed " << queue[i].end << " to " << distance[queue[i].end] <<endl;
      }
    }
    for(int i = 0; i < distance.size(); i++){
      cout << "cd: " << i << " " << distance[i] << endl;
    }
    visited[start] = true;
    int smallest = -1;
    int next;
    for(int i = 0; i < distance.size(); i++){
      if(smallest == -1 && visited[i] == false){
	smallest = distance[i];
	next = i;
      }
      if((distance[i] < smallest) && (visited[i] == false) && (distance[i] != -1)){
	next = i;
	smallest = distance[i];
      }
    }
    start = next;
    cout << "start is now " << start << endl;
    visited[start] = true;       
    allvisit = allvisited(visited);
    //start = next;
  }
  for(int i = 0; i < distance.size(); i++){
    cout << "Shortest distance from " << startstart << " to " << i << " is " << distance[i] << endl;
  }
}
  
int main(){
  //cout << "here0" << endl;
  string junk;
  cin >> junk;
  cin >> junk;
  int vertice_count;
  cin >> vertice_count;
  int edge_count;
  cin >> edge_count;
  int first_vert;
  int second_vert;
  int len;
  vector <edge> edges;
  //cout << "here1" << endl;
  for(int i = 0; i < edge_count; i++){
    cin >> junk;
    cin >> first_vert;
    cin >> second_vert;
    cin >> len;
    edge newEdge = edge(first_vert, second_vert, len);
    edges.push_back(newEdge);
  }
  int start;
  cin >> start;
  vector <int> distances (vertice_count, -1); // distances from the start
  vector <bool> visited (vertice_count, false); // all the nodes that have been visited, originally set to false
  dijkstra(edges, start, visited, distances);
  return 0;
}
