#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* pseudo-code
 * input text file
 *      Start value
 *      Vertices
 *      Edges
 * create map of size vertices to levels
 * bfs(map)
 *      create queue as a vector
 *      add start to queue
 *      distance = 0
 *      map(s) = distance
 *      while q is not empty
 *              pop item = u
 *              for nbrs in u:
 *                      if not visited:
 *                              insert nbr to queue
 *                              map(nbr) = map(u)+1 // Here we add a level to current item
 */


void bfs(vector < vector<int> > adlst, int start)
{
        vector<int> queue;
        int vertices = adlst.size();
        queue.push_back(start);
        vector <int> dists(vertices, -1);
        dists[start] = 0;

        while(! queue.empty())
        {
                int u = queue.back();
                cout << "Popped: " << u << endl;
                queue.pop_back();
                for(int i = 0; i < adlst[u].size(); i++)
                {
                        cout << "current nbr: " << adlst[u][i] << endl;
                        for(int j = 0; j < dists.size(); j++)
                        {
                                cout << "vertex: " << j;
                                cout << " distance: " << dists[j] << endl;
                        }
                        cout << "current dists: " << dists[i] << endl;
                        if(dists[adlst[u][i]] == -1)
                        {
                                queue.insert(queue.begin(), adlst[u][i]);
                                //cout << i << endl;
                                dists[adlst[u][i]] = dists[u] + 1;
                                cout << "Changed dist of: "<< i;
                                cout << " to: " << dists[i] << endl;
                        }
                }
        }

        cout << endl;
        cout << "Final values: " << endl;
        for(int i = 0; i < vertices; i++)
        {
                cout << "vertex: " << i << " ";
                cout << "distance from start: " << dists[i] << endl;
        }
}

bool myfunction(int i, int j)
{
        return (i < j);
}


int main()
{
        string junk;
        cin >> junk;
        cin >> junk;
        int vertice_count;
        cin >> vertice_count;
        int edge_count;
        cin >> edge_count;
        int first_vert;
        int second_vert;
        vector < vector <int> > adlst;
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

        bfs(adlst, start);

        return 0;
}
      
