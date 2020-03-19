/*
	Logarithmic exponentiation
	Complexity: O(log e)
*/
#include <bits/stdc++.h>
using namespace std;

int pot(int b, int e) {
	int res = 1;
	while (e > 0) {
		if (e % 2 == 1) res *= b;
		b *= b;
		e /= 2;
	}
	return res;
}

int main() {
	int b, e;
	cin >> b >> e;
	cout << pot(b, e) << endl;
	return 0;
}
