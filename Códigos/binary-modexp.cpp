/*
	Devolve o resultado de 'a' elevado a 'b'
	a - base
	b - expoente, inteiro positivo
*/
long long modexp(long long a, long long b, long long m) {
	long long res = 1;
	a %= m;
	while (b > 0) {
		if (b & 1) res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}
