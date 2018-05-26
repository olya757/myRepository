#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
using namespace std;
//�������� ����� �� ��������� �������� � ������� �����
ofstream CreateFileRand(string FileName, int N, int M) {
	ofstream fs(FileName);
	for (int i = 0; i < N; ++i) {
		
		int r = rand()%(2*M +1)-M;
		fs << r << " ";
	}
	fs.close();
	return fs;
}

//�������� ����� �� ��������� �������� � ������� generate
ofstream CreateFileGenerate(string FileName, int N, int M) {
	ofstream fs;
	fs.open(FileName);
	generate_n(std::ostream_iterator<int>(fs, " "), N, [M]() {int i = rand() % (2 * M + 1) - M; return i; });
	fs.close();
	return fs;
}

//�������� �� �����
deque<int> LoadFromFile(ifstream &fin) {
	deque<int> dec;
	if (!fin) {
		cout << "���� �� ������." << endl;
		return dec;
	}
		
	int a;
	if (!(fin >> a)) { 
		cout << "�������� ������ ������" << endl;
		return dec;
	}
	if (fin.eof()) {
		cout << "���� ����." << endl;
	} else {
		while (!fin.eof()) {
			dec.push_back(a);

			if (!(fin >> a) && !fin.eof()) {
				cout << "�������� ������ ������" << endl;
				dec.clear();
				return dec;
			}
		}
	}
	return dec;
}

//�������������� ���� (�������� ������������� �������� ����������) � ������ for
deque<int> Modify(deque<int> &dec1) {
	int max = 0;
	deque<int> dec = dec1;
	int len = dec.size();
	for (const int i : dec) {
		if (i > max) {
			max = i;
		}
	}
	for (int &i: dec) {
		if (i > 0) {
			i = max;
		}
	}
	return dec;
}

//�������������� ���� (�������� ������������� �������� ����������) � �����������
void Modify(deque<int>::iterator begin, deque<int>::iterator end) {
	int max = 0;
	for (deque<int>::iterator i = begin; i != end; i++) {
		if (*i > max) max = *i;
	}
	for (deque<int>::iterator i = begin; i != end; i++) {
		if (*i > 0) *i=max;
	}
}

//�������������� ���� (�������� ������������� �������� ����������) � transform
void Modify_Transform(deque<int>::iterator &begin, deque<int>::iterator end) {
	int max = 0;
	transform(begin, end, begin, [&max](int i) { if (i > max) max = i;	return i; });
	transform(begin, end, begin, [max](int i) {return i > 0 ? max : i; });
}

//�������������� ���� (�������� ������������� �������� ����������) � for_each
void Modify_For_Each(deque<int>::iterator begin, deque<int>::iterator end) {
	int max;
	for_each(begin, end, [&max](int i) { if (i > max) max = i; });
	for_each(begin, end, [max](int &i) { i= i > 0 ? max : i; });
}

//������� ����� ���������
int Summ(deque<int> dec) {
	int summ = 0;
	for_each(dec.begin(), dec.end(), [&summ](int i) {summ+=i; });
	return summ;
}

//������� �������� ���������������
double MidArith(deque<int> &dec) {
	return (double)Summ(dec) / dec.size();
}

//������ � ����
void  Print(fstream &st,deque<int> &dec) {
	for_each(dec.begin(), dec.end(), [&st](int i) {st << i << " "; });
}

//������������� �����, ������ � �������
void  Print(ostream &st, deque<int> dec) {
	for_each(dec.begin(), dec.end(), [&st](int i) {st << i << " "; });
	st << endl;
}

//���������� ����
int Menu(int flag) {
	cout << "Menu:" << endl;
	cout << 1 << " - - - " << "������� ����� ���� �� ��������� ������������������� �����." << endl;
	cout << 2 << " - - - " << "��������� ������������������ �� �����." << endl;
	if (flag > 0) {
		cout << 3 << " - - - " << "�������� ��� ������������� ����� ������������������ ����������." << endl;
		cout << 4 << " - - - " << "��������� ����� ������ ������������������." << endl;
		cout << 5 << " - - - " << "��������� ������� ��������������." << endl;
		cout << 6 << " - - - " << "�������� ������������������ � ����." << endl;
		cout << 7 << " - - - " << "���������� ������������������." << endl;
	}
	cout << 0 << " - - - " << "�����." << endl<<endl;
	int res;
	while (!(cin >> res) || flag <= 0 && (res > 2) || (flag > 0) && (res > 7));	
	return res;
}

//���� ������ ��/���
bool InputQuery(string question) {
	cout << question << endl;
	cout << 1 << " - - - ��" << endl;
	cout << 0 << " - - - ���" << endl;
	int res;
	while (!(cin >> res) || res != 0 && res != 1);
	return res==1;
}

//���� ����� �����
string InputFileName() {
	string name;
	cout << "������� ��� �����" << endl;
	cin >> name;
	return name;
}

//���� �����
int InputNum(string str) {
	int Num;
	cout << str << endl;
	while (!(cin >> Num) || Num <= 0);
	return Num;
}

int main() {
	setlocale(LC_ALL, "Russian");
	bool exit = false;
	deque<int> dec;
	string FileName="";
	int N;
	int M;
	ofstream ofs;
	ifstream ifs;
	do {
		switch (Menu(dec.size())) {
		case 1: 
			N = InputNum("������� ���������� ���������.");
			M = InputNum("������� ������������ ������ �����.");
			FileName = InputFileName();
			//ofs=CreateFileRand(FileName,N,M);
			ofs = CreateFileGenerate(FileName, N, M);
			break;
		case 2:
			if (FileName == "") FileName=InputFileName();
			else if (!InputQuery("������������ ������� ����?")) {
				FileName = InputFileName();
			}
			ifs.open(FileName);
			dec = LoadFromFile(ifs);
			ifs.close();
			break;
		case 3:
			dec = Modify(dec);
			//Modify(dec.begin(), dec.end());
			//Modify_Transform(dec.begin(), dec.end());
			//Modify_For_Each(dec.begin(), dec.end());
			break;
		case 4:
			cout << "����� ��������� ����� " << Summ(dec) << endl;
			break;
		case 5:
			cout << "������� �������������� ����� " << MidArith(dec) << endl;
			break;
		case 6:
			FileName = InputFileName();
			ofs.open(FileName);
			Print(ofs, dec);
			ofs.close();
			break;
		case 7:
			Print(cout, dec);
			break;
		default:
			return 0;
		}
	} while (1);
	
}