/*
	Prime Factorisation
	Complexity: O(sqrt(n))
*/
#include <bits/stdc++.h>
using namespace std;

void showPrimeFactors(int n) {
	while (n % 2 == 0) {
		cout << 2 << " ";
		n /= 2;
	}

	for (int i = 3; i*i <= n; i += 2) {
		while (n % i == 0) {
			cout << i << " ";
			n /= i;
		}
	}

	if (n > 1) {
		cout << n;
	}
	
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	showPrimeFactors(n);
	return 0;
}
