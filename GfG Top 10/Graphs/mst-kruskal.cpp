/*
	Kruskal's Minimum Spanning Tree
	Complexity: O(edges * log(edges))
*/
#include <bits/stdc++.h>
using namespace std;

#define N 100010

typedef struct edge {
	int a;
	int b;
	int w;
} Edge;

int parent[N];
int vrank[N];
Edge graph[N];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void join(int x, int y) {
	int sx = find(x);
	int sy = find(y);

	if (vrank[sx] > vrank[sy]) {
		parent[sy] = sx;
	} else if (vrank[sx] < vrank[sy]) {
		parent[sx] = sy;
	} else {
		parent[sx] = sy;
		vrank[sy]++;
	}
}

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

void mst(int n, int e) {
	sort(graph, graph+e, cmp);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		vrank[i] = 0;
	}
	int ce = 0;
	int re = 0;
	while (re < n - 1 && ce < e) {
		if (find(graph[ce].a) != find(graph[ce].b)) {
			cout << graph[ce].a << " " << graph[ce].b << "\n";
			join(graph[ce].a, graph[ce].b);
			re++;
		}
		ce++;
	}

}


int main() {
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> graph[i].a >> graph[i].b >> graph[i].w;
	}
	mst(n, e);
	return 0;
}
