#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    int time;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        time = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<pair<int, int>>& bridges) {
        disc[u] = low[u] = ++time;
        int children = 0;
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                children++;
                parent[v] = u;
                dfs(v, disc, low, parent, bridges);
                low[u] = min(low[u], low[v]);

                // Bridge found
                if (low[v] > disc[u])
                    bridges.push_back({u, v});
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        // Articulation point found
        if (parent[u] == -1 && children > 1)
            cout << "Articulation point: " << u << endl;
        else if (parent[u] != -1 && low[u] >= disc[u])
            cout << "Articulation point: " << u << endl;
    }

    void findBridges() {
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<pair<int, int>> bridges;

        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1)
                dfs(i, disc, low, parent, bridges);
        }

        cout << "Bridges in the graph:\n";
        for (auto bridge : bridges) {
            cout << bridge.first << " - " << bridge.second << endl;
        }
    }
};

int main() {
    
    ifstream inputFile("input.txt");

    int V, E;
    inputFile >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; ++i) {
        int u, v;
        inputFile >> u >> v;
        g.addEdge(u, v);
    }

    g.findBridges();

    return 0;
}
