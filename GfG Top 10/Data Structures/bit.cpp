/*
	Binary Indexed Tree
	Complexity: O(log n) for update and getSum operations
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n;
int BITree[MAXN];

int getSum(int x) {
	int res = 0;
	x++;
	while (x > 0) {
		res += BITree[x];
		x = x - (x & (-x));
	}
	return res;
}

void update(int i, int val) {
	i++;
	while (i <= n) {
		BITree[i] += val;
		i = i + (i & (-i));
	}
}

int startTree(int arr[], int n) {
	for (int i = 1; i <= n; i++) BITree[i] = 0;
	for (int i = 0; i < n; i++) update(i, arr[i]);
	return n;
}

int main() {
	int arr[MAXN];
	int m;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	startTree(arr, n);
	cin >> m;
	while (m--) {
		char op;
		int a, b;
		cin >> op;
		if (op == 'g') {
			cin >> a;
			cout << getSum(a) << endl;
		} else if (op == 'u') {
			cin >> a >> b;
			update(a, b);
		}
	}
	return 0;
}
