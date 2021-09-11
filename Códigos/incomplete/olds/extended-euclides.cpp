/*
	Devolve o MDC dos números a e b e os coeficientes do Algoritmo de Euclides Estendido
	a, b - números inteiros
	x, y - coeficientes, vale que ax + by = mdc(a, b)
*/
long long gcdExt(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long x1, y1;
	long long res = gcdExt(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return res;
}
