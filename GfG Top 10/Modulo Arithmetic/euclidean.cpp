/*
	Euclidean Algorithm
	Complexity: O(log(min(a, b)))
*/
#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b) {
	return b == 0 ? a : mdc(b, a % b);
}

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

int main() {
	int a, b, x, y;
	cin >> a >> b;
	cout << "mdc = " << mdc(a, b) << endl;
	cout << "mdc = " << mdcext(a, b, &x, &y) << " x = " << x << " y = " << y << endl;
	return 0;
}
