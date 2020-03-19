/*
	Rabin-Karp Algorithm fpr Pattern Searching
	Complexity: O(n * m) avg O(n + m)
*/
#include <bits/stdc++.h>
using namespace std;

#define C 256
#define P 101

string pat, txt;

void search() {
	int path = 0;
	int txth = 0;
	int h = 1;
	for (int i = 0; i < pat.size() - 1; i++) {
		h = (h * C) % P;
	}

	for (int i = 0; i < pat.size(); i++) {
		path = (path * C + pat[i]) % P;
		txth = (txth * C + txt[i]) % P;
	}

	for (int i = 0; i <= txt.size() - pat.size(); i++) {
		if (path == txth) {
			int j;
			for (j = 0; j < pat.size(); j++) {
				if (txt[i+j] != pat[j]) break;
			}
			if (j == pat.size()) cout << "Pattern found at " << i << "\n";
		}
		if (i < txt.size() - pat.size()) {
			txth = (C*(txth - txt[i] * h) + txt[i+pat.size()]) % P;
			if (txth < 0) txth = txth + P;
		}
	}
}

int main() {
	cin >> txt >> pat;
	search();
	return 0;
}
