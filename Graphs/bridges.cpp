/*
    Bridges in a Graph
    Complexity: O(vertices + edges)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];
int disc[MAXN];
int low[MAXN];
int timeRef;

void bridgeUtil(int v) {
    visited[v] = true;
    disc[v] = low[v] = ++timeRef;
    for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
        int adj = *it;
        if (!visited[adj]) {
            parent[adj] = v;
            bridgeUtil(adj);
            low[v] = min(low[v], low[adj]);
            if (low[adj] > disc[v]) {
                cout << v << " " << adj << endl;
            }

        } else if (parent[v] != adj) {
            low[v] = min(low[v], disc[adj]);
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visited, false, sizeof visited);
    memset(parent, -1, sizeof parent);
    timeRef = 0;
    for (int i = 1; i <= vertices; i++) {
        if (!visited[i]) {
            bridgeUtil(i);
        }
    }
    return 0;
}
