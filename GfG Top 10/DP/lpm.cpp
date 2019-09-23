/*
    Longest Path in a Matrix
    Complexity: O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int dp[MAXN][MAXN];

int lpmUtil(int i, int j, int mat[][MAXN], int n) {
    if (dp[i][j] != -1) return dp[i][j];

    int u = 0, d = 0, l = 0, r = 0;

    if (0 < i) {
        if (mat[i][j] + 1 == mat[i-1][j])
            u = lpmUtil(i-1, j, mat, n);
    }
    if (i < n - 1) {
        if (mat[i][j] + 1 == mat[i+1][j])
            d = lpmUtil(i+1, j, mat, n);
    }
    if (0 < j) {
        if (mat[i][j] + 1 == mat[i][j-1])
            l = lpmUtil(i, j-1, mat, n);
    }
    if (j < n - 1) {
        if (mat[i][j] + 1 == mat[i][j+1])
            r = lpmUtil(i, j+1, mat, n);
    }
    return dp[i][j] = 1 + max(u, max(d, max(l, r)));
}

int lpm(int mat[][MAXN], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, lpmUtil(i, j, mat, n));
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int matrix[MAXN][MAXN];
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << lpm(matrix, n) << endl;
    return 0;
}
