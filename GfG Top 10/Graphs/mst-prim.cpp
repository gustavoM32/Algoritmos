/*
	Prim’s Minimum Spanning Tree
	Complexity: O(vertices ^ 2)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 110

int graph[MAXN][MAXN];
bool mstSet[MAXN];
int key[MAXN];
int parent[MAXN];

int getMin(int vertices) {
	int minW = INT_MAX;
	int minId;
	for (int i = 1; i <= vertices; i++) {
		if (!mstSet[i] && key[i] < minW) {
			minW = key[i];
			minId = i;
		}
	}
	return minId;
}

void prim(int vertices) {
	for (int i = 1; i <= vertices; i++) {
		mstSet[i] = false;
		key[i] = INT_MAX;
	}

	key[1] = 0;
	parent[1] = -1;

	for (int i = 0; i < vertices - 1; i++) {
		int addedV = getMin(vertices);
		mstSet[addedV] = true;

		for (int j = 1; j <= vertices; j++) {
			if (!mstSet[j] && graph[addedV][j] != 0 && graph[addedV][j] < key[j]) {
				key[j] = graph[addedV][j];
				parent[j] = addedV;
			}
		}
	}
}

int main() {
	int vertices, edges;
	cin >> vertices >> edges;
	for (int i = 1; i <= vertices; i++) {
		for (int j = 1; j <= vertices; j++) {
			graph[i][j] = 0;
		}
	}
	for (int i = 0; i < edges; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a][b] = w;
		graph[b][a] = w;
	}
	prim(vertices);
	cout<<"Edge \tWeight\n";
	for (int i = 2; i <= vertices; i++) {
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
	}
	return 0;
}
