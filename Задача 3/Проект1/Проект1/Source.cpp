#pragma once
//#include "Deque.h"
#include "Hex.h"
#include <string>
#include <iostream>

using namespace std;
int main() 
{
	//Deque<int>  deque1;
	//Deque<string>  deque2;
	//Deque<Hex>  deque3;


	Hex nole;
	nole++;
	nole.Display();



	/*string s = "0";
	for (int i = 1; i <= 5; i++) {
		deque1.PushBack(i);
		deque1.PushInFront(i);
		deque2.PushBack(s);
		deque2.PushInFront(s);
		s += i;
		deque3.PushBack(nole);
		deque3.PushInFront(nole);
		nole++;
	}
	deque1.Print();
	deque2.Print();
	deque3.Print();*/
	return 0;
	
}