#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

vector<int> dijkstras_algo(vector<vector<pair<int, int>>> &graph, int source)
{ 
    vector<int> dist(graph.size());
    for(int i = 0; i < graph.size(); i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert(make_pair(source, 0));

    while(!st.empty())
    {
        auto top = *(st.begin());

        int distance = top.second;
        int vertex = top.first;

        st.erase(st.begin());

        for(auto neighbour: graph[vertex])
        {
            if(distance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(neighbour.first, dist[neighbour.second]));
                
                if(record != st.end())
                {
                    st.erase(record);
                }

                dist[neighbour.first] = distance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
    
}

int main()
{
    int nvertex, nedges, source;
    cout << "Enter number of vertex: ";
    cin >> nvertex;
    cout << "Enter number of edges: ";
    cin >> nedges;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<vector<pair<int, int>>> graph(nvertex);

    cout << "Enter edge pairs(u v w): ";
    for(int i = 0; i < nedges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    dijkstras_algo(graph, source);
}
