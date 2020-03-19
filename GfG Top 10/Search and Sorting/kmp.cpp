/*
	KMP Pattern Searching
	Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

#define N 10010

int lps[N];
string txt, pat;

void prep() {
	int i = 1, j = 0;
	lps[0] = 0;
	while (i < pat.size()) {
		if (pat[i] == pat[j]) {
			lps[i] = ++j;
			i++;
		} else if (j == 0) {
			lps[i] = 0;
			i++;
		} else {
			j = lps[j-1];
		}
	}
}

void kmp() {
	prep();
	int i = 0, j = 0;
	while (i < txt.size()) {
		if (txt[i] == pat[j]) {
			i++;
			j++;
		}

		if (j == pat.size()) {
			cout << "Found pattern at index " << i - j << "\n";
			j = lps[j - 1];
		} else if (i < txt.size() && txt[i] != pat[j]) {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				i++;
			}
		}
	}
}

int main() {
	cin >> txt >> pat;
	kmp();
	return 0;
}
