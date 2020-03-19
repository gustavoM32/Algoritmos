/*
	Primality Test - Fermat Method
	Complexity: O(k * log(n))
*/
#include <bits/stdc++.h>
using namespace std;

long long modexp(long long a, long long x, long long m) {
	long long res = 1;
	a = a % m;
	while (x > 0) {
		if (x % 2) {
			res = (res * a) % m;
		}
		x /= 2;
		a = (a * a) % m;
	}
	return res;
}

long long mdc(long long a, long long b) {
	return b == 0 ? a : mdc(b, a % b);
}

bool isPrime(long long n, int k) {

	if (n <= 1 || n == 4) return false;
	if (n <= 5) return true;

	for (int i = 0; i < k; i++) {
		long long a = 2 + rand() % (n - 4);

		if (mdc(a, n) != 1) return false;
		if (modexp(a, n-1, n) != 1) return false;
	}
	return true;
}

int main() {
	long long t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (isPrime(n, 10000)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
