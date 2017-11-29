#include "Deque.h"
#include "Hex.h"
#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;


int main() 
{
	setlocale(LC_ALL, "Russian");
	Menu menu;
	menu.Init();
	menu.Task();
	return 0;
	
}