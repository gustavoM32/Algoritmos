/*
	Subset Sum Problem
	Complexity: O(n * sum)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int pd[MAXN][MAXN];

bool ssp(int i, int sum, int arr[], int n) {
	if (pd[i][sum] != -1) return pd[i][sum];
	if (sum == 0) return pd[i][sum] = 1;
	if (i == n) return pd[i][sum] = 0;
	if (arr[i] > sum) {
		return pd[i][sum] = ssp(i + 1, sum, arr, n);
	}
	return pd[i][sum] = ssp(i + 1, sum, arr, n) || ssp(i + 1, sum - arr[i], arr, n);
}

int main() {
	int n, sum;
	cin >> n >> sum;
	int arr[MAXN];
	for (int i = 0; i < n; i++) cin >> arr[i];
	memset(pd, -1, sizeof pd);
	cout << (ssp(0, sum, arr, n) ? "YES" : "NO") << endl;
	return 0;
}
