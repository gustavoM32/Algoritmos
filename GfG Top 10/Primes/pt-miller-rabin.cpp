/*
	Primality Test - Miller Rabin Method
	Complexity: O(k * log(n) ^ 3)
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

bool millerTest(int d, int n) {
	int a = 2 + rand() % (n - 4);
	int x = modexp(a, d, n);
	if (x == 1 || x == n - 1) return true;
	while (d != n - 1) {
		x = (x * x) % n;
		d *= 2;
		if (x == 1) return false;
		if (x == n - 1) return true;
	}
	return false;
}

bool isPrime(int n, int k) {
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;
	int d = n - 1;
	while (d % 2 == 0) d /= 2;
	for (int i = 0; i < k; i++) {
		if (!millerTest(d, n)) return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (isPrime(n, 10000)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
