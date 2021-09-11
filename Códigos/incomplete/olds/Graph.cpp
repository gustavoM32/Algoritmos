class Graph {
	int v;
	bool directed;
	vector<vector<int>> adjs;
	
	public:
	Graph(int v, bool directed) {
		this->v = v;
		this->directed = directed;
		adjs.reserve(v);
	}

	addEdge(int a, int b) {
		adjs[a].push_back(b);
		if (directed) adjs[b].push_back(a);
	}
}