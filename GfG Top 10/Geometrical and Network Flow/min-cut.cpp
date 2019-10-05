/*
    s-t min cut
    Complexity: O(ed * v^2)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXV 110

bool bfs(int graph[MAXV][MAXV], int v, int s, int e, int parent[MAXV]) {
    bool visited[MAXV];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    queue<int> toVisit;
    toVisit.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!toVisit.empty()) {
        int curV = toVisit.front();
        toVisit.pop();
        for (int adjV = 0; adjV < v; adjV++) {
            if (!visited[adjV] && graph[curV][adjV] > 0) {
                toVisit.push(adjV);
                visited[adjV] = true;
                parent[adjV] = curV;
            }
        }
    }
    return visited[e];
}

void dfs(int graph[MAXV][MAXV], int v, int s, bool visited[MAXV]) {
    visited[s] = true;
    for (int i = 0; i < v; i++) {
        if (!visited[i] && graph[s][i] > 0) dfs(graph, v, i, visited);
    }
}

void minCut(int graph[MAXV][MAXV], int v, int s, int e) {
    int rGraph[MAXV][MAXV];
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            rGraph[i][j] = graph[i][j];
        }
    }

    int parent[MAXV];
    int maxFlow = 0;

    while (bfs(rGraph, v, s, e, parent)) {
        int pathFlow = INT_MAX;
        for (int c = e; c != s; c = parent[c]) {
            int p = parent[c];
            pathFlow = min(pathFlow, rGraph[p][c]);
        }

        for (int c = e; c != s; c = parent[c]) {
            int p = parent[c];
            rGraph[p][c] -= pathFlow;
            rGraph[c][p] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    bool visited[MAXV];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    dfs(rGraph, v, s, visited);
    for (int i = 0; i < v; i++) {
        if (visited[i]) {
            for (int j = 0; j < v; j++) {
                if (!visited[j] && graph[i][j] > 0) cout << i << " - " << j << "\n";
            }
        }
    }
}

int main() {
    int v, ed, s, e;
    cin >> v >> ed >> s >> e;
    int graph[MAXV][MAXV];
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < ed; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    minCut(graph, v, s, e);
    return 0;
}
