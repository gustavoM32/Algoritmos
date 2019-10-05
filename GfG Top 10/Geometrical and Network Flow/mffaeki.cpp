/*
    Ford Fulkerson Maximum Flow
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

int ford(int graph[MAXV][MAXV], int v, int s, int e) {
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
    return maxFlow;
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
    cout << ford(graph, v, s, e) << endl;
    return 0;
}
