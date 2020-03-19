/*
	Assembly Line Scheduling
	Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

#define NUM_STATIONS 10010

int dp[2][NUM_STATIONS];

int assembly(int l, int i, int n, int e[], int a[][NUM_STATIONS], int t[][NUM_STATIONS]) {
	if (dp[l][i] != -1) return dp[l][i];
	if (i == 0) return dp[l][i] = e[l] + a[l][i];

	return dp[l][i] =
		min(assembly(l, i - 1, n, e, a, t) + a[l][i],
			assembly((l + 1)%2, i - 1, n, e, a, t) + t[(l + 1)%2][i] + a[l][i]);
}

int solve(int n, int e[], int a[][NUM_STATIONS], int t[][NUM_STATIONS], int x[]) {
	return min(assembly(0, n - 1, n, e, a, t) + x[0],
			   assembly(1, n - 1, n, e, a, t) + x[1]);
}

int main() {
	int n;
	int e[2], x[2];
	int a[2][NUM_STATIONS];
	int t[2][NUM_STATIONS];
	cin >> n;
	cin >> e[0] >> e[1];
	for (int i = 0; i < n; i++) {
		cin >> a[0][i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[1][i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[0][i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[1][i];
	}
	cin >> x[0] >> x[1];
	memset(dp, -1, sizeof dp);
	cout << solve(n, e, a, t, x) << endl;
	return 0;
}
