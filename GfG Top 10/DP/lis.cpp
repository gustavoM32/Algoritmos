/*
	Longest Increasing Subsequence
	Complexity: O(n * n)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

int pd[MAXN];

int lisUtil(int arr[], int n, int* max_ref) {
	if (pd[n] != -1) return pd[n];
	if (n == 1) return pd[n] = 1;

	int res, max_here = 1;
	for (int i = 1; i < n; i++) {
		res = lisUtil(arr, i, max_ref);
		if (arr[i - 1] < arr[n - 1] && res + 1 > max_here) {
			max_here = res + 1;
		}
	}
	*max_ref = max(*max_ref, max_here);
	return pd[n] = max_here;
}

int lis(int arr[], int n) {
	int max = 1;
	lisUtil(arr, n, &max);
	return max;
}

int main() {
	int arr[MAXN];
	int n;
	memset(pd, -1, sizeof pd);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << lis(arr, n) << endl;
	return 0;
}
