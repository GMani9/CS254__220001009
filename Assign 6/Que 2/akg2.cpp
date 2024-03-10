#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
    }

    void topo_dfs(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        for (auto& neighbor : adj[v]) {
            int adj_vertex = neighbor.first;
            if (!visited[adj_vertex])
                topo_dfs(adj_vertex, visited, Stack);
        }

        Stack.push(v);
    }

    vector<int> longestPath(int source) {
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                topo_dfs(i, visited, Stack);
        }

        vector<int> distance(V, INT_MIN);
        distance[source] = 0;

        while (!Stack.empty()) {
            int u = Stack.top();
            Stack.pop();

            if (distance[u] != INT_MIN) {
                for (auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    distance[v] = max(distance[v], distance[u] + weight);
                }
            }
        }

        return distance;
    }
};

int main() {

    ifstream inputFile("input.txt");

    int N, M;
    inputFile >> N >> M;

    Graph g(N);

    for (int i = 0; i < M; ++i) {
        int u, v, weight;
        inputFile >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    int source;
    inputFile >> source;

    vector<int> longest_paths = g.longestPath(source);

    int longest_path_length = *max_element(longest_paths.begin(), longest_paths.end());

    cout << "Length of the longest path from vertex " << source << ": " << longest_path_length << endl;

    return 0;
}
