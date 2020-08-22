/*
	Devolve o resto da divisão de a por b
	a, b - inteiros
*/
long long rem(long long a, long long b) {
	return (b + (a % b)) % b;
}

/*
	Devolve os termos F_n e F_(n+1) da sequência de Fibonacci módulo m
	n - inteiro não negativo
	m - inteiro positivo
*/
pair<long long, long long> modfibRec(long long n, long long m) {
	if (n == 0)
		return {0, 1};
	long long fk, fk1;
	tie(fk, fk1) = modfibRec(n >> 1, m);
	long long f2k = (fk*rem(2*fk1 - fk, m)) % m;
	long long f2k1 = ((fk1*fk1) % m + (fk*fk) % m) % m;
	if (n & 1)
		return {f2k1, (f2k + f2k1) % m};
	return {f2k, f2k1};
}

/*
	Retorna o n-ésimo termo da sequência de Fibonacci módulo m
	n - inteiro não negativo
	m - inteiro positivo
*/
long long modfib(long long n, long long m) {
	return modfibRec(n, m).first;
}