/*
	Knapsack Problem
	Complexity: O(n * w)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
#define MAXW 1010

int dp[MAXN][MAXW];

int knapsack(int i, int weight, int n, int values[], int weights[]) {
	if (dp[i][weight] != -1) return dp[i][weight];
	if (weight == 0 || i == n) return dp[i][weight] = 0;
	if (weights[i] > weight) {
		return dp[i][weight] = knapsack(i + 1, weight, n, values, weights);
	}
	return dp[i][weight] = max(knapsack(i + 1, weight, n, values, weights),
				   values[i] + knapsack(i + 1, weight - weights[i], n, values, weights));
}

int main() {
	int n, w;
	cin >> n >> w;
	int values[MAXN], weights[MAXN];
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}
	cout << knapsack(0, w, n, values, weights) << endl;
	return 0;
}
