/*����� ������� �����, �� ���� ����� ����� ������� �����, 
��������� ���������� �� ������� �� ���� ��������� ������ �������� ����������.*/
#include <iostream>


using namespace std;

const int maxPath = 100000;


bool CheckTop(int **Matr, int Num, int n, int sum=0) {
	//���������� ��������� ��������
	/*�������� ������� �������� �����*/
	int *ShortPath = new int[n];
	/*�������� ������� ���������� ������*/
	int *Visited = new int[n];
	//��������� ������� ���������� ������ � �������� �����
	int i;
	for (i = 0; i < n; i++) {
		ShortPath[i] = maxPath;
		Visited[i] = 0; //0 - �� ��������, 1 - ��������
	}
	ShortPath[Num] = 0; //�������� ���� �� �������� ������� - 0
	
	int top = Num; //top - ������� �������

	do
	{
		i = 0;
		for (; i < n; i++) {//���� ����� ������� �� ������� � �� ���� �������� � ���������� �� �� �� �������� ������, ��� ����
			if (i != top && Visited[i] == 0 && Matr[i][top]>0 && ShortPath[top] + Matr[i][top] < ShortPath[i]) {
				ShortPath[i] = ShortPath[top] + Matr[i][top];//��������� ����� ���� � ������� i
			}
		}
		Visited[top] = 1; //������� ������� ���������

		int min = maxPath;//��������� �������
		int top = -1; //�������, ������� ����� ������� ������� ��� ���������� ����
		for (int i = 0; i < n; i++) { //���� ������������� ������� � ����� �������� �����
			if (Visited[i] == 0 && ShortPath[i] < min) {
				min = ShortPath[i];
				top = i;
			}
		}

	} while (top == -1); //��� ������� ���������
	
	
	i = 0;
	while (i < n && ShortPath[i] < maxPath) {
		sum += ShortPath[i];
		i++;
	}

	/*�������� ������� �����*/
	delete[] ShortPath;
	delete[] Visited;
	
	if (i==n) return true;
	else
	return false;

}

int main() {

	
	/*�������� ������������ �������*/
	int n;
	cout << "������� ���������� ������" << endl;
	cin >> n;
	int **Graf = new int*[n];
	for (int i = 0; i < n; i++) {
		Graf[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		Graf[i][i] = 0;
		
	}

	/*���� ����� � �������*/
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			int a;
			cout << "������� ��� ����� ����� ��������� " << i+1 << "� " << j+1 << ", ���� ����� ���, ������� 0" << endl;
			cin >> a;
			Graf[i][j] = a;
			Graf[j][i] = a;
		}
	}

	int sum=0, minsum = 0;
	int SearchTop = -1;
	for (int i = 0; i < n; i++) {
		if (CheckTop(Graf, i, n, sum) && (minsum==0 || sum<minsum)) {
			SearchTop = i;
			minsum = sum;
		}
	}

	if (SearchTop == -1) {
		cout << "� ����� ��� �������" << endl;
	}
	else
		cout << "������� ����� - ������� ����� "<< SearchTop+1 << endl;


	/*�������� ������� �� ������*/
	for (int i = 0; i < n; i++) {
		delete[] Graf[i];
	}
	
	return 0;
}