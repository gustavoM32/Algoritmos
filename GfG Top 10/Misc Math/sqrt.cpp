/*
	Integer square root
	Complexity: O(log n)
*/
#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
	if (n == 0 || n == 1) return n;
	int s = 0, e = n, m;
	while (s <= e) {
		m = (s + e + 1) / 2;
		if (s == e) return m;
		if (m * m <= n) s = m;
		else e = m - 1;
	}
	return m;
}

int main() {
	int n;
	cin >> n;
	cout << floorSqrt(n) << "\n";
	return 0;
}
