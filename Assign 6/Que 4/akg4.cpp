#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool dfs(int v, vector<bool>& visited, vector<bool>& recStack) {
        if (!visited[v]) {
            visited[v] = true;
            recStack[v] = true;

            for (int i = 0; i < adj[v].size(); ++i) {
                int adj_vertex = adj[v][i];
                if (!visited[adj_vertex] && dfs(adj_vertex, visited, recStack))
                    return true;
                else if (recStack[adj_vertex])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; ++i)
            if (dfs(i, visited, recStack))
                return true;

        return false;
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

    if (g.isCyclic())
        cout << "The directed graph has a cycle." << endl;
    else
        cout << "The directed graph does not have a cycle." << endl;

    return 0;
}
