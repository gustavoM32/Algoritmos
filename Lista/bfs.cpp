/*
	Breadth First Search
	Complexidade: O(v + e)
	Nome: "BFS"
	Atalho: "bfs"
	Descrição: "Encontra as distâncias mínimas de um vértice a todos os outros em um grafo"
*/
#include <bits/stdc++.h>
using namespace std;

#define N 10010

/*
	Lista de adjacências e vetor de distância
*/
//[
vector<int> adjs[N];
int dist[N];
//]

/*
	Inicializa a lista de adjacências
	v - número de vértices
	e - número de arestas
*/
void graphInit(int v, int e) {
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		adjs[x].push_back(y);
		adjs[y].push_back(x);
	}
}

/*
	Calcula a menor distancia de um vértice para todos os outros.
	r - vértice raiz
*/
//[
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
//]

/*
	Reseta as distâncias e chama bfs.
	r - vértice raiz
	v - número de vértices
*/
//[
void bfsU(int r, int v) {
	for (int i = 0; i < v; i++) {
		dist[i] = -1;
	}
	bfs(r);
}
//]

int main() {
	int v, e;
	cin >> v >> e;
	graphInit(v, e);
	bfsU(0, v);
	for (int i = 0; i < v; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
	return 0;
}
