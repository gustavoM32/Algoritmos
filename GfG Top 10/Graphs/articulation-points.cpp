/*
    Articulation Points
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
bool ap[MAXN];
int timeRef;

void apUtil(int v) {
    int children = 0;
    visited[v] = true;
    disc[v] = low[v] = ++timeRef;
    for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
        int adj = *it;
        if (!visited[adj]) {
            children++;
            parent[adj] = v;
            apUtil(adj);

            low[v] = min(low[v], low[adj]);

            if (parent[v] == -1 && children >= 2) {
                ap[v] = true;
            }
            if (parent[v] != -1 && low[adj] >= disc[v]) {
                ap[v] = true;
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
    memset(ap, false, sizeof ap);
    timeRef = 0;
    for (int i = 1; i <= vertices; i++) {
        if (!visited[i]) {
            apUtil(i);
        }
    }
    for (int i = 1; i <= vertices; i++) {
        if (ap[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
