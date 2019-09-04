/*
    Optimal Strategy for a Game
    Complexity: O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int dp[MAXN][MAXN];

int osg(int i, int j, int arr[]) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == j) return dp[i][j] = arr[i];
    if (i + 1 == j) return dp[i][j] = max(arr[i], arr[j]);
    return dp[i][j] = max(arr[i] + min(osg(i + 2, j, arr), osg(i + 1, j - 1, arr)),
                          arr[j] + min(osg(i + 1, j - 1, arr), osg(i, j - 2, arr)));
}

int main() {
    int n;
    cin >> n;
    int arr[MAXN];
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << osg(0, n - 1, arr) << endl;
    return 0;
}
