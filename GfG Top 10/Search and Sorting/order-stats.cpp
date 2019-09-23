/*
    Order Statistics
    Complexity: O(n^2) avg n;
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int s = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < pivot) {
            swap(&(arr[i]), &(arr[s]));
            s++;
        }
    }
    swap(&(arr[r]), &(arr[s]));
    return s;
}

int randomPartition(int arr[], int l, int r) {
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&(arr[r]), &(arr[l + pivot]));
    return partition(arr, l, r);
}

int getKthElement(int arr[], int l, int r, int k) {
    if (l > r) return INT_MAX;
    int pivot = randomPartition(arr, l, r);
    if (pivot + 1 == k) return arr[pivot];
    if (pivot + 1 > k) return getKthElement(arr, l, pivot - 1, k);
    return getKthElement(arr, pivot + 1, r, k);
}

int main() {
    int n;
    cin >> n;
    int arr[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << getKthElement(arr, 0, n - 1, k) << endl;
    return 0;
}
