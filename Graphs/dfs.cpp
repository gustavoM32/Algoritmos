/* Depth First Search */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int root) {
    visited[root] = true;
    cout << "Visiting node " << root << endl;
    for (auto it = adj[root].begin(); it != adj[root].end(); it++) {
        if (visited[*it]) continue;
        dfs(*it);
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(visited, false, sizeof visited);
    dfs(1);
    for (int i = 1; i <= vertices; i++) {
        cout << i << ": " << (visited[i] ? "YES" : "NO") << endl;
    }
    return 0;
}
