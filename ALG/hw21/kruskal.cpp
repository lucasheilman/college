#include<iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
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
  void display(){
    cout << "vert1: " << begin << " vert2: " << end << " length: " << len << endl;
  }
};

// Class for an undirected graph
class Graph
{
public:
  int V;    // No. of vertices
  vector <edge> edges;
  list<int> *adj;    // Pointer to an array containing adjacency lists
  bool isCyclicUtil(int v, bool visited[], int parent);
  Graph(int V);   // Constructor
  void addEdge(edge e);   // to add an edge to graph
  void remEdge(edge e);
  bool isCyclic();   // returns true if there is a cycle
};
 
Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
  //edges.resize(V);
  //for(int i = 0; i < edges.size()
}
 
void Graph::addEdge(edge ed)
{
  //edge ed(b,e,l);
  edges.push_back(ed);
  adj[ed.begin].push_back(ed.end); // Add w to vs list.
  adj[ed.end].push_back(ed.begin); // Add v to ws list.
}

void Graph::remEdge(edge ed)
{
  //edge ed(b,e,l);
  edges.pop_back();
  adj[ed.begin].pop_back(); // Add w to vs list.
  adj[ed.end].pop_back(); // Add v to ws list.
}
 
// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v.}
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
  // Mark the current node as visited
  visited[v] = true;
 
  // Recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
      // If an adjacent is not visited, then recur for that adjacent
      if (!visited[*i])
        {
	  if (isCyclicUtil(*i, visited, v))
	    return true;
        }
 
      // If an adjacent is visited and not parent of current vertex,
      // then there is a cycle.
      else if (*i != parent)
	return true;
    }
  return false;
}
 
// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
  // Mark all the vertices as not visited and not part of recursion
  // stack
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;
 
  // Call the recursive helper function to detect cycle in different
  // DFS trees
  for (int u = 0; u < V; u++)
    if (!visited[u]) // Don't recur for u if it is already visited
      if (isCyclicUtil(u, visited, -1))
	return true;
 
  return false;
}
void sortplz(vector <edge> &edges){
  bool sortd = false;
  while(sortd == false){
    for(int i = 1; i<edges.size();i++){
      if(edges[i].len < edges[i-1].len){
	swap(edges[i],edges[i-1]);
      }
    }
    bool valgood = true;
    for(int i = 1; i<edges.size();i++){
      for(int x = i - 1; x >= 0; x--){
	if(edges[i].len < edges[x].len){
	  valgood = false;
	}
      }
    }
    sortd = valgood;
  }
}

int main()
{
  Graph g1(6);
  vector <edge> edges;
  edge e1(0,1,5);
  edges.push_back(e1);
  edge e2(0,2,6);
  edges.push_back(e2);
  edge e3(0,3,4);
  edges.push_back(e3);
  edge e4(1,2,1);
  edges.push_back(e4);
  edge e5(1,3,2);
  edges.push_back(e5);
  edge e6(2,3,2);
  edges.push_back(e6);
  edge e7(2,5,3);
  edges.push_back(e7);
  edge e8(2,4,5);
  edges.push_back(e8);
  edge e9(3,5,4);
  edges.push_back(e9);
  edge e10(4,5,4);
  edges.push_back(e10);
  sortplz(edges);
  int count = 0;
  while(count < g1.V-1){
    edge start = edges[0];
    edges.erase(edges.begin());
    g1.addEdge(start);
    if(g1.isCyclic()){
      g1.remEdge(start);
    }
    else{
      count = count+1;
    }
  }
  cout << "Used Edges:" << endl;
  for(int i = 0; i < g1.edges.size(); i++){
    g1.edges[i].display();
  }
  return 0;
}
