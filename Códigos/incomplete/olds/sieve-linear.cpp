/*
	Acha os números primos de 1 a n, devolve o vetor lp em que lp[i] é o menor fator primo de i
	n - inteiro positivo
*/
vector<int> sieveLinear(int n) {
	vector<int> lp(n + 1, 0);
	vector<int> pr;
	for (long long i = 2; i <= n; i++) {
		if (lp[i] == 0) {
			pr.push_back(i);
			lp[i] = i;
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
	return lp;
}