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

// n funciona pra isso
/*
11 22 3 7
3 0 6
3 4 8
3 8 14
0 1 2
0 4 4
1 2 9 
1 6 1
2 6 3
2 7 9
4 5 7
5 0 5
5 9 11
6 5 7
6 7 6
6 10 8
8 4 1
8 2 5
8 5 8
8 9 2
9 7 2
9 10 9
10 7 12

deu 18

era pra ser 20
*/