/*
    Depth First Search
    Complexity: O(v + e)
*/
#include <bits/stdc++.h>
using namespace std;

#define N 10010

vector<int> adjs[N];
bool visited[N];

/*
	Procura se existe um caminho entre o vértice raiz e cada um dos outros.
	r - vértice raiz
*/
void dfs(int cv) {
	visited[cv] = true;
	for (int i = 0; i < adjs[cv].size(); i++) {
		int av = adjs[cv][i];
		if (!visited[av]) {
			dfs(av);
		}
	}
}

/*
	Reseta o estado dos vérticies e chama dfs.
*/
void dfsU(int r, int v) {
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	dfs(0);
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
	dfsU(0, v);
	for (int i = 0; i < v; i++) {
		cout << visited[i] << " ";
	}
	cout << endl;
	return 0;
}