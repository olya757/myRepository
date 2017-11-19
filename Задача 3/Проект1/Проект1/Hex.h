#pragma once
#include <iostream>
#include <string>


using namespace std;
static const unsigned char let[17];
static const unsigned char one[100];
static const unsigned char zero[100];

int NumOfLet(char c);
class Hex {
	
	
public:
	unsigned char number[100];
	int Size;
	//объявление через массив символов
	Hex(const unsigned char num[100] = zero);

	//возвращает длину числа
	int size();
	//инициализация через массив символов 
	void Init(const unsigned char num[100]);
	//инициализация через строку

	//перевод в десятичное
	int NexToDec();

	//проверка корректности числа
	bool isCorrect();
	//считывание с клавиатуры
	void Read();
	//перевод в вид строки
	string ToString();
	//показать в консоли, вывести за ним дополнительную строку (если надо)
	void Display(string str="");
	

	//определяет равно ли 
	bool operator == (Hex b);
	//возвращает правду если больше
	bool operator > (Hex b);
	//больше либо равно
	bool operator >= (Hex b);
	//меньше
	bool operator < (Hex b);
	//меньше либо равно
	bool operator <=(Hex b);
	//сумма
	Hex operator + (Hex b);
	//разность
	Hex operator - (Hex b);
	//деление (как для целых)
	Hex operator / (Hex b);
	//умножение
	Hex operator * (Hex b);
	Hex operator++(int);
	Hex operator --(int);

	friend ostream& operator<<(ostream& os, const Hex& hex);

};
//остаток от деления, % почему то не читается

Hex Mod(Hex a, Hex b);




