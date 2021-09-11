#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007

void man(string &s, vector<int> &d, bool even) {
	int n = s.size();
	int l = 0, r = -1;
	for (int i = 0; i < n; i++) {
		int k = (i > r) ? !even : min(d[l + r - i + even], r - i + 1);
		while (0 <= i - k - even && i + k < n && s[i - k - even] == s[i + k]) {
			k++;
		}
		d[i] = k--;
		if (i + k > r) {
			l = i - k - even;
			r = i + k;
		}
	}
}

void solve() {
	int k;
	cin >> k;
	string s;
	cin >> s;
	int n = s.size();
	vector<int> d(n);
	set<int> is;
	man(s, d, k % 2 == 0);
	for (int i = 0; i < n; i++) {
		if (d[i] >= (k + 1) / 2) {
			is.insert(i - (k + 1) / 2);
		}
	}
	cout << is.size() << endl;
}

int main() {
	FASTIO;
	solve();
	return 0;
}
