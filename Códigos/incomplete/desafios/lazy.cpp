#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100010

int st[26][4*N];
int lz[26][4*N];

void build(int c, string &s, int i, int il, int ir) {
	if (il > ir) return;

	lz[c][i] = -1;

	if (il == ir) {
		st[c][i] = (s[il] - 'a') == c;
	} else {
		int im = (il + ir) / 2;
		build(c, s, 2*i, il, im);
		build(c, s, 2*i+1, im+1, ir);
		st[c][i] = st[c][2*i] + st[c][2*i+1];
	}
}

void lazyUpdate(int c, int i, int il, int ir) {
	if (lz[c][i] != -1) {
		st[c][i] = (ir - il + 1) * lz[c][i];
		if (il != ir) {
			lz[c][2*i] = lz[c][i];
			lz[c][2*i+1] = lz[c][i];
		}
		lz[c][i] = -1;
	}
}

int query(int c, int i, int il, int ir, int l, int r) {
	lazyUpdate(c, i, il, ir);
	
	if (r < il || ir < l) return 0;
	if (l <= il && ir <= r) return st[c][i];
	
	int im = (il + ir) / 2;
	return query(c, 2*i, il, im, l, r)
		+  query(c, 2*i+1, im+1, ir, l, r);
}

void update(int c, int i, int il, int ir, int l, int r, int v) {
	lazyUpdate(c, i, il, ir);

	if (r < il || ir < l) return;
	if (l <= il && ir <= r) {
		lz[c][i] = v;
		lazyUpdate(c, i, il, ir);
	} else {
		int im = (il + ir) / 2;
		update(c, 2*i, il, im, l, r, v);
		update(c, 2*i+1, im+1, ir, l, r, v);
		st[c][i] = st[c][2*i] + st[c][2*i+1];
	}
}

void build(int n, int c, string &s) {
	build(c, s, 1, 0, n-1);
}

int query(int n, int c, int l, int r) {
	return query(c, 1, 0, n-1, l, r);
}

void update(int n, int c, int l, int r, int v) {
	return update(c, 1, 0, n-1, l, r, v);
}

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	for (int c = 0; c < 26; c++) {
		build(n, c, s);
	}

	for (int x = 0; x < q; x++) {
		int i, j, k;
		cin >> i >> j >> k;
		i--; j--;

		int ii = i;
		int jj = j;
		
		for (int c = 0; c < 26; c++) {
			int cnt = query(n, c, i, j);
			if (cnt == 0) continue;
			update(n, c, i, j, 0);
			if (k == 1) {
				update(n, c, ii, ii + cnt - 1, 1);
				ii += cnt;
			} else {
				update(n, c, jj - cnt + 1, jj, 1);
				jj -= cnt;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int c = 0; c < 26; c++) {
			if (query(n, c, i, i) == 1) {
				cout << char('a' + c);
				break;
			}
		}
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*******************************/
	solve();
	return 0;
}
