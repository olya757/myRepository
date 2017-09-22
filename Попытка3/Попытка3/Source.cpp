/*Найти медиану графа, то есть найти такую вершину графа, 
суммарное расстояние от которой до всех остальных вершин является наименьшим.*/
#include <iostream>
#include <vector>

using namespace std;


int main() {
	
	/*Создание динамического массива*/
	int n;
	cout << "Введите количество вершин" << endl;
	cin >> n;
	int **Matr = new int*[n];
	for (int i = 0; i < n; i++) {
		Matr[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Matr[i][j] = 0;
		}
	}



	/*Удаление массива из памяти*/
	for (int i = 0; i < n; i++) {
		delete[] Matr[i];
	}
	
	return 0;
}