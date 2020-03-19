/*
	Depth First Search
	Complexidade: O(v + e)
	Nome: "DFS"
	Atalho: "dfs"
	Descrição: "Encontra os vértices adjacentes a um dado vértice."
*/
#include <bits/stdc++.h>
using namespace std;

#define N 10010

/*
	Lista de adjacências e distâncias
*/
//[
vector<int> adjs[N];
bool visited[N];
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
	Procura se existe um caminho entre o vértice raiz e cada um dos outros.
	r - vértice raiz
*/
//[
void dfs(int cv) {
	visited[cv] = true;
	for (int i = 0; i < adjs[cv].size(); i++) {
		int av = adjs[cv][i];
		if (!visited[av]) {
			dfs(av);
		}
	}
}
//]

/*
	Reseta o estado dos vérticies e chama dfs.
*/
//[
void dfsU(int r, int v) {
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	dfs(r);
}
//]

int main() {
	int v, e;
	cin >> v >> e;
	graphInit(v, e);
	dfsU(0, v);
	for (int i = 0; i < v; i++) {
		cout << visited[i] << " ";
	}
	cout << endl;
	return 0;
}
