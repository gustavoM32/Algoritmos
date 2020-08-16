/*
	Devolve algum índice do vetor 'arr' cujo elemento é 'x' ou
	-1 se não encontrar.
	arr - vetor ordenado
	x - valor que se procura
	s - índice de início da busca
	e - índice de término da busca
*/
int bSearch(int arr[], int x, int s, int e) {
	if (s > e) return -1;
	int m = (s + e) / 2;
	if (arr[m] == x) return m;
	if (arr[m] > x) return bs(arr, x, s, m - 1);
	return bs(arr, x, m + 1, e);
}
