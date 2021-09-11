// GMD
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> inv(n+1);
    inv[1] = 1;
    cout << "1: 1\n";
    for (int i = 2; i <= n; i++) {
        inv[i] = m - ((m/i) * inv[m%i]) % m;
        cout << i << ": " << inv[i] << "\n";
    }

}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
