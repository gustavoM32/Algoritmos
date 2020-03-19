/*
	Counting inversions
	Complexity: O(n * log(n))
*/
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int countInv(vector<int> &v) {
	if (v.size() <= 1) return 0;
	int inv = 0;
	vector<int> l;
	vector<int> r;
	int m = v.size()/2;
	for (int i = 0; i < m; i++) {
		l.push_back(v[i]);
	}
	for (int i = m; i < v.size(); i++) {
		r.push_back(v[i]);
	}
	inv += countInv(l);
	inv += countInv(r);
	l.push_back(INF);
	r.push_back(INF);
	int il = 0, ir = 0;
	for (int i = 0; i < v.size(); i++){
		if (l[il] <= r[ir]) {
			v[i] = l[il++];
		} else {
			inv += m - il;
			v[i] = r[ir++];
		}
	}
	return inv;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	int el;
	for (int i = 0; i < n; i++) {
		cin >> el;
		arr.push_back(el);
	}
	cout << countInv(arr) << "\n";
	return 0;
}
