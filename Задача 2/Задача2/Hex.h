#pragma once
#include <iostream>
#include <string>

using namespace std;
extern unsigned char let[17];
extern unsigned char one[100];
extern unsigned char zero[100];
int NumOfLet(char c);
class Hex {
	
public:
	unsigned char number[100];
	int Size;
	//���������� ����� ������ ��������
	Hex(unsigned char num[100] = zero);
	//���������� ����� ������
	Hex(string s);
	//���������� ����� �����
	int size();
	//������������� ����� ������ �������� 
	void Init(unsigned char num[100]);
	//������������� ����� ������
	void Init(string s);
	//������� � ����������
	int NexToDec();

	//�������� ������������ �����
	bool isCorrect();
	//���������� � ����������
	void Read();
	//������� � ��� ������
	string ToString();
	//�������� � �������, ������� �� ��� �������������� ������ (���� ����)
	void Display(string str="");

	

	//���������� ����� �� 
	bool operator == (Hex b);
	//���������� ������ ���� ������
	bool operator > (Hex b);
	//������ ���� �����
	bool operator >= (Hex b);
	//������
	bool operator < (Hex b);
	//������ ���� �����
	bool operator <=(Hex b);
	//�����
	Hex operator + (Hex b);
	//��������
	Hex operator - (Hex b);
	//������� (��� ��� �����)
	Hex operator / (Hex b);
	//���������
	Hex operator * (Hex b);
	Hex operator ++(int);
	Hex operator --(int);

	friend ostream& operator<<(ostream& os, Hex& hex);
};
//������� �� �������, % ������ �� �� ��������

Hex Mod(Hex a, Hex b);




