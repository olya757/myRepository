#include "Hex.h"

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

Hex::Hex(unsigned char num[100]) {
	Init(num);
}
//���������� ����� ������
Hex::Hex(string s) {
	Init(s);
}
//���������� ����� �����
int Hex::size() {
	int j = 98;
	for (; j > 0 && number[j] == '0'; j--);
	return j + 1;
}
//������������� ����� ������ �������� 
void Hex::Init(unsigned char num[100]) {
	for (int i = 0; i<100; i++)
		number[i] = num[i];
	Size = size();

}
//������������� ����� ������
void Hex::Init(string s) {
	int i = 0;
	int j = 0;
	int len = s.length();
	for (; j < len && s[j] == ' '; j++);
	i = j;
	j = len - 1;
	for (; j >= 0 && s[j] == ' '; j--);

	for (; i <= j; i++) {
		number[i] = s[len - i - 1];
	}
	for (int j = i; j < 100; j++) {
		number[j] = '0';
	}
	Size = size();

}
//������� � ����������
int Hex::NexToDec() {
	int res = 0;
	for (int i = 0; i < Size; i++) {
		res = res * 16 + NumOfLet(number[i]);
	}
	return res;
}


//�������� ������������ �����
bool Hex::isCorrect() {
	bool res = true;
	
	for (int i = 0; i < Size && res; i++) {
		res = (number[i] >= '0' && number[i] <= '9') || (number[i] >= 'a' && number[i] <= 'f') || (number[i] >= 'A' && number[i] <= 'F');
	}
	return res;
}
//���������� � ����������
void Hex::Read() {
	string s;
	cin >> s;
	Init(s);
}
//������� � ��� ������
string Hex::ToString() {
	string s = "";
	
	for (int i = 0; i < Size; i++) {
		s += number[Size - i - 1];
	}
	return s;
}
//�������� � �������, ������� �� ��� �������������� ������ (���� ����)
void Hex::Display(string str) {

	cout << ToString() << str;
}

//���������� ����� �� !!!!!!!!!!!!
bool Hex::operator == (Hex b) {
	if (Size != b.Size) return false;
	int i = 0;
	for (; i < Size && number[i] == b.number[i]; i++);
	return (i == Size);

}
//���������� ������ ���� ������
bool Hex::operator > (Hex b) {
	if (Size > b.Size)
		return true;
	if (Size < b.Size)
		return false;
	int i = Size - 1;
	while (i >= 0 && number[i] == b.number[i]) {
		i--;
	}
	if (i < 0) return false;
	if (NumOfLet(number[i]) > NumOfLet(b.number[i]))
		return true;
	return false;
}
//������ ���� �����
bool Hex::operator >= (Hex b) {
	if (Size > b.Size)
		return true;
	if (Size < b.Size)
		return false;
	int i = Size - 1;
	while (i >= 0 && number[i] == b.number[i]) {
		i--;
	}
	if (i < 0) return true;
	if (NumOfLet(number[i]) > NumOfLet(b.number[i]))
		return true;
	return false;
}
//������
bool Hex::operator < (Hex b) {
	return (b > *this);
}
//������ ���� �����
bool Hex::operator <=(Hex b) {
	return (b >= *this);
}
//�����
Hex Hex::operator + (Hex b) {
	
	Hex res;
	Hex minn;
	Hex maxx;
	if (Size > b.Size) {
		minn.Init(b.number);
		maxx.Init(number);
	}
	else {
		minn.Init(number);
		maxx.Init(b.number);
	}

	int x = 0;
	int i = 0;
	int j = 0;
	for (; i < minn.Size; i++, j++) {
		int t = NumOfLet(number[i]) + NumOfLet(b.number[i]) + x;
		res.number[j] = let[t % 16];
		x = t / 16;
	}
	for (; i <= maxx.Size && i<99; i++, j++) {
		int t = NumOfLet(maxx.number[i]) + x;
		res.number[j] = let[t % 16];
		x = t / 16;
	}
	res.Size = res.size();
	return res;
}
//��������
Hex Hex::operator - (Hex b) {
	Hex Zero;
	if ((*this < b)) return Zero;
	Hex res;
	int x = 0;
	int i = 0;
	for (; i < b.Size; i++) {
		int t = NumOfLet(number[i]) - NumOfLet(b.number[i]) + x;
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
	for (; i < Size; i++) {
		int t = NumOfLet(number[i]) + x;
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
	res.Size = res.size();
	return res;

}
//������� (��� ��� �����)
Hex Hex::operator / (Hex b) {
	Hex Zero;
	Hex One(one);

	if (!(b == Zero)) {
		Hex copya = *this;
		Hex D;
		while (copya >= b) {
			copya = copya - b;
			D = D + One;
		}
		D.Size = D.size();
		return D;
	}
	else
		return Zero;

}

//���������
Hex Hex::operator * (Hex b) {
	Hex Zero;
	Hex One(one);
	Hex minn;
	Hex maxx;
	if (*this > b) { minn = b; maxx = *this; }
	else {
		minn = *this;
		maxx = b;
	}

	Hex res;
	for (; minn > Zero; minn = minn - One) {
		res = res + maxx;
	}
	res.Size = res.size();
	return res;
}

Hex Hex::operator ++(int) {
	Hex temp = *this;
	Hex One(one);
	temp= temp + One;
	return temp;
}
Hex Hex::operator --(int) {
	Hex temp = *this;
	Hex One(one);
	temp = temp - One;
	return temp;
}

ostream& operator<<(ostream& os, Hex& hex)
{
	os << hex.ToString();
	return os;
}


Hex Mod(Hex a, Hex b) {
	Hex Zero;
	Hex One(one);
	if (!(b == Zero)) {
		Hex copya = a;

		while (copya >= b) {
			copya = copya - b;

		}
		copya.Size = copya.size();
		return copya;
	}
	else
		return Zero;
}
