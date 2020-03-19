/*
	Counting inversions using BIT
	Complexity: O(n * log(n))
*/
#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n;
int bit[N];

int getSum(int i) {
	int sum = 0;
	while (i > 0) {
		sum += bit[i];
		i -= (i & (-i));
	}
	return sum;
}

void update(int i, int x) {
	while (i <= n) {
		bit[i] += x;
		i += (i & (-i));
	}
}

void convert(int arr[]) {
	int tmp[N];
	for (int i = 0; i < n; i++) {
		tmp[i] = arr[i];
	}
	sort(tmp, tmp+n);
	for (int i = 0; i < n; i++) {
		arr[i] = lower_bound(tmp, tmp+n, arr[i]) - tmp + 1;
	}
}

int countInv(int arr[]) {
	int invCount = 0;
	convert(arr);
	for (int i = 1; i <= n; i++) {
		bit[i] = 0;
	}
	for (int i = n - 1; i >= 0; i--) {
		invCount += getSum(arr[i]-1);
		update(arr[i], 1);
	}
	return invCount;
}

int main() {
	cin >> n;
	int arr[N];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << countInv(arr) << "\n";
	return 0;
}
