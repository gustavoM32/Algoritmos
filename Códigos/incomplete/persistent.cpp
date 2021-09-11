// GMD
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define INF 1000000007
#define MOD 1000000007

struct Node {
    ll value;
    int left, right;

    Node(ll value) : value(value), l(nullptr), r(nullptr) {}
    Node(Vertex *l, Vertex *r) : value(0), l(l), r(r) {
        if (l) value += l->value;
        if (r) value += r->value;
    }
}

class PersistentST {
    int n;

    Node *build(int l, int r) {
        if (l == r) return new Node(0);
        int m = (l + r) / 2;
        return new Node(build(l, m), build(m+1, r));
    }

    ll query(Node *node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return node->sum;
        if (r < ql || qr < l) return 0;
        int m = (l + r) / 2;
        return query(node->left, l, m, ql, qr)
            + query(node->right, m+1, r, ql, qr;
    }

    Node *update(Node *node, int l, int r, int p, ll x) {
        if (l == r) return new Node(x);
        int m = (l + r) / 2;
        if (x <= m) {
            return update(node->left, l, m, p, x);
        }
        return update(node->right, m+1, r, p, x);
    }

    public:
    PersistentST(int n) {
        build(0, n-1);
    }

    ll query(Node *node, int ql, int qr) {
        return query(node, 0, n-1, ql, qr);
    }

    ll update(Node *node, int p, ll x) {
        return update(node, 0, n-1, p, x);
    }
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
