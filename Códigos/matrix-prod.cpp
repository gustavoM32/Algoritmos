/* Returns the product of matrixes
 *
 * a - n x m matrix
 * b - m x p matrix
 * c - output n x p matrix
 *
 * Complexity: O(nmp)
 */
void matProd(vector<vector<ll>> &a, vector<vector<ll>> &b, vector<vector<ll>> &c) {
    int n = a.size();
    int m = a[0].size();
    int p = b[0].size();
    vector<vector<ll>> res(n, vector<ll>(p, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    c = res;
}
