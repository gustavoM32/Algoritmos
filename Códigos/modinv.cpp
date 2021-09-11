/* Returns the modular multiplicative inverse of a number
 *
 * a - integer
 * m - prime module
 *
 * Complexity: O(log(m))
 */
#include "modexp.cpp"

ll modinv(ll a, ll m = MOD) {
	return modexp(a, m-2, m);
}