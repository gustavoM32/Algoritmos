// GMD
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007
#define N 120

vector<pair<int, ll>> adjs[N];
int n;

ll dij(int r, int g) {
    set<pair<ll, int>> s;
    vector<ll> dist(n, -1);
    s.insert({0, r});
    while (!s.empty()) {
        int vi = (*s.begin()).second;
        ll vw = (*s.begin()).first;
        s.erase(s.begin());
        if (dist[vi] != -1) continue;
        if (vi == g) return vw;
        dist[vi] = vw;
        for (auto p : adjs[vi]) {
            int ai = p.first;
            ll aw = p.second;
            if (dist[ai] != -1) continue;
            s.insert({vw + aw, ai});
        }
    }
    return -1;
}

void solve() {
    int l, q;
    cin >> n >> l >> q;
    for (int i = 0; i < l; i++) {
        int a, b;
        ll t;
        cin >> a >> b >> t;
        adjs[a-1].push_back({b-1, t});
        adjs[b-1].push_back({a-1, t});
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << dij(a-1, b-1) << "\n";
    }
}

int main() {
	FASTIO;
	//int tst; cin >> tst; while (tst--)
	solve();
	return 0;
}
