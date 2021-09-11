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

/*
	Devolve true se n é composto
	n - número inteiro positivo
	a - base fermat
	d, s - s é o maior inteiro tal que n = 2^s*d
*/
bool check_composite(long long n, long long a, long long d, int s) {
	long long x = modexp(a, d, n);
	if (x == 1 || x == n - 1) return false;
	for (int i = 1; i < s; i++) {
		x = (x * x) % n;
		if (x == n - 1) return false;
	}
	return true;
}

/*
	Devolve true se n é primo
	n - inteiro positivo
*/
bool millerRabin(long long n) {
	if (n < 2) return false;

	int r = 0;
	long long d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		r++;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a) return true;
		if (check_composite(n, a, d, r)) return false;
	}
	return true;
} 
