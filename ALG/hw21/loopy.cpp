#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "math.h"
using namespace std;

struct edge{
  int begin;
  int end;
  bool taken;
  edge(int b, int e){
    begin = b;
    end = e;
    taken = false;
  }
};

vector< vector <int> >  makeAdList(vector <edge> edges, int verts){
  //init adlist
  vector< vector <int> > adList;
  for(int init = 0; init < verts; init++){
    vector <int> columns;
    adList.push_back(columns);
  }
  //make adjacency list
  for(int y = 0; y < edges.size(); y++){
    adList[edges[y].begin].push_back(edges[y].end);
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

bool notVisited(vector < vector <int> > visited, vector <int> target){
  int totalMatch = 0;
  for(int i =0; i < visited.size(); ++i){
    int totalMatch = 0;
    for(int j = 0; j < target.size(); ++j){
      if(target[j] == visited[i][j]){
	totalMatch++;
      }
      if(totalMatch == target.size()){
	return false;
      }
    }
  }
  return true;
}

void vDisp(vector <int> vec){
  cout << "Vec: ";
  for(int len = 0; len < vec.size(); ++len){
    cout << vec[len] << " ";
  }
  cout << endl;
}

void vvDisp(vector < vector <int> > vecvec){
  cout << "All pathes: " << endl;
  for(int height = 0; height < vecvec.size(); ++height){
    cout << "Path " << height << ": ";
    for(int width = 0; width < vecvec[height].size(); ++ width){
      cout << vecvec[height][width] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void eraseDubRuns(vector < vector <int> > &vec){
  for(int height = 0; height < vec.size(); ++height){
    int check0 = vec[height][0];
    int check1 = -1;
    int check2 = -1;

    if(vec[height].size() >= 2) check1 = vec[height][1];
    if(vec[height].size() > 3) check2 = vec[height][2];

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for(int width = 0; width < vec[height].size(); ++width){
      if(vec[height][width] == check0) ++count0;
      if(check1 != -1)
	{
	  if(vec[height][width] == check1) ++count1;
	}
      if(check2 != -1)
	{
	  if(vec[height][width] == check2) ++count2;
	}
    }
    if(count0 > 2 || count1 > 1 || count2 > 1)
      {
	cout << "count0: " << count0;
	cout << ", count1: " << count1;
	cout << ", count2: " << count2 << " ";
	vDisp(vec[height]);
	vec.erase(vec.begin() + height);
	--height;

      }
  }
}

vector < vector <int> > findall(vector< vector <int> >  adList, int vertice_count){
  vector < vector <int> > allPaths;
  int count = 0;
  int current = 0;

  //Start at every vertex
  for(int start = 0; start < vertice_count; start++){
    vector <int> path;
    path.push_back(start);
    allPaths.push_back(path);

    //total paths added
    count++;

    //Last steps taken
    int lastsize = 1;
    current = count - 1;

    //Iterate through all lengths up to 1 over vertice count to get all loops
    while(allPaths[current].size() < vertice_count+1){
      //Total items added in an iteration
      int step = 0;

      //Iterate through the last added vectors
      for(int i = 0; i < lastsize; ++i){
	//cout << "new iteration: " << lastsize << endl;
	//For each added vector, iterate over the number of nbrs to make new vectors
	for(int j = 0; j < adList[allPaths[current + i].back()].size(); ++j){
	  vector <int> path;
	  path = allPaths[current+i];
	  //cout << "first path: " << endl;
	  // for(int check = 0; check < path.size(); check++){
	  //      cout << path[check] << " ";
	  // }
	  // cout << endl;

	  //Add nbr and add to master list
	  path.push_back(adList[allPaths[current + i].back()][j]);
	  allPaths.push_back(path);
	  //cout << "Updated path: " << endl;
	  // for(int check = 0; check < path.size(); check++){
	  //      cout << path[check] << " ";
	  // }
	  //cout << endl;
	  count++;
	  step++;
	  //cout << "count: " << count << ", step: " << step << endl;
	}
      }
      //Set current to total number of vectors - those just added
      current = count - step;

      //lastsize = stepsize
      lastsize = step;

      //cout << "current: " << current << ", lastsize: " << lastsize << endl;
    }
  }
  cout << allPaths.size() << endl;
  vector < vector <int> > visited;
  vector < vector <int> > allLoops;
  int iter = 0;
  cout << endl;

  vvDisp(allPaths);

  eraseDubRuns(allPaths);

  vvDisp(allPaths);

  for(int printRow = 0; printRow < allPaths.size(); ++printRow){
    if(allPaths[printRow].size() > 1 && allPaths[printRow].front() == allPaths[printRow].back()){
      iter++;
      if(notVisited(visited, allPaths[printRow])){
	vector <int> path;
	for(int printCol = 0; printCol < allPaths[printRow].size(); ++printCol){
	  path.push_back(allPaths[printRow][printCol]);
	}
	allLoops.push_back(path);
	visited.push_back(allPaths[printRow]);
      }
    }
  }
  return allLoops;
}
bool notShift(vector <int> target, vector < vector <int> > &visited){
  vector <int> temp;
  for(int row = 0; row < visited.size(); ++row){
    temp = visited[row];
    if(target.size() == visited[row].size()){
      for(int halfRow = 0; halfRow < visited[row].size(); ++halfRow){
	int sims = 0;
	for(int col = 0; col < visited[row].size(); ++col){
	  if(temp[col] == target[col])
	    ++sims;
	}
	temp.push_back(temp.front());
	temp.erase(temp.begin());
	if(sims == target.size()){
	  visited.push_back(target);
	  return true;
	}
      }
    }
  }
  return false;
}

void findSimpleLoops(vector < vector <int> > allLoops){
  vector < vector <int> > visited;
  vector < vector <int> > simpleLoops;
  int total = 0;

  for(int height = 0; height < allLoops.size(); ++height){
    allLoops[height].pop_back();
    if(allLoops[height].size() == 2)
      sort(allLoops[height].begin(),allLoops[height].end());
  }

  for(int h = 0; h < allLoops.size(); ++h){
    notShift(allLoops[h], visited);
    if(notVisited(visited, allLoops[h])){
      visited.push_back(allLoops[h]);
      simpleLoops.push_back(allLoops[h]);
      ++total;
    }
  }
  cout << "Simple loops: " << endl;
  vvDisp(simpleLoops);
  cout << "Total Simple Loops: " << total << endl;
}

int main(){
  srand((unsigned int) time (NULL));
  int vertice_count;
  cin >> vertice_count;
  int edge_count;
  cin >> edge_count;
  int first_vert;
  int second_vert;
  vector <edge> edges;
  for(int i = 0; i < edge_count; i++){
    cin >> first_vert;
    cin >> second_vert;
    edge newEdge = edge(first_vert, second_vert);
    edges.push_back(newEdge);
  }
  cout << "The edges are: " << endl;
  for(int x = 0; x < edges.size(); x++){
    cout << edges[x].begin << " " << edges[x].end << endl;
  }
  cout << endl;

  vector< vector <int> >  adList;
  adList = makeAdList(edges, vertice_count);
  vector < vector <int> > allLoops;
  allLoops = findall(adList, vertice_count);

  vvDisp(allLoops);
  cout << endl;

  findSimpleLoops(allLoops);

  return 0;
}