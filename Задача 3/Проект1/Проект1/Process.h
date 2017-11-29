#pragma once
#include <iostream>
#include <string>
#include "Hex.h"
#include "Deque.h"
#include <stdio.h>

using namespace std;
template <class T>
class Process {
public:
	void Process1(Deque<T>  &dec);

};

template <class T>
void Process<T>::Process1(Deque<T>  &dec) {
	
	int choose = 0;
	do {
		int var = dec.Count() > 0 ? 5 : 2;
		choose = ShowMenu(var);
		switch (choose) {
		case 1:
		{
				 T p1;
				cout << "������� �������" << endl;
				if (cin >> p1) {
					dec.PushBack(p1);
					cout << endl;
					getchar();
					getchar();
				}
				else
				{
					cout << endl;
					cout << "�������� ������" << endl;
					getchar();
					getchar();
					choose = 0;
				}
			
		}
			break;
		case 2:
		{			
			  T p2;
				cout << "������� �������" << endl;
				if (cin >> p2) {
					dec.PushInFront(p2);
					cout << endl;
					getchar();
					getchar();
				}
				else
				{
					cout << endl;
					cout << "�������� ������" << endl;
					getchar();
					getchar();
					choose = 0;
				}

			}
			
		
			break;
		case 3:
		{
			dec.Print(); 
			cout << endl;
			getchar();
			getchar(); 
		}
			break;
		case 4:
		{	
			cout << dec.PopFromBack() << endl; 
			cout << endl;
			getchar();
			getchar(); 
		}
			break;
		case 5:
		{cout << dec.PopFromFront() << endl; cout << endl;
		getchar();
		getchar(); }
			break;
		}
	} while (choose > 0);
}

int ShowMenu(int var) {

	int choose = 0;
	cout << "�������� ��������" << endl;
	cout << "1 - �������� ������� � �����" << endl;
	cout << "2 - �������� ������� � ������" << endl;
	if (var > 2)
	{
		cout << "3 - ���������� ������� " << endl;
		cout << "4 - ������� ������� �� �����" << endl;
		cout << "5 - ������� ������� �� ������" << endl;
	}
	cout << "0 - �����" << endl;
	do {
		cin >> choose;
		cout << endl;
	} while (choose > var);
	return choose;
}