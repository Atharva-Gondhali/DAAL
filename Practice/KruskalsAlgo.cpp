#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void make_set(vector<int> &parent, vector<int> &rank)
{
    for(int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_parent(vector<int> &parent, int n)
{
    if(parent[n] == n)
    {
        return n;
    }
    return parent[n] = find_parent(parent, parent[n]);
}

void union_set(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = find_parent(parent, u);
    v = find_parent(parent, v);

    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

int main()
{
    int nvertex, nedges;
    cout << "Enter number of vertex: ";
    cin >> nvertex;
    cout << "Enter number of edges: ";
    cin >> nedges;

    int arr[nedges][3];
    vector<vector<int>> edges(nedges);

    cout << "Enter the edge pairs(u v w): ";
    for(int i = 0; i < nedges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].push_back(u);
        edges[i].push_back(v);
        edges[i].push_back(w);
    }

    std::sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(nvertex);    
    vector<int> rank(nvertex);
    make_set(parent, rank);

    int min_weight = 0;

    for(int i = 0; i < nedges; i++)
    {
        int u = find_parent(parent, edges[i][0]);
        int v = find_parent(parent, edges[i][1]);

        if(u != v)
        {
            min_weight += edges[i][2];
            union_set(parent, rank, u, v);
            cout << "Selected Edge: (" << edges[i][0] << ", " << edges[i][1] << ") with weight " << edges[i][2] << endl;
        }
    }

    cout << "The minimum cost of spanning tree is " << min_weight;
}