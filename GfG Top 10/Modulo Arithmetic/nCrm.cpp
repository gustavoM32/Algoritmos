/*
    nCr % p
    Complexity: O(p ^ 2 * log (n))
*/
#include <bits/stdc++.h>
using namespace std;

#define N 10010

int nCrMod(int n, int r, int p) {
	int line[N];
	if (r > n) return 0;
	for (int i = 0; i <= n; i++) {
		line[i] = 0;
	}
	line[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = min(i, r); j > 0; j--) {
			line[j] = (line[j] + line[j-1]) % p;
		}
	}
	return line[r];
}

int nCrModLucas(int n, int r, int p) {
	if (r == 0) return 1;
	int ni = n % p;
	int ri = r % p;

	return (nCrModLucas(n/p, r/p, p) * nCrMod(ni, ri, p)) % p;
}

int main() {
    int n, r, p;
	cin >> n >> r >> p;
	cout << nCrModLucas(n, r, p) << "\n";
    return 0;
}
