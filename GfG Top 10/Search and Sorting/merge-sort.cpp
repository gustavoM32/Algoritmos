/*
	Merge Sort
	Complexity: O(n * log(n))
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

void mergeSort(int arr[], int l, int r) {
	if (l < r) return;
	int m = (l + r)/2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);

	int arr1[(MAXN+1)/2];
	int arr2[(MAXN+1)/2];
	int i1 = 0;
	int i2 = 0;
	int sz1 = m - l + 1;
	int sz2 = r - m;
	int cur = 0;
	for (int i = 0; i < sz1; i++) {
		arr1[i] = arr[l + i];
	}
	for (int i = 0; i < sz2; i++) {
		arr2[i] = arr[m + 1 + i];
	}

	while (i1 < sz1 && i2 < sz2) {
		if (arr1[i1] <= arr2[i2]) {
			arr[cur] = arr1[i1++];
		} else {
			arr[cur] = arr2[i2++];
		}
		cur++;
	}

	while (i1 < sz1) {
		arr[cur++] = arr1[i1++];
	}

	while (i2 < sz2) {
		arr[cur++] = arr2[i2++];
	}
}

int main() {
	int n;
	cin >> n;
	int arr[MAXN];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
