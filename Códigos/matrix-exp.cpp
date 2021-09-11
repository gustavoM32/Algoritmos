/* Returns the matrix exponentiation
 *
 * base - d x d matrix
 * n - non-negative integer for the exponent
 * res - output param
 *
 * Complexity: O(d^2 * log(n))
 */
#include "matrix-prod.cpp"

void matExp(vector<vector<ll>> &base, ll n, vector<vector<ll>> &res) {
    int d = base.size();
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            res[i][j] = ll(i == j);
        }
    }
    while (n > 0) {
        if (n % 2 == 1) matProd(res, base, res);
        matProd(base, base, base);
        n /= 2;
    }
}
