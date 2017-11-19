#include "Hex.h"
#include "Hex.h"

const unsigned char let[17] = "0123456789abcdef";
const unsigned char one[100] = { '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
const unsigned char zero[100] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
int NumOfLet(char c) {
	if (c >= '0' && c <= '9') return (int)c - (int)'0';
	if (c >= 'a' && c <= 'z') return (int)c - (int)'a' + 10;
	if (c >= 'A' && c <= 'Z') return (int)c - (int)'A' + 10;
}

Hex::Hex(const unsigned char num[100]) {
	Init(num);
}

//возвращает длину числа
int Hex::size() {
	int j = 98;
	for (; j > 0 && number[j] == '0'; j--);
	return j + 1;
}
//инициализация через массив символов 
void Hex::Init(const unsigned char num[100]) {
	for (int i = 0; i<100; i++)
		number[i] = num[i];
	Size = size();

}

//перевод в десятичное
int Hex::NexToDec() {
	int res = 0;
	for (int i = 0; i < Size; i++) {
		res = res * 16 + NumOfLet(number[i]);
	}
	return res;
}


//проверка корректности числа
bool Hex::isCorrect() {
	bool res = true;
	
	for (int i = 0; i < Size && res; i++) {
		res = (number[i] >= '0' && number[i] <= '9') || (number[i] >= 'a' && number[i] <= 'f') || (number[i] >= 'A' && number[i] <= 'F');
	}
	return res;
}
//считывание с клавиатуры
void Hex::Read() {
	string s;
	cin >> s;
	Init(s);
}
//перевод в вид строки
string Hex::ToString() {
	string s = "";
	
	for (int i = 0; i < Size; i++) {
		s += number[Size - i - 1];
	}
	return s;
}
//показать в консоли, вывести за ним дополнительную строку (если надо)
void Hex::Display(string str) {

	cout << ToString() << str;
}

//определяет равно ли 
bool Hex::operator == (Hex b) {
	if (Size != b.Size) return false;
	int i = 0;
	for (; i < Size && number[i] == b.number[i]; i++);
	return (i == Size);

}
//возвращает правду если больше
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
//больше либо равно
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
//меньше
bool Hex::operator < (Hex b) {
	return (b > *this);
}
//меньше либо равно
bool Hex::operator <=(Hex b) {
	return (b >= *this);
}
//сумма
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
//разность
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
//деление (как для целых)
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

//умножение
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

Hex Hex::operator++(int)
{
	Hex One(one);
	Hex temp = *this;
	temp=temp+One;
	return temp;
}
Hex Hex::operator --(int) {
	Hex *tmp = *this;
	Hex One(one);
	tmp = tmp - One;
	return tmp;
}

ostream& operator<<(ostream& os, const Hex& hex)
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
