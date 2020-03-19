/*
	Quick Sort
	Complexity: O(n^2) avg n*log(n)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int s = low;
	for (int i = low; i < high; i++) {
		if (arr[i] < pivot) {
			swap(&(arr[i]), &(arr[s]));
			s++;
		}
	}
	swap(&(arr[s]), &(arr[high]));
	return s;
}

void quickSort(int arr[], int low, int high) {
	int part;
	if (low < high) {
		part = partition(arr, low, high);
		quickSort(arr, low, part-1);
		quickSort(arr, part+1, high);
	}
}

int main() {
	int n;
	cin >> n;
	int arr[MAXN];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
