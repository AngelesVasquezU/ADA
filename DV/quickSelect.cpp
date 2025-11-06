#include <iostream>
#include <vector>

int medianadetres(int a, int b, int c) {
	if ((a <= c && a >= b) || (a <= b && a >= c)) {
		return a;
	}

	if ((c <= a && c >= b) || (c <= b && c >= a)) {
		return c;
	}
	else return b;
}

int particion(std::vector<int>& lista, int left, int right) {
	int iMed = (left + right) / 2;
	int pivot = medianadetres(lista[left], lista[iMed], lista[right]);
	// ordenar la lista izq menores y der mayores
	int i = left - 1, j = right + 1;
	while (true) {
		do { i++; } while (lista[i] < pivot);
		do { j--; } while (lista[j] > pivot);

		if (i >= j) return j;

		std::swap(lista[i], lista[j]);
	}
}
int encontrarMediana(std::vector<int>& lista, int left, int right, int k) {
	if (left >= right) return lista[left];
	int p = particion(lista, left, right);
	if(k <= p)
		return encontrarMediana(lista, left, p, k);
	else return encontrarMediana(lista, p + 1, right, k);
}
void imprimir(std::vector<int> lista) {
	for (auto element : lista) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> lista = { 45, 89, 72, 90, 67, 88 };
	int n = lista.size();
	int mediana = encontrarMediana(lista, 0, n - 1, n/2);
	imprimir(lista);
	std::cout << "Mediana: " << mediana << std::endl;
}
