/*
	Merge Sort
	Dado un arreglo de numeros enteros A = [a1, a2, a3, ..] utiliza 
	el algoritmo Merge Sort para ordenar
	1. Los numeros pares en orden ascendente
	2. Los numeros impares en orden descendente

	Luego se combinan los resultados de tal forma que queden primero
	los números pares y luego los impares.
	Entrada: A = [38, 27, 43, 3, 9, 82, 10]
	Salida: A = [10, 38, 82, 43, 27, 9, 3]
*/

#include <iostream>
#include <vector>

using namespace std;

bool comp(int a, int b) {
	if (a % 2 == 0 && !(b%2==0)) return 1;
	if (b % 2 == 0 && !(a % 2 == 0)) return 0;
	if (b % 2 == 0 && a % 2 == 0) return a<b;
	return b < a;
}

void merge(vector<int> &A, int left, int mid, int right) {
	vector<int> result;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right) {
		if (comp(A[i], A[j])) result.push_back(A[i++]);
		else result.push_back(A[j++]);
	}
	while (i <= mid) result.push_back(A[i++]);
	while (j <= right) result.push_back(A[j++]);

	//Copiamos al arreglo original
	for (int i = 0; i < result.size(); i++) {
		A[i+left] = result[i];
	}

}

void mergeSort(vector<int> &A, int left, int right) {
	if (A.empty()) return;
	if (left == right) return;
	int mid = (left + right) / 2;
	mergeSort(A, left, mid);
	mergeSort(A, mid + 1, right);
	merge(A,left, mid, right);
}

void imprimir(vector<int>& A) {
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
int main()
{
	vector<int> A = { 38, 27, 43, 3, 9, 82, 10 };
	mergeSort(A, 0, A.size() - 1);
	imprimir(A);
}
