/*
    Binary Search
    Complexity: O(log n)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010

int bb(int arr[], int l, int r, int x) {
    if (l > r) return -1;
    int m = (l + r)/2;
    if (arr[m] == x) return m;
    if (x < arr[m]) return bb(arr, l, m - 1, x);
    return bb(arr, m + 1, r, x);
}

int main() {
    int n;
    cin >> n;
    int arr[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    cout << bb(arr, 0, n - 1, x) << endl;
    return 0;
}
