/*
	Devolve o resultado de 'a' elevado a 'b'
	a - base
	b - expoente, inteiro positivo
*/
long long binexp(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}
