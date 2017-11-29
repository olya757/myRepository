#pragma once
#include "Deque.h"
#include "Hex.h"
#include "Process.h"
using namespace std;

class Menu
{ 
private: 
	int choose;

public:
	void Init();
	void Task();
};

void Menu::Init() {
	
	cout << "Какой тип должна содержать очередь?" << endl;
	cout << "1 - int" << endl;
	cout << "2 - string" << endl;
	cout << "3 - Hex" << endl;
	try {
		do {
			cin >> choose;
			cout << endl;
		} while (choose != 1 && choose != 2 && choose != 3);
	}
	catch (int) {
		runtime_error("Неверный формат");
		getchar();
		getchar();
	}
	
}

void Menu::Task() {
	switch (choose) {
	case 1:
	{Process <int> p1;
	Deque <int> a1;

	p1.Process1(a1); }
		break;
	case 2:
	{Deque<string>  a2;
	Process<string> p2;
	p2.Process1(a2); }
		break;
	case 3:
	{Deque <Hex>  a3;
	Process <Hex> p3;
	p3.Process1(a3); }
		break;
	}
}


