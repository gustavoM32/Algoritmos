/* Does that and returns that
 *
 * a -
 * b -
 * c -
 *
 * Complexity: O(n)
 */

struct Hash {
    ll power_p;
    ll hash;

    Hash(ll p, ll h) : p(p), h(h) {}
}

struct Hashing {
    ll p, m;
    ll h = 0;
    ll pow_end = 1;
    char sc = 'a';
    vector<ll> hashes;

    Hashing(ll p, ll m, string &s) : p(p), m(m) {
        for (char c : s) {
            append(c);
        }
    }

    Hash hashSubs(int i, int j) {
        ll res = hashes[j];
        if (i > 0) res = (res + (m - hashes[i-1])) % m;
        return Hash(i, res);

    }

    void append(char c) {
        h = (h + (c - sc + 1) * pow_end) % m;
        pow_end = (p * pow_end) % m;
        hashes.push_back(h);
    }
};

struct StringHashing {
    Hashing h1, h2;

    StringHashing(string &s) {
        h1 = Hashing(31, 1000000007, s);
        h2 = Hashing(29, 1000000009, s);
    }

    

}
