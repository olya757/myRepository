/*����� ������� �����, �� ���� ����� ����� ������� �����, 
��������� ���������� �� ������� �� ���� ��������� ������ �������� ����������.*/
#include <iostream>
#include <vector>

using namespace std;


int main() {
	
	/*�������� ������������� �������*/
	int n;
	cout << "������� ���������� ������" << endl;
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



	/*�������� ������� �� ������*/
	for (int i = 0; i < n; i++) {
		delete[] Matr[i];
	}
	
	return 0;
}