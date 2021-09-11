#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007
#define N 100010

int centroid[N];
int sz[N];
int parent[N];
int son[N];
vector<int> adjs[N];

void dfs(int v) {
	sz[v] = 1;
	son[v] = -1;
	for (int av : adjs[v]) {
		if (av == parent[v] || centroid[av] != -1) continue;
		parent[av] = v;
		dfs(av);
		sz[v] += sz[av];
		if (son[v] == -1 || sz[son[v]] < sz[av]) son[v] = av;
	}
}

int find(int r) {
	parent[r] = -1;
	dfs(r);
	int c = r;
	while (son[c] != -1 && sz[son[c]] > sz[r] / 2) c = son[c];
	return c;
}

void findAll(int r=0, int rank=0) {
	int c = find(r);
	centroid[c] = rank;
	for (int av : adjs[c]) {
		if (centroid[av] != -1) continue;
		parent[av] = -1;
		findAll(av, rank + 1);
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		centroid[i] = -1;
	}

	findAll();

	for (int i = 0; i < n; i++) {
		cout << char('A' + centroid[i]) << " ";
	}
	cout << "\n";
}

int main() {
	FASTIO;
	solve();
	return 0;
}
