/*
	Ways to Cover a Distance
	Complexity: O()
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010
#define ll long long

ll dp[MAXN];

ll wcd(int dist) {
	if (dp[dist] != -1) return dp[dist];
	if (dist == 0) return dp[dist] = 1;
	ll res = 0;
	for (int i = 1; i <= 3; i++) {
		if (dist >= i) {
			res += wcd(dist - i);
		}
	}
	return dp[dist] = res;
}

int main() {
	int dist;
	cin >> dist;
	memset(dp, -1, sizeof dp);
	cout << wcd(dist) << endl;
	return 0;
}
