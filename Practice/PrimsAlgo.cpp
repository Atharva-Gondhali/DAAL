#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void prims_algo(const vector<vector<pair<int, int>>> graph)
{
    int nvertices = graph.size();
    vector<int> key(nvertices, INT_MAX);
    vector<int> parent(nvertices, -1);
    vector<bool> mst(nvertices, false);

    key[0] = 0;
    for(int i = 0; i < nvertices; i++)
    {
        int min = INT_MAX;
        int curr_vertex;

        for(int j = 0; j < nvertices; j++)
        {
            if(mst[j] == false && key[j] < min)
            {
                curr_vertex = j;
                min = key[j];
            }
        }

        mst[curr_vertex] = true;

        for(auto it: graph[curr_vertex])
        {
            if(mst[it.first] == false && it.second < key[it.first])
            {
                parent[it.first] = curr_vertex;
                key[it.first] = it.second;
            }
        }

    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < nvertices; ++i) {
        cout << parent[i] << " - " << i << " with weight " << key[i] << "\n";
    }
}

int main()
{
    int nvertex;
    int nedges;
    cout << "Enter number of vertices: ";
    cin >> nvertex;
    cout << "Enter number of edges: ";
    cin >> nedges;

    vector<vector<pair<int, int>>> graph(nvertex);
    cout << "Enter edge pairs and weight(u v w): ";
    for(int i = 0; i < nedges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    prims_algo(graph);
}