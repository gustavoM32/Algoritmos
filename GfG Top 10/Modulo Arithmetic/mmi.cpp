/*
	Modular multiplicative inverse
	Complexity: O(log(m))
*/
#include <bits/stdc++.h>
using namespace std;

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

int main() {
	int a, m;
	cin >> a >> m;
	cout << multinv(a, m) << endl;

	return 0;
}
