#include <iostream>
#include <vector>
using namespace std;

void imprimir(vector<int> list) {
	for (auto element : list) {
		cout << element << " ";
	}
	cout << endl;
}

void merge(vector<int>& list, int left, int mid, int right) {
	vector<int> result;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right) {
		if (list[i] < list[j]) result.push_back(list[i++]);
		else result.push_back(list[j++]);
	}

	while (i <= mid) { result.push_back(list[i++]); }
	while (j <= right) { result.push_back(list[j++]); }
	
	for (int k = 0; k < result.size(); k++) {
		list[k + left] = result[k];
	}
	imprimir(list);
}
void mergeSort(vector<int>& list, int left, int right) {
	if (list.empty()) return;
	if (left == right) return;
	int mid = (left + right) / 2;
	mergeSort(list, left, mid);
	mergeSort(list, mid + 1, right);
	merge(list, left, mid, right);
}

int main()
{
	vector<int> list = { 87, 12, 94, 32, 12, 54, 1, 0, 3, 3, 88, 77, -4, 6};
	mergeSort(list, 0, list.size()-1);
	imprimir(list);
}
