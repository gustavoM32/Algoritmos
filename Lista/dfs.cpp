/*
	Lista de adjacências e distâncias
*/
vector<int> adjs[N];
bool visited[N];

/*
	Procura se existe um caminho entre o vértice raiz e cada um dos outros.
	r - vértice raiz
*/
void dfsRec(int cv) {
	visited[cv] = true;
	for (int i = 0; i < adjs[cv].size(); i++) {
		int av = adjs[cv][i];
		if (!visited[av]) {
			dfsMain(av);
		}
	}
}

/*
	Reseta o estado dos vértices e chama dfs.
*/
void dfs(int r, int v) {
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	dfsRec(r);
}
