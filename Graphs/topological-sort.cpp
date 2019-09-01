/*
    Topological Sorting
    Complexity: O(vertices + edges)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

vector<int> adj[MAXN];
bool visited[MAXN];
stack<int> sorted;

void tsUtil(int vertex) {
    visited[vertex] = true;
    for (auto it = adj[vertex].begin(); it != adj[vertex].end(); it++) {
        if (visited[*it]) continue;
        tsUtil(*it);
    }
    sorted.push(vertex);
}

void ts(int vertices) {
    for (int i = 1; i <= vertices; i++) {
        if (visited[i]) continue;
        tsUtil(i);
    }

    while (!sorted.empty()) {
        cout << sorted.top() << " ";
        sorted.pop();
    }
    cout << endl;
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
    ts(vertices);
    for (int i = 1; i <= vertices; i++) {
        cout << i << ": " << (visited[i] ? "YES" : "NO") << endl;
    }
    return 0;
}
