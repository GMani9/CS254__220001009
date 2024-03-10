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

    void topo_dfs(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        for (int i = 0; i < adj[v].size(); ++i) {
            int adj_vertex = adj[v][i];
            if (!visited[adj_vertex])
                topo_dfs(adj_vertex, visited, Stack);
        }

        Stack.push(v);
    }

    void topo_sort() {
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                topo_dfs(i, visited, Stack);
        }

        cout << "Topological sorting of the graph: ";
        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
};

int main() {

    ifstream inputFile("input.txt");

    int V, E;
    inputFile >> V >> E;

    Graph g(V);

    //adding edges
    for (int i = 0; i < E; ++i) {
        int u, v;
        inputFile >> u >> v;
        g.addEdge(u, v);
    }

    g.topo_sort();

    return 0;
}
