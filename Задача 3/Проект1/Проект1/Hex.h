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
	//���������� ����� ������ ��������
	Hex(const unsigned char num[100] = zero);

	//���������� ����� �����
	int size();
	//������������� ����� ������ �������� 
	void Init(const unsigned char num[100]);
	//������������� ����� ������

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
	Hex operator++(int);
	Hex operator --(int);

	friend ostream& operator<<(ostream& os, const Hex& hex);

};
//������� �� �������, % ������ �� �� ��������

Hex Mod(Hex a, Hex b);




