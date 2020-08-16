/*
	Lista de adjacências e vetor de distância
*/
vector<int> adjs[N];
int dist[N];

/*
	Calcula a menor distancia de um vértice para todos os outros.
	r - vértice raiz
*/
void bfsRec(int r) {
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
void bfs(int r, int v) {
	for (int i = 0; i < v; i++) {
		dist[i] = -1;
	}
	bfsRec(r);
}
