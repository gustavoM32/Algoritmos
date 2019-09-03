/*
    Sieve of Eratosthenes
    Complexity: O(n * log(log(n)))
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000010

int primes[MAXN];

void sieve(int n) {
    for (int p = 2; p*p <= n; p++) {
        if (primes[p] == false) continue;
        for (int i = p*p; i <= n; i += p) {
            primes[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        primes[i] = true;
    }
    sieve(n);
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
