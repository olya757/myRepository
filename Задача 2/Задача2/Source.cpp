#include "Hex.h"
#include <iostream>
#include <string>


/*�������: ����������� �������� � ������ ���������������� ������������������ �������, ����������� �� � ���� ������� 
�� 100 ����������� ��������*/
using namespace std;
//����
int Menu() {
	cout << "1 - �������" << endl;
	cout << "2 - �������" << endl;
	cout << "3 - ���������" << endl;
	cout << "4 - ��������" << endl;
	cout << "5 - ��������� ������� �� �������" << endl;
	int n;
	cin >> n ;
	return n;
}


int main() {
	setlocale(LC_ALL, "Russian");
	cout << "������� ��� ����������������� �����" << endl;
	Hex a, b;
	a.Read();
	if (!a.isCorrect()) {
		cout << "������������ ��������" << endl;
		getchar();
		getchar();
		return 0;
	}
	
	b.Read();
	if (!b.isCorrect()) {
		cout << "������������ ��������"<<endl;
		getchar();
		getchar();
		return 0;
	}
	Hex res;
	int n = Menu();
	switch (n) 
	{
	case 1:a++; res = a;  break;
	case 2: res = a - b;  break;
	case 3: res = a / b;  break;
	case 4: res = a * b;  break;
	case 5: res = Mod(a, b);  break;
	default: cout << "������� ������ ��������" << endl;
		getchar();
		getchar();
		return 0;
	}
	res.Display();
	getchar();
	getchar();
	

	
	return 0;
}