class Lazy {
    int n;
    vector<ll> st, lz;

    void build(int i, int il, int ir) {
        if (il > ir) return;

        st[i] = lz[i] = 0;

        if (il != ir) {
            int im = (il + ir) / 2;
            build(2*i, il, im);
            build(2*i + 1, im+1, ir);
        }
    }

    void push(int i, int il, int ir) {
        if (lz[i] != 0) {
            st[i] += lz[i];

            if (il != ir) {
                lz[2*i] += lz[i];
                lz[2*i+1] += lz[i];
            }

            lz[i] = 0;
        }
    }

    ll query(int i, int il, int ir, int l, int r) {
        push(i, il, ir);

        if (r < il || ir < l) return INF;

        if (l <= il && ir <= r) {
            return st[i];
        }

        int im = (il + ir) / 2;

        ll q1 = query(2*i, il, im, l, r);
        ll q2 = query(2*i+1, im+1, ir, l, r);

        return min(q1, q2);
    }

    void update(int i, int il, int ir, int l, int r, ll v) {
        push(i, il, ir);

        if (r < il || ir < l) return;

        if (l <= il && ir <= r) {
            lz[i] = v;
            push(i, il, ir);
            return;
        }

        int im = (il + ir) / 2;

        update(2*i, il, im, l, r, v);
        update(2*i+1, im+1, ir, l, r, v);
        st[i] = min(st[2*i], st[2*i+1]);
    }

    public:
    Lazy(int n) : n(n) {
        st.resize(4 * n);
        lz.resize(4 * n);
        build(1, 0, n-1);
    }

    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int l, int r, ll v) {
        return update(1, 0, n-1, l, r, v);
    }
};

