#include "Hex.h"
#include <iostream>
#include <string>


/*Задание: реализовать операции с целыми неотрицательными шестнадцатеричными числами, представить их в виде массива 
из 100 беззнаковых символов*/
using namespace std;
//меню
int Menu() {
	cout << "1 - Сложить" << endl;
	cout << "2 - Вычесть" << endl;
	cout << "3 - Разделить" << endl;
	cout << "4 - Умножить" << endl;
	cout << "5 - Вычислить остаток от деления" << endl;
	int n;
	cin >> n ;
	return n;
}


int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите два шестнадцатеричных числа" << endl;
	Hex a, b;
	a.Read();
	if (!a.isCorrect()) {
		cout << "Некорректное значение" << endl;
		getchar();
		getchar();
		return 0;
	}
	
	b.Read();
	if (!b.isCorrect()) {
		cout << "Некорректное значение"<<endl;
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
	default: cout << "Неверно введен оператор" << endl;
		getchar();
		getchar();
		return 0;
	}
	res.Display();
	getchar();
	getchar();
	

	
	return 0;
}