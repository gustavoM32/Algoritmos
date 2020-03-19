/*
	Binary Search
	Complexity: O(n * log(n))
	Nome: "Binary Search"
	Atalho: "bSearch"
	Descrição: "Encontra o índice de um elemento em um vetor."
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

/*
	Devolve algum índice do vetor 'arr' cujo elemento é 'x' ou
	-1 se não encontrar.
	arr - vetor ordenado
	x - valor que se procura
	s - índice de início da busca
	e - índice de término da busca
*/
//[
int bSearch(int arr[], int x, int s, int e) {
	if (s > e) return -1;
	int m = (s + e) / 2;
	if (arr[m] == x) return m;
	if (arr[m] > x) return bs(arr, x, s, m - 1);
	return bs(arr, x, m + 1, e);
}
//]

/*
	Devolve o menor índice do vetor 'arr' cujo elemento é 'x' ou
	-1 se não encontrar.
	arr - vetor ordenado
	x - valor que se procura
	s - índice de início da busca
	e - índice de término da busca
*/
int fbs(int arr[], int x, int s, int e) {
	if (s > e) return -1;
	int m = (s + e) / 2;
	if (arr[m] == x)  {
		if (s == e) return m;
		return fbs(arr, x, s, m);
	}
	if (arr[m] > x) return fbs(arr, x, s, m - 1);
	return fbs(arr, x, m + 1, e);
}

/*
	Devolve o maior índice do vetor 'arr' cujo elemento é 'x' ou
	-1 se não encontrar.
	arr - vetor ordenado
	x - valor que se procura
	s - índice de início da busca
	e - índice de término da busca
*/
int lbs(int arr[], int x, int s, int e) {
	if (s > e) return -1;
	int m = (s + e + 1) / 2;
	if (arr[m] == x)  {
		if (s == e) return m;
		return lbs(arr, x, m, e);
	}
	if (arr[m] > x) return lbs(arr, x, s, m - 1);
	return lbs(arr, x, m + 1, e);
}

int main() {
	int n;
	cin >> n;
	int arr[MAXN];
	for (int i = 0; i < n; i++) {
		arr[i] = 1 + rand() % 4;
	}
	sort(arr, arr+n);
	int x;
	while (1) {
		cin >> x;
		cout << endl;
		for (int i = 0; i < n; i++) {
			printf("%2d|", arr[i]);
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			printf("%2d|", i);
		}
		cout << endl << endl;
		cout << "normal bb: " << bSearch(arr, x, 0, n - 1) << endl;
		cout << "first bb: " << fbs(arr, x, 0, n - 1) << endl;
		cout << "last bb: " << lbs(arr, x, 0, n - 1) << endl;
		cout << endl;
	}

	return 0;
}
