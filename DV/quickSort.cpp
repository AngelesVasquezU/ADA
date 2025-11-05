// quickSort.cpp 

#include <iostream>
#include <vector>

//int* medianadetres(int* ini, int* med, int* fin) {
//	if ((*ini <= *fin && *ini >= *med) || (*ini <= *med && *ini >= *fin)) {
//		return ini;
//	}
//	
//	if ((*fin <= *ini && *fin >= *med) || (*fin <= *med && *fin >= *ini)) {
//		return fin;
//	}
//	else return med;
//}

int medianadetres(int a, int b, int c) {
	if ((a <= c && a >= b) || (a <= b && a >= c)) {
		return a;
	}

	if ((c <= a && c >= b) || (c <= b && c >= a)) {
		return c;
	}
	else return b;
}

int particion(std::vector<int> &lista, int left, int right) {
	int iMed = (left + right) / 2;
	int pivot = medianadetres(lista[left], lista[iMed], lista[right]);
	// ordenar la lista izq menores y der mayores
	int i = left-1, j = right+1;
	while (true) {
		do { i++; } while (lista[i] < pivot);
		do { j--; } while (lista[j] > pivot);

		if (i >= j) return j;

		std::swap(lista[i], lista[j]);
	}
}
void quickSort(std::vector<int> &lista, int left, int right) {
	if (left >= right) return;
	int p = particion(lista, left, right);
	quickSort(lista, left, p);
	quickSort(lista, p+1, right);
}
void imprimir(std::vector<int> lista) {
	for (auto element : lista) {
		std::cout << element << " ";
	}
	std::cout<<std::endl;
}

int main()
{
	std::vector<int> lista = { 42, 124, 23, 5, 89, -1, 44, 643, 34 };
	quickSort(lista, 0, lista.size()-1);
	imprimir(lista);
}
