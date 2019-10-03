/*
    Matrix Rank
    Complexity: O(max(r, c) ^ 3)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
#define EPSILON 1e-10

void swapRows(double mat[MAXN][MAXN], int r1, int r2, int c) {
    int aux;
    for (int i = 0; i < c; i++) {
        aux = mat[r1][i];
        mat[r1][i] = mat[r2][i];
        mat[r2][i] = aux;
    }
}

int calcRank(double mat[MAXN][MAXN], int r, int c) {
    int rank = 0;
    int col = 0;
    for (int i = 0; i < r && col < c; i++, col++) {
        double pivot = mat[i][col];
        if (abs(pivot) < EPSILON) {
            for (int j = i + 1; j < r; j++) {
                if (abs(mat[j][col]) >= EPSILON) {
                    pivot = mat[j][col];
                    swapRows(mat, i, j, c);
                    break;
                }
            }
            if (abs(pivot) < EPSILON) {
                i--;
                continue;
            }
        }
        rank++;
        for (int j = i + 1; j < r; j++) {
            double factor = mat[j][col] / pivot;
            for (int k = col; k < c; k++) {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }
    return rank;
}

int main() {
    double mat[MAXN][MAXN];
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    cout << calcRank(mat, r, c) << endl;
    return 0;
}
