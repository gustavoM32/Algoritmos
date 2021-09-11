// GMD
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007

class SegTree {
    int n;
    vector<ll> st;

    void build(vector<ll> &v) {
        for (int i = n-1; i >= 1; i--) {
            st[i] = st[i << 1] + st[i << 1 | 1];
        }
    }

    public:

    SegTree(int n) : n(n) {
        st.assign(2*n, 0);
    }

    SegTree(vector<ll> &v) : SegTree(v.size()) {
        for (int i = 0; i < n; i++) {
            st[n + i] = v[i];
        }

        build(v);
    }

    void update(int i, ll x) {
        i += n;
        st[i] = x;
        while (i > 1) {
            st[i >> 1] = st[i] + st[i ^ 1];
            i >>= 1;
        }
    }

    ll query(int l, int r) {
        ll res = 0;
        l += n;
        r += n+1;
        while (l < r) {
            if (l & 1) res += st[l++];
            if (r & 1) res += st[--r];

            l >>= 1;
            r >>= 1;
        }

        return res;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> resmin(n);
    vector<ll> res(n);
    vector<int> last(n);
    SegTree st(n + m);

    for (int i = n-1; i >= 0; i--) {
        resmin[i] = i+1;
        res[i] = i+1;
        last[i] = n - 1 - i;
        st.update(n - 1 - i, 1);
    }

    for (int i = n; i < n + m; i++) {
        int x;
        cin >> x;
        x--;
        resmin[x] = 1;
        res[x] = max(res[x], st.query(last[x], i-1));
        st.update(last[x], 0);
        last[x] = i;
        st.update(i, 1);
    }

    for (int i = 0; i < n; i++) {
        res[i] = max(res[i], st.query(last[i], n+m-1));
    }

    for (int i = 0; i < n; i++) {
        cout << resmin[i] << " " << res[i] << "\n";
    }
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}

