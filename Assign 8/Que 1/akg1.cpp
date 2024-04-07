#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int weight, u, v;
    Edge(int w, int U, int V) : weight(w), u(U), v(V) {}
};

struct CompareEdges {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight;
    }
};

vector<int> p;
int find(int x) {
    if(x==p[x]) return x;
    return p[x] = find(p[x]);
}

bool unite(int u, int v) {
    int x = find(u);
    int y = find(v);
    if(x==y) return false;
    p[y]=x;  return true;
}

int main() {
    int n, m; cin >> n >> m;
    int u, v, w; p.resize(n+1);
    for(int i=0; i<=n; ++i) p[i] = i;
    priority_queue<Edge, vector<Edge>, CompareEdges> Q;
    for(int i=0; i<m; ++i) {
        cin >> u >> v >> w;
        Edge e(w, u, v);
        Q.push(e);
    }
    int ans = 0;
    while(!Q.empty()) {
        Edge e = Q.top();
        Q.pop();
        if(unite(e.u, e.v)) ans += e.weight;
    }
    cout << ans << "\n";
    return 0;
}