/*
	Segmented Sieve
	Complexity: O(n * log(log(n)))
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

void sieve(int n, vector<int> &primes) {
	int firstPrimes[MAXN];
	for (int i = 2; i <= n; i++) {
		firstPrimes[i] = true;
	}
	for (int p = 2; p*p <= n; p++) {
		if (firstPrimes[p] == false) continue;
		for (int i = p*p; i <= n; i += p) {
			firstPrimes[i] = false;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (firstPrimes[i]) {
			primes.push_back(i);
			cout << i << " ";
		}
	}
}

void segSieve(int n) {
	vector<int> primes;
	int limit = floor(sqrt(n)) + 1;
	sieve(limit, primes);

	int low = limit;
	int high = 2*limit;

	int segPrimes[MAXN];

	while (low <= n) {
		if (high > n) {
			high = n;
		}

		for (int i = 0; i < high - low; i++) {
			segPrimes[i] = true;
		}
		for (int i = 0; i < primes.size(); i++) {
			int p = primes[i];
			int firstMul = floor(low/p) * p;
			if (firstMul < low) firstMul += p;
			for (int j = firstMul; j < high; j += p) {
				segPrimes[j - low] = false;
			}
		}

		for (int i = low; i < high; i++) {
			if (segPrimes[i - low]) {
				cout << i << " ";
			}
		}

		low += limit;
		high += limit;
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	segSieve(n);
	return 0;
}
