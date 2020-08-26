/*
	Acha os números primos de L a R
	L, R - números inteiros positivos, L <= R
*/
vector<bool> sieveRange(long long L, long long R) {
	vector<bool> isPrime(R - L + 1, true);
	long long sqrtR = sqrt(R);
	for (long long i = 2; i <= sqrtR; i++) {
		for (long long j = max(i, (L + i - 1) / i) * i; j <= R; j += i) {
			isPrime[j - L] = false;
		}
	}
	if (L == 1) isPrime[0] = false;
	return isPrime;
}