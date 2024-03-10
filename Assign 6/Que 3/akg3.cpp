#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> adjTranspose;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        adjTranspose.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adjTranspose[v].push_back(u);
    }

    void dfs(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        for (int adj_vertex : adj[v]) {
            if (!visited[adj_vertex])
                dfs(adj_vertex, visited, Stack);
        }

        Stack.push(v);
    }

    void dfsTranspose(int v, vector<bool>& visited, unordered_set<int>& component) {
        visited[v] = true;
        component.insert(v);

        for (int adj_vertex : adjTranspose[v]) {
            if (!visited[adj_vertex])
                dfsTranspose(adj_vertex, visited, component);
        }
    }

    vector<unordered_set<int>> getSCCs() {
        vector<bool> visited(V, false);
        stack<int> Stack;

        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                dfs(i, visited, Stack);
        }

        vector<unordered_set<int>> sccs;
        visited.assign(V, false);

        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();

            if (!visited[v]) {
                unordered_set<int> component;
                dfsTranspose(v, visited, component);
                sccs.push_back(component);
            }
        }

        return sccs;
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

    vector<unordered_set<int>> sccs = g.getSCCs();

    cout << "Strongly Connected Components:" << endl;
    for (const auto& scc : sccs) {
        for (int vertex : scc) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
