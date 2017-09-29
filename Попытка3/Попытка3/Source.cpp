/*����� ������� �����, �� ���� ����� ����� ������� �����, 
��������� ���������� �� ������� �� ���� ��������� ������ �������� ����������.*/
#include <iostream>
#include <fstream>
#include <io.h>
#include <stdio.h>

using namespace std;

const int maxPath = 100000;

struct TFileInfo { //��������� �������� �������� ���������� � ��� �����
	FILE *f;
	char FileName[20];

};


bool CheckTop(int **Matr, int Num, int n, int & sum) {
	//���������� ��������� ��������
	/*�������� ������� �������� �����*/
	int *ShortPath = new int[n];
	/*�������� ������� ���������� ������*/
	int *Visited = new int[n];
	//��������� ������� ���������� ������ � �������� �����
	int i;
	sum = 0;
	for (i = 0; i < n; i++) {
		ShortPath[i] = maxPath;
		Visited[i] = 0; //0 - �� ��������, 1 - ��������
	}
	ShortPath[Num] = 0; //�������� ���� �� �������� ������� - 0
	
	int top = Num; //top - ������� �������

	do
	{
		i = 0;
		for (; i < n; i++) {//���� ����� ������� �� ������� � �� ���� �������� � ���������� �� �� �� �������� ������, ��� ����
			if (i != top && Visited[i] == 0 && Matr[i][top]>0 && ShortPath[top] + Matr[i][top] < ShortPath[i]) {
				ShortPath[i] = ShortPath[top] + Matr[i][top];//��������� ����� ���� � ������� i
			}
		}
		Visited[top] = 1; //������� ������� ���������

		int min = maxPath;//��������� �������
		top = -1; //�������, ������� ����� ������� ������� ��� ���������� ����
		for (i = 0; i < n; i++) { //���� ������������� ������� � ����� �������� �����
			if (Visited[i] == 0 && ShortPath[i] < min) {
				min = ShortPath[i];
				top = i;
			}
		}

	} while (top != -1); //��� ������� ���������
	


	i = 0;
	while (i < n && ShortPath[i] < maxPath) {
		sum += ShortPath[i];
		i++;
	}
		
	/*�������� ������� �����*/
	delete[] ShortPath;
	delete[] Visited;

	if (i == n) return true;
	//else
	return false;
	

}

void ShowMessage(char txt[]) { //����� ��������� ������������

	printf_s("%s\n", txt);
	puts("");

}


bool InputQuery(char *txt) { //���������� ����� ������������ �� ������ � ������� yes\no 
	char s[5]; //����� ������������
	char ans; //������ ������ ������
	do {
		printf_s("%s\n", txt); //����� ������� 
		gets_s(s); //��������� ������
		ans = s[0]; //�������� ������ ������ ������
	} while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n'); //���� ����� �� �������� ��� ������� yes\no 
	return (ans == 'Y' || ans == 'y'); //��������� true ���� yes
}



bool CorrectFilename(const char *txt) //�������� �� ������������ ����� �����, boolean //��������� ������������ ����� �����
{
	int len; //���������� ����� �����
	bool res = true; //���������� ���������� ���������� �������
	int i = 0; //���������� ������� ������� �����
	int j;
	char cor[8] = "/:?*<>|"; //������ ������������ ��������
	len = strlen(txt); //����� �����
	while ((i < len) && (res)) //���� �� ����� ����� � ��� �����, ��������� ����
	{
		j = 0;
		while ((j < 8) && (res)) //���� �� ��������� ��� ���������. ������� � ��� �����, ��������� ����
		{
			if (txt[i] != cor[j])
				j++; //���� ������ ����������, �� ��������� ��������� ������������ ������
			else
				res = false; //����� ��� �����������
		}
		i++;//��������� �� ��������� ������ �����
	}
	return res; //���������� true - ��� ���������, false - ��� �� ���������
}

void deletestr(char *s, int l, int r) { //������� ��������� � ������ � ������� l �� r
	char s1[30];
	int len = strlen(s); //����� ������
	int i = 0;
	if (l >= 0 && l <= r && r < len) { //���� ������� ����������
		for (; i < l; i++) //�������� ������ � 0 �� l-1
			s1[i] = s[i];
		for (int j = r + 1; j < len; j++, i++) //�������� � r+1 �� len 
			s1[i] = s[j];
		s1[i] = '\0'; //��������� ������ �����
		strcpy_s(s, 30, s1); //��������� ����� ������ � ��������
	}

}


void Trim(char *str) { //������� ������� ����� � ������ � ������
	int i = 0;
	int len = strlen(str); //����� ������
	int l, r;
	while (i<len && str[i] == ' ') i++; //������� �� ������� ��������� �� �������
	l = i - 1; //���������� ������� 
	i = len - 1;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\n')) i--; //� ����� ������� �� ������� ��������� �� �������
	r = i + 1;//����������
	deletestr(str, r, len - 1); 	 //������� ����� � ��������� ������
	deletestr(str, 0, l); //������� ����� � ��������� �����
}

bool FileExists(char *N)//��������� ������������� �����
{
	bool res;
	

	if (!_access(N, 0)) res = true; //���� ���������� ���� � ��������� ������, ������ true 
	else res = false;

	return res;
}

bool InputFileName(char *txt, char *FileName, bool MustExist) { //���� ����� �����, MustExist ����������, ������ �� ������������ ����
	bool check; //���������
	cout<< txt<<endl; //����� ������ 
	cin>>FileName; //��������� ���
	Trim(FileName); //������ ������� ����� � ������

	check = true;


	if (strlen(FileName) == 0) { //���� ������ ������, ������� �� ������� � ����������� false 
		ShowMessage("�������� ��������");
		check = false;
	}

	else
		if (CorrectFilename(FileName)) { //���� ��� ������� ���������
			if (MustExist) //���� ������ ������������ 
			{

				if (FileExists(FileName)) { //���� ����������

					check = true; //��������� true
				}
				else //�� ����������
				{

					ShowMessage("���� �� ������"); //����� ���������, ��������� false
					check = false;
				}
			}
			else //���� �� ������ ��� ������������ 
			{
				if (!FileExists(FileName)) { // ���� �� ���������� 
					check = true;
				}

				else //���� ���������� 
				{
					if (!InputQuery("����� ���� ��� ����������.��������?")) //���������� �������� ������� ���� ����� 
						check = false;
				}
			}
		}
		else {
			ShowMessage("������������ ��� �����");
		}
		return check; //��������� ���������
}










int main() {

	setlocale(LC_ALL, "Russian");
	/*�������� ������������ �������*/
	int **Graf;
	int n;


	cout << "��� �� ������ ������ ���������� � �����? 1 - �� �����, 2 - � ����������" << endl;
	int ans;
	cin >> ans;
	if (ans == 2) {
		
		cout << "������� ���������� ������" << endl;
		cin >> n;
		Graf = new int*[n];
		for (int i = 0; i < n; i++) {
			Graf[i] = new int[n];
		}

		for (int i = 0; i < n; i++) {
			Graf[i][i] = 0;

		}

		/*���� ����� � �������*/
		cout << "������� ���� ���e� ����� ���������:" << endl;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int a;
				cout << i + 1 << " � " << j + 1 << ", ���� ����� ���, ������� 0." << endl;
				cin >> a;
				Graf[i][j] = a;
				Graf[j][i] = a;
			}
		}
	}
	else
	{
		char FileName[20];
		if (InputFileName("������� ��� �����", FileName, true)) {
			ifstream fin(FileName);
			
			fin >> n;
			Graf = new int*[n];
			for (int i = 0; i < n; i++) {
				Graf[i] = new int[n];
			}

			for (int i = 0; i < n; i++) {
				Graf[i][i] = 0;

			}
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					int a;
					fin >> a;
					Graf[i][j] = a;
					Graf[j][i] = a;
				}
			}

		}
	}

	//����� �����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << Graf[i][j] << " ";
		}
		cout << endl;
	}

	//��������� ������ ������� � ���� �� ��� ���� ���� �� ��� ���������, ���������� ����� ���� ����� � ���������, ��������� �������
	int sum = 0, minsum = maxPath;
	int SearchTop = -1;
	for (int i = 0; i < n; i++) {
		if (CheckTop(Graf, i, n, sum) &&  (sum < minsum)) {
			SearchTop = i;
			minsum = sum;
		}
	}

	if (SearchTop == -1) {
		cout << "� ����� ��� �������" << endl;
	}
	else
		cout << "������� ����� - ������� ����� "<< SearchTop+1 << ", ����� - "<< minsum <<endl;


	/*�������� ������� �� ������*/
	for (int i = 0; i < n; i++) {
		delete[] Graf[i];
	}
	

	/*
	5
	3
	5
	0
	7
	2
	0
	0
	2
	6
	4
	
		
	*/



	return 0;
}