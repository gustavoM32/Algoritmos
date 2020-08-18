/*
	Devolve o MDC dos números a e b
	a, b - números naturais
*/
long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}
