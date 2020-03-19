/*
	Longest Common Subsequence
	Complexity: O(n * m)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int pd[MAXN][MAXN];

int lcs(char* a, char* b, int n, int m) {
	if (pd[n][m] != -1) return pd[n][m];
	if (m == 0 || n == 0) {
		return pd[n][m] = 0;
	}
	if (a[n-1] == b[m-1]) {
		return pd[n][m] = 1 + lcs(a, b, n - 1, m - 1);
	}
	return pd[n][m] = max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
}

int main() {
	memset(pd, -1, sizeof(pd));
	char a[MAXN], b[MAXN];
	cin >> a >> b;
	cout << lcs(a, b, strlen(a), strlen(b)) << endl;
	return 0;
}
