/*
    Binary Search
    Complexity: O(n * log(n))
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
int bs(int arr[], int x, int s, int e) {
    if (s > e) return -1;
    int m = (s + e) / 2;
    if (arr[m] == x) return m;
    else if (arr[m] > x) return bb(arr, x, s, m - 1);
    else return bb(arr, x, m + 1, e);
}

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
        else return fbb(arr, x, s, m);
    }
    else if (arr[m] > x) return fbb(arr, x, s, m - 1);
    else return fbb(arr, x, m + 1, e);
}

/*
    Devolve o menor índice do vetor 'arr' cujo elemento é 'x' ou
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
        else return lbb(arr, x, m, e);
    }
    else if (arr[m] > x) return lbb(arr, x, s, m - 1);
    else return lbb(arr, x, m + 1, e);
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%2d|", arr[i]);
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        printf("%2d|", i);
    }
    cout << endl << endl;
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
        printArr(arr, n);
        cout << "normal bb: " << bb(arr, x, 0, n - 1) << endl;
        cout << "first bb: " << fbb(arr, x, 0, n - 1) << endl;
        cout << "last bb: " << lbb(arr, x, 0, n - 1) << endl;
        cout << endl;
    }

    return 0;
}
