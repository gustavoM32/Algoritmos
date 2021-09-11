/*
	Vetor que diz se o i-ésimo elemento é primo ou não
*/
vector<char> isPrime;

/*
	Acha os números primos de 1 a n
	n - número inteiro positivo
*/
void sieve(int n) {
	isPrime.assign(n+1, true);
	isPrime[0] = isPrime[1] = false;
	for (long long p = 2; p * p <= n; p++) {
		if (!isPrime[p]) continue;
		for (int j = p * p; j <= n; j += p) {
			isPrime[j] = false;
		}
	} 
}