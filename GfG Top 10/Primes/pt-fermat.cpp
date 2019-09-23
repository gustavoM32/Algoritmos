/*
    Primality Test - Fermat Method
    Complexity: O()
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << (isPrime(n) ? "YES" : "NO") << endl;
    return 0;
}
