/*
    Counting Sort
    Complexity: O(n + r)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010
#define MAXR 10010

void countingSort(int arr[], int n) {
    int sorted[MAXN];
    int count[MAXR];
    for (int i = 0; i < MAXR; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i < MAXR; i++) {
        count[i] += count[i - 1];
    }
    for (int i = 0; i < n; i++) {
        sorted[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }
}

int main() {
    int n;
    int arr[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    countingSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
