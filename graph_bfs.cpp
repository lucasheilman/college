#include <bits/stdc++.h>

using namespace std;

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

void BFS(vector <vector <int> > adlst, vector <int> visited, int start)
{
    visited[start] = 0;
    vector <int> queue;
    queue.push_back(start);
    while(!queue.empty())
    {
        int current = queue[0];
        queue.erase(queue.begin());
        for(int i = 0; i < adlst[current].size(); i++)
        {
            if(visited[adlst[current][i]] == -1)
            {
                queue.push_back(adlst[current][i]);
                visited[adlst[current][i]] = visited[current] + 6;
            }
        }
    }
    for(int i = 1; i < visited.size(); i++)
    {
        if(i != start)
        {
            cout << visited[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int q;
    cin >> q;
    for(int j = 0; j < q; j++)
    {
        int node_count;
        cin >> node_count;
        int edge_count;
        cin >> edge_count;
        int first_node;
        int second_node;
        vector <vector <int> > adlst;
        adlst.resize(node_count+1);
        for(int i = 0; i < edge_count; i++)
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
        vector <int> visited;
        visited.resize(adlst.size());
        for(int i = 0; i < visited.size(); i++)
        {
            visited[i] = -1;
        }
        int start;
        cin >> start;
        BFS(adlst, visited, start);
    }
    return 0;
}
