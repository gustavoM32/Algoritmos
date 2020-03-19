/*
	Chinese Remainder Theorem
	Complexity: O(n*log(max(mods[])))
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 110

int mdcext(int a, int b, int *x, int *y) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	int x1, y1;
	int mdc = mdcext(b, a % b, &x1, &y1);
	*x = y1;
	*y = x1 - (a / b) * y1;
	return mdc;
}

int multinv(int a, int m) {
	int x, y;
	if (mdcext(a, m, &x, &y) != 1) return -1;
	return (m + x) % m;
}

int crt(int mods[], int rems[], int n) {
	int res = 0;
	int prod = 1;
	for (int i = 0; i < n; i++) {
		prod *= mods[i];
	}
	for (int i = 0; i < n; i++) {
		int pp = prod / mods[i];
		res += rems[i] * multinv(pp, mods[i]) * pp;
	}
	return res % prod;
}

int main() {
	int n;
	cin >> n;
	int mods[MAXN], rems[MAXN];
	for (int i = 0; i < n; i++) {
		cin >> mods[i] >> rems[i];
	}
	cout << crt(mods, rems, n) << endl;
	return 0;
}
