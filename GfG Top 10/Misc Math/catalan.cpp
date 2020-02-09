/*
    Nth Catalan
    Complexity: O(n ^ 2)
*/
#include <bits/stdc++.h>
using namespace std;

#define N 10010

int nCr(int n, int r) {
	int line[N];
	if (r > n) return 0;
	for (int i = 0; i <= n; i++) {
		line[i] = 0;
	}
	line[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = min(i, r); j > 0; j--) {
			line[j] = line[j] + line[j-1];
		}
	}
	return line[r];
}

int catalan(int n) {
	return nCr(2*n, n) / (n + 1);
}

int main() {
    int n;
	cin >> n;
	cout << catalan(n) << "\n";
    return 0;
}
