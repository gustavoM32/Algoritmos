/*
    Edit Distance
    Complexity: O(n * m)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int dp[MAXN][MAXN];

int editDist(int n, int m, char a[], char b[]) {
    if (dp[n][m] != -1) return dp[n][m];
    if (n == 0) return dp[n][m] = m;
    if (m == 0) return dp[n][m] = n;
    if (a[n - 1] == b[m - 1]) {
        return dp[n][m] = editDist(n - 1, m - 1, a, b);
    }
    return dp[n][m] = 1 + min(editDist(n, m - 1, a, b),
                          min(editDist(n - 1, m - 1, a, b),
                              editDist(n - 1, m, a, b)));
}

int main() {
    int n, m;
    cin >> n >> m;
    char a[MAXN], b[MAXN];
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << editDist(n, m, a, b) << endl;
    return 0;
}
