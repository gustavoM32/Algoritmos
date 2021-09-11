#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007
#define N 10010

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int t[2*N];
int n, k;

void build() {	
	for (int i = 0; i < 2*n; i++) t[i] = -INF;
}

void change(int i, int v) {
	i += n;
	t[i] = v;
	while (i > 1) {
		t[i >> 1] = max(t[i], t[i^1]);
		i >>= 1;
	}
}

int seg_query(int i, int j) {
	int res = -INF;
	i += n;
	j += n+1;

	while (i < j) {
		if (i & 1) {
			res = max(res, t[i]);
			i++;
		}
		if (j & 1) {
			j--;
			res = max(res, t[j]);
		}

		i >>= 1;
		j >>= 1;
	}
	return res;
}

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = seg_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = seg_query(pos[a]+1, pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

void solve() {
	cin >> n;
	vector<vector<int>> adjs(n);
	vector<pair<pair<int, int>, int>> edges;
	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edges.push_back({{a, b}, c});
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}
	init(adjs);
	build();
	for (auto &p : edges) {
		int &a = p.first.first;
		int &b = p.first.second;
		if (parent[a] != b) swap(a, b);
		change(pos[a], p.second);
	}
	string s;
	cin >> s;
	while (s != "DONE") {
		int x, y;
		cin >> x >> y;
		if (s == "CHANGE") {
			change(pos[edges[x-1].first.first], y);
		} else {
			cout << query(x-1, y-1) << "\n";
		}

		cin >> s;
	}
	
}

int main() {
	FASTIO;
	int tst; cin >> tst; while (tst--)
	solve();
	return 0;
}

