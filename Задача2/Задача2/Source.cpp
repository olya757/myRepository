#include <iostream>
#include <string>
#include "Hex.h"

using namespace std;

int Task(Hex a, Hex b) {
	a.Read();
	if (!a.isCorrect()) {
		cout << "Некорректное значение";
		return 0;
	}
	b.Read();
	if (!b.isCorrect()) {
		cout << "Некорректное значение";
		return 0;
	}
	Hex aSumm, aDiff1, aDiff2, aDiv1, aDiv2, aMod1, aMod2, aMult;
	
	aSumm = Summ(a, b);
	a.Display(" + "); b.Display(" = ");
	aSumm.Display("\n");

	aDiff1 = Diff(a, b);
	a.Display(" - "); b.Display(" = ");
	aDiff1.Display("\n");

	aDiff2 = Diff(b, a);
	b.Display(" - "); a.Display(" = ");
	aDiff2.Display("\n");

	if (!(b.size()==1 && b.number[0]=='0')) {
		aDiv1 = Div(a, b);
		a.Display(" div "); b.Display(" = ");
		aDiv1.Display("\n");
	}
	if (!(a.size() == 1 && a.number[0] == '0')) {
		aDiv2 = Div(b, a);
		b.Display(" div "); a.Display(" = ");
		aDiv2.Display("\n");
	}
	if (!(b.size() == 1 && b.number[0] == '0')) {
		aMod1 = Mod(a, b);
		a.Display(" mod "); b.Display(" = ");
		aMod1.Display("\n");
	}
	if (!(a.size() == 1 && a.number[0] == '0')) {
		aMod2 = Mod(b, a);
		b.Display(" mod "); a.Display(" = ");
		aMod2.Display("\n");
	}

	aMult = Mult(a, b);
	a.Display(" * "); b.Display(" = ");
	aMult.Display("\n");
	return 0;
}



int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите два шестнадцатеричных числа" << endl;
	Hex a, b;
	
	return Task(a,b);
	
}