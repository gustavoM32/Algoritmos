/*
	Stable Marriage Problem
	Complexity: O(n^3)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

bool wPrefNew(int wPref[MAXN][MAXN], int n, int w, int oldM, int newM) {
	for (int i = 0; i < n; i++) {
		if (wPref[w][i] == newM) return true;
		if (wPref[w][i] == oldM) return false;
	}
	return false;
}

void stableMarriages(int mPref[MAXN][MAXN], int wPref[MAXN][MAXN], int n) {
	int freeCount = n;
	bool mfree[MAXN];
	int wpair[MAXN];
	for (int i = 0; i < n; i++) {
		mfree[i] = true;
		wpair[i] = -1;
	}
	while (freeCount > 0) {
		int mseek;
		for (int m = 0; m < n; m++) {
			if (mfree[m]) {
				mseek = m;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			int w = mPref[mseek][i];
			if (wpair[w] == -1) {
				wpair[w] = mseek;
				mfree[mseek] = false;
				freeCount--;
				break;
			} else {
				if (wPrefNew(wPref, n, w, wpair[w], mseek)) {
					mfree[wpair[w]] = true;
					mfree[mseek] = false;
					wpair[w] = mseek;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << i + 4 << " " << wpair[i] << endl;
	}
}

int main() {
	int n;
	cin >> n;
	int mPref[MAXN][MAXN];
	int wPref[MAXN][MAXN];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mPref[i][j];
			mPref[i][j] -= n;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> wPref[i][j];
		}
	}
	stableMarriages(mPref, wPref, n);

	return 0;
}
