/*
    Minimum Partition
    Complexity: O(n * sum)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int dp[MAXN][MAXN];

int minPart(int i, int setSum, int arr[], int n, int maxSum) {
    if (dp[i][setSum] != -1) return dp[i][setSum];
    if (i == n) return dp[i][setSum] = abs(maxSum - 2*setSum);
    return dp[i][setSum] = min(minPart(i+1, setSum, arr, n, maxSum),
                               minPart(i+1, setSum + arr[i], arr, n, maxSum));
}

int main() {
    int n;
    int sum = 0;
    int arr[MAXN];
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << minPart(0, 0, arr, n, sum) << endl;
    return 0;
}
