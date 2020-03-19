/*
	Segment Tree
	Complexity: O(log n) for queries and updates
*/
#include <bits/stdc++.h>
using namespace std;

#define N 10010

int st[4*N];
int lazy[4*N];

int query(int i, int ns, int ne, int qs, int qe) {
	if (lazy[i] != 0) {
		st[i] += lazy[i] * (ne - ns + 1);
		if (ns != ne) {
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}
		lazy[i] = 0;
	}
	if (ne < qs || qe < ns) return 0;
	if (qs <= ns && ne <= qe) return st[i];
	int m = (ns + ne) / 2;
	return query(2*i, ns, m, qs, qe) + query(2*i+1, m+1, ne, qs, qe);
}

void updateRange(int i, int ns, int ne, int us, int ue, int x) {
	if (lazy[i] != 0) {
		st[i] += lazy[i] * (ne - ns + 1);
		if (ns != ne) {
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}
		lazy[i] = 0;
	}
	if (ue < ns || ne < us) return;
	if (us <= ns & ne <= ue) {
		st[i] += x * (ne - ns + 1);
		if (ns != ne) {
			lazy[2*i] += x;
			lazy[2*i+1] += x;
		}
		return;
	}
	int m = (ns + ne) / 2;
	updateRange(2*i, ns, m, us, ue, x);
	updateRange(2*i+1, m+1, ne, us, ue, x);
	st[i] = st[2*i] + st[2*i+1];
}

void update(int i, int ns, int ne, int p, int x) {
	if (p < ns || ne < p) return;
	if (ns == ne) {
		st[i] = x;
		return;
	}
	int m = (ns + ne) / 2;
	update(2*i, ns, m, p, x);
	update(2*i+1, m+1, ne, p, x);
	st[i] = st[2*i] + st[2*i+1];
}

void build(int i, int ns, int ne, int arr[N]) {
	if (ns == ne) {
		st[i] = arr[ns];
		lazy[i] = 0;
		return;
	}
	int m = (ns + ne) / 2;
	build(2*i, ns, m, arr);
	build(2*i+1, m+1, ne, arr);
	st[i] = st[2*i] + st[2*i+1];
}

int main() {
	int n = 9;
	int arr[] = {9, 3, 2, 1, 4, 5, 3, 2, 1};
	build(1, 0, n-1, arr);
	cout << query(1, 0, n-1, 4, 8) << endl;
	updateRange(1, 0, n-1, 3, 5, 1000);
	cout << query(1, 0, n-1, 4, 8) << endl;
	cout << query(1, 0, n-1, 1, 3) << endl;
	return 0;
}
