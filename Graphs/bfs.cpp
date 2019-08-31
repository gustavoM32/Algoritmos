/* Breadth First Search */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

vector<int> adj[MAXN];
bool visited[MAXN] = {false};

void bfs(int root) {
    queue<int> check;
    check.push(root);
    visited[root] = true;

    while (!check.empty()) {
        int curNode = check.front();
        check.pop();
        cout << "Visiting node " << curNode << endl;
        for (auto it = adj[curNode].begin(); it != adj[curNode].end(); it++) {
            if (visited[*it]) continue;
            visited[*it] = true;
            check.push(*it);
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
    }
    memset(visited, false, sizeof visited);
    bfs(1);
    for (int i = 1; i <= vertices; i++) {
        cout << i << ": " << (visited[i] ? "YES" : "NO") << endl;
    }
    return 0;
}
