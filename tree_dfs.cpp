#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int pair_count = 0;

bool myfunction (int i,int j) 
{
    return (i<j);
}   

void pretty_print(vector <vector <int> > vec)
{
    cout << "[";
    for(int i = 0; i < vec.size(); i++)
    {
        cout << "[";
        for(int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

void DFS(vector<vector <int> > adlst, int node, vector <bool> visited)
{
    visited[node] = true;
    for(int i = 0; i < adlst[node].size();i++)
    {
        if(!visited[adlst[node][i]])
        {
            cout << "current node: " << node << " next node: " << (adlst[node][i]) << endl;
            DFS(adlst, adlst[node][i], visited);
        }
    }
}

int main()
{
    int node_count;
    cin >> node_count;
    int edge_count;
    cin >> edge_count;
    int first_node;
    int second_node;
    vector <vector <int> > adlst;
    adlst.resize(node_count+1);
    for(int i = 1; i < edge_count + 1; i++)
    {
        cin >> first_node;
        cin >> second_node;
        adlst[first_node].push_back(second_node);
        adlst[second_node].push_back(first_node);
    }
    for(int i = 0; i < adlst.size(); i++)
    {
        sort(adlst[i].begin(), adlst[i].end(), myfunction);
    }
    pretty_print(adlst);
    vector <bool> visited;
    visited.resize(adlst.size());
    for(int i = 0; i < visited.size(); i++)
    {
        visited[i] = false;
    }
    DFS(adlst, 1, visited);
}
