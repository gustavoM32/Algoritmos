/*
    Breadth First Search
    Complexity: O(v + e)
*/
#include <bits/stdc++.h>
using namespace std;

#define N 10010

vector<int> adjs[N];
int dist[N];

/*
	Calcula a menor distancia de um vértice para todos os outros.
	r - vértice raiz
*/
void bfs(int r) {
	queue<int> q;
	dist[r] = 0;
	q.push(r);
	while (!q.empty()) {
		int cv = q.front();
		q.pop();
		for (int i = 0; i < adjs[cv].size(); i++) {
			int av = adjs[cv][i];
			if (dist[av] == -1) {
				dist[av] = dist[cv] + 1;
				q.push(av);
			}
		}
	}
}

/*
	Reseta as distâncias e chama bfs.
	r - vértice raiz
	v - número de vértices
*/
void bfsU(int r, int v) {
	for (int i = 0; i < v; i++) {
		dist[i] = -1;
	}
	bfs(0);
}

int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		adjs[x].push_back(y);
		adjs[y].push_back(x);
	}
	bfsU(0, v);
	for (int i = 0; i < v; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
	return 0;
}