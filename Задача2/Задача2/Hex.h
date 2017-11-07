#include <iostream>
#include <string>

using namespace std;

unsigned char let[17] = "0123456789abcdef";
unsigned char one[100] = { '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
unsigned char zero[100] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
int NumOfLet(char c) {
	if (c >= '0' && c <= '9') return (int)c - (int)'0';
	if (c >= 'a' && c <= 'z') return (int)c - (int)'a' + 10;
	if (c >= 'A' && c <= 'Z') return (int)c - (int)'A' + 10;
}


class Hex {
	
public:
	unsigned char number[100];
	
	Hex(unsigned char num[100]=zero) {
		Init(num);
	}
	
	Hex(string s) {
		Init(s);
	}

	int size() {
		int j = 98;
		for (; j > 0 && number[j] == '0'; j--);
		return j + 1;
	}

	void Init(unsigned char num[100]) {
		for (int i = 0; i<100; i++)
			number[i] = num[i];

	}
	
	void Init(string s) {
		int i = 0;
		int j = 0;
		for (; j < s.length() && s[j] == ' '; j++);
		i = j;
		j = s.length() - 1;
		for (; j >=0 && s[j] == ' '; j--);
		for (; i <=j; i++) {
			number[i] = s[s.length() - i - 1];
		}
		for (int j = i; j < 100; j++) {
			number[j] = '0';
		}
		
	}

	int NexToDec(Hex a) {
		int res = 0;
		for (int i = 0; i < a.size(); i++) {
			res = res * 16 + NumOfLet(a.number[i]);
		}
		return res;
	}

	

	bool isCorrect() {
		bool res = true;
		for (int i = 0; i < size() && res; i++) {
			res = (number[i] >= '0' && number[i] <= '9') || (number[i] >= 'a' && number[i] <= 'f') || (number[i] >= 'A' && number[i] <= 'F');
		}
		return res;
	}

	void Read() {
		string s;
		cin >>  s;
		Init(s);
	}

	string ToString() {
		string s = "";
		for (int i = 0; i < size(); i++) {
			s += number[size() - i-1];
		}
		return s;
	}

	void Display(string str="") {
		
		cout << ToString()<<str;
	}



};

Hex Zero;
Hex One(one);
bool isEqual(Hex a, Hex b) {
	if (a.size() != b.size()) return false;
	int i = 0;
	for (; i < a.size() && a.number[i] == b.number[i]; i++);
	if (i == a.size()) return true;
	return false;
}

bool MoreThan(Hex a, Hex b) {
	if (a.size() > b.size())
		return true;
	if (a.size() < b.size())
		return false;
	int i = a.size() - 1;
	while (i >= 0 && a.number[i] == b.number[i]) {
		i--;
	}
	if (i < 0) return false;
	if (NumOfLet(a.number[i]) > NumOfLet(b.number[i]))
		return true;
	return false;
}

bool MoreOrEqualThan(Hex a, Hex b) {
	if (a.size() > b.size())
		return true;
	if (a.size() < b.size())
		return false;
	int i = a.size() - 1;
	while (i >= 0 && a.number[i] == b.number[i]) {
		i--;
	}
	if (i < 0) return true;
	if (NumOfLet(a.number[i]) > NumOfLet(b.number[i]))
		return true;
	return false;
}

bool LessThan(Hex a, Hex b) {
	return MoreThan(b, a);
}
bool LessOrEqualThan(Hex a, Hex b) {
	return MoreOrEqualThan(b, a);
}

Hex Summ(Hex a, Hex b) {
	Hex res;
	char c;
	Hex minn;
	Hex maxx;
	if (a.size() > b.size()) {
		minn.Init(b.number);
		maxx.Init(a.number);
	}
	else {
		minn.Init(a.number);
		maxx.Init(b.number);
	}

	int x = 0;
	int i = 0;
	int j = 0;
	for (; i < minn.size(); i++, j++) {
		int t = NumOfLet(a.number[i]) + NumOfLet(b.number[i]) + x;
		res.number[j] = let[t % 16];
		x = t / 16;
	}
	for (; i <= maxx.size() && i<99; i++, j++) {
		int t = NumOfLet(maxx.number[i]) + x;
		res.number[j] = let[t % 16];
		x = t / 16;
	}

	return res;
}

Hex Diff(Hex a, Hex b) {
	if (LessThan(a, b)) return zero;
	Hex res;
	unsigned char c;
	int x = 0;
	int i = 0;
	for (; i < b.size(); i++) {
		int t = NumOfLet(a.number[i]) - NumOfLet(b.number[i]) + x;
		if (t >= 0) {
			res.number[i] = let[t];
			x = 0;
		}
		else {
			t += 16;
			x = -1;
			res.number[i] = let[t];
		}

	}
	for (; i < a.size(); i++) {
		int t = NumOfLet(a.number[i]) + x;
		if (t >= 0) {
			res.number[i] = let[t];
			x = 0;
		}
		else {
			t += 16;
			x = -1;
			res.number[i] = let[t];
		}
	}
	for (; i < 100; i++) {
		res.number[i] = '0';
	}
	return res;

}

Hex Ost(Hex a, Hex b, int p) {
	if (!isEqual(b, Zero)) {
		Hex copya = a;
		Hex D;
		while (MoreOrEqualThan(copya, b)) {
			copya = Diff(copya, b);
			D = Summ(D, One);
		}
		if (p == 0) return D;
		return copya;
	}
	else
		return Zero;
}

Hex Div(Hex a, Hex b) {
	return Ost(a, b, 0);
}

Hex Mod(Hex a, Hex b) {
	return Ost(a, b, 1);
}

Hex Mult(Hex a, Hex b) {
	Hex minn;
	Hex maxx;
	if (MoreThan(a, b)) { minn = b; maxx = a; }
	else {
		minn = a;
		maxx = b;
	}

	Hex res;
	for (; MoreThan(minn, zero); minn = Diff(minn, One)) {
		res = Summ(res, maxx);
	}
	return res;
}
