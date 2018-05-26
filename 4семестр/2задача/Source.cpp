/*�2 
������ � ������ �� ������ ������������ ����� ��������� � ������: ����� �����,*/
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;

//Date
struct Date {
	int dd;
	int mm;
	int yy;
	string ToString();
	bool Check();
	void Increase(int count);//� ����
	void Input(string str);
	void Print();
};

string Date::ToString() {
	string s = to_string(dd) + '.' + to_string(mm) + '.' + to_string(yy);
	return s;
}

bool Date::Check() {
	int maxdd;
	switch (mm)
	{
	case 1:
	case 3:
	case 5: {maxdd = 31; break; }
		case 7: {maxdd = 31; break; }
		case 8: {maxdd = 31; break; }
		case 10: {maxdd = 31; break; }
		case 12: {maxdd = 31; break; }
		case 2: {
			maxdd = yy % 4 == 0 ? 29 : 28;//���������� ��������
			break;
		}
		case 4: {maxdd = 30; break; }
		case 6: {maxdd = 30; break; }
		case 9: {maxdd = 30; break; }
		case 11: {maxdd = 30; break; }
	default: return false;
	}
	return dd > 0 && dd <= maxdd && yy > 0;
}

void Date::Increase(int count) {
	while (count>0) {
		int maxdd;
		switch (mm)
		{
		case (1, 3, 5, 7, 8, 10, 12): {maxdd = 31; break; }
		case (2): {
			maxdd = yy % 4 == 0 ? 29 : 28;
			break;
		}
		default: maxdd = 30;
			break;
		}
		if (dd + count > maxdd) {
			int p = dd;
			if (mm == 12) {
				mm = 1;
				yy++;
				dd = 1;
			}
			else
				mm++;
			count -= (maxdd - p) + 1;
		}
		else
		{
			dd += count;
			count = 0;
		}
	}
}

bool GetNum(string str, int p1, int p2, int &res) {
	res = 0;
	int i = p1;
	while (i < p2) {
		if (str[i] > '9' || str[i] < '0') {
			return false;
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return true;
}

bool StrToDate(string str, Date &d) {
	unsigned int i = 0;
	while (i < str.size() && str[i] != '.') 
		i++;
	if (i >= str.size()) 
		return false;
	unsigned char p1 = i;
	i++;
	while (i < str.size() && str[i] != '.') 
		i++;
	if (i >= str.size()) 
		return false;
	unsigned int p2 = i;
	return GetNum(str, 0, p1, d.dd) &&
		GetNum(str, p1 + 1, p2, d.mm) &&
		GetNum(str, p2 + 1, str.size(), d.yy) &&
		d.Check();
}

void Date::Input(string str) {
	cout << str << endl;
	cout << "� ������� dd.mm.yyyy" << endl;
	string res;
	do {
		cin >> res;
	} while (!StrToDate(res, *this));
}

void Date::Print() {
	cout << ToString() << endl;
}

void InputNum(string str, int &res) {
	cout << str << endl;
	while (!(cin >> res && res>0));
}

void InputStr(string str, char* res) {
	cout << str << endl;
	do {
		cin >> res;
	} while (res == "");
}

//Product

struct Product {
	int NumOfStock;
	int Code;
	char Name[40];
	Date InputDate;
	Date OutPutDate;
	int Life;
	int Count;
	int Price;
	void Print();
	void Input();
};

void Product::Print() {
	cout << "���: " << Code << endl;
	cout << "��������: " << Name << endl;
	cout << "�����: " << NumOfStock << endl;
	cout << "���� �����������: " << InputDate.ToString() << endl;
	cout << "���� ��������: " << Life << endl;
	cout << "����������: " << Count << endl;
	cout << "����: " << Price << endl;
	cout << endl;
}

void Product::Input() {
	InputNum("������� ���������� ��� ������", Code);
	InputStr("������� �������� ������", Name);
	InputNum("������� ����� ������", NumOfStock);
	InputDate.Input("������� ���� �����������");
	InputNum("������� ���� �������� � ����", Life);
	OutPutDate = InputDate;
	OutPutDate.Increase(Life);
	InputNum("������� ���������� ������", Count);
	InputNum("������� ���� ������", Price);
}

void InputFileName(string &FileName) {
	cout << "������� ��� �����" << endl;
	do {
		cin >> FileName;
	} while (FileName == "");
}

void ShowMessage(string str) {
	cout << str << endl << endl;
}

//Base
template <class T>
class Base {
public:
	vector<T> base;
	string FileName;
	void Assign(vector<T> b);
	Base();
	~Base();
	int Count();
	bool Add(T p);
	bool Delete(T p);
	bool Change(T p);
	vector<T> LinSearch(bool(*f)(T&, T&), T need);
	vector<T> BinSearch(bool(*f)(T&, T&), T need);
	vector<T> LinSearch_Life(T need);
	vector<T> SortAndSearch_Life(T need);
	vector<T> GetStock(int num);
	void  LoadFromFile();
	void  SaveToFile();
	void Print();
	void Sort(bool(*f)(T&, T&));
	void ChangeStockOfChoosenElems(Base<Product> res, int newStock);

};

template <class T>
void Base<T>::Print() {
	for (Product p : base) {
		p.Print();
	}
}

template <class T>
Base<T>::Base() {
	FileName = "binfile.txt";
	LoadFromFile();
}

template <class T>
Base<T>::~Base(){
	SaveToFile();
}



template <class T>
void Base<T>::LoadFromFile() {
	base.clear();
	ifstream fin(FileName, ios::binary);
	Product p;
	if (fin) {
		while (fin.read(reinterpret_cast<char*>(&p), sizeof(p))) {
			base.push_back(p);
		}
		fin.close();
	}
}

template <class T>
void Base<T>::SaveToFile() {
	ofstream fout(FileName, ios::binary);
	for (Product p : base) {
		fout.write(reinterpret_cast<char*>(&p), sizeof(p));
	}
	fout.close();
}

template <class T>
void  Base<T>::Assign(vector<T> b) {
	base = b;
}

bool CompDate(const Date &T1, const Date &T2) {
	if (T1.yy != T2.yy) return T1.yy<T2.yy;
	if (T1.mm != T2.mm) return T1.mm < T2.mm;
	return T1.dd < T2.dd;
}

bool CompNumOfStock(Product &T1, Product &T2) {
	return (T1.NumOfStock < T2.NumOfStock);
}

bool CompCode(Product &T1, Product &T2) {
	return (T1.Code < T2.Code);
}

bool CompInputDate(Product &T1, Product &T2) {
	return CompDate(T1.InputDate, T2.InputDate);
}

bool CompOutPutDate(Product &T1, Product &T2) {
	return CompDate(T1.OutPutDate, T2.OutPutDate);
}

bool CompCount(Product &T1, Product &T2) {
	return (T1.Count<T2.Count);
}

bool CompPrice(Product &T1, Product &T2) {
	return (T1.Price<T2.Price);
}

template <class T>
vector<T> Base<T>::LinSearch(bool(*f)(T&, T&), T need) {
	vector<T> Result;
	for (auto it = base.begin(); it != base.end(); it++) {
		if (!f(*it,need) && !f(need,*it)) {
			Result.push_back(*it);
		}
	}
	return Result;
}

template <class T>
vector<T> Base<T>::BinSearch(bool(*f)(T&, T&), T need) {
	vector<T> Result;
	sort(base.begin(), base.end(), f);
	int begin = 0, end = base.size() - 1;
	while (begin != end) {
		int m = (begin + end) / 2;
		if (f(base[m],need)) begin = m + 1;
		else
			end = m;
	}
	int i = begin - 1;
	while (i>0 && !f(base[i], need) && !f(need,base[i])) {
		Result.push_back(base[i]);
		i--;
	}
	while (begin<base.size() && !f(base[begin], need) && !f(need, base[begin])) {
		Result.push_back(base[begin]);
		begin++;
	}
	return Result;
}

template <class T>
vector<T> Base<T>::LinSearch_Life(T need)
{
	vector<T> Result;
	for (auto it = base.begin(); it != base.end(); it++) {
		if (!CompOutPutDate(need, *it)) {
			Result.push_back(*it);
		}
	}
	return Result;
}

template <class T>
vector<T> Base<T>::SortAndSearch_Life(T need) {
	vector<T> Result;
	sort(base.begin(), base.end(), CompOutPutDate);
	for (auto it = base.begin(); it != base.end() && !CompOutPutDate(need, *it);it++) {
		Result.push_back(*it);
	}
	return Result;
}

template <class T>
vector<T> Base<T>::GetStock(int num) {
	vector<T> result;
	for (Product p : base) {
		if (p.NumOfStock == num)
			result.push_back(p);
	}
	return result;
}

template <class T>
void Base<T>::Sort(bool(*f)(T&, T&)) {
	sort(base.begin(), base.end(), f);
}

void ShowResultsForEachStock(Base<Product> b) {
	if (b.Count() == 0) return;
	b.Sort(CompNumOfStock);
	int cntTypes=0;
	int cntAll=0;
	int Summ = 0;
	int NumOfStock = b.base[0].NumOfStock;
	cout << "����� �"<<NumOfStock<<endl;
	for (Product p : b.base) {
		if (p.NumOfStock != NumOfStock) {
			cout << "���������� ������������:"<<cntTypes<< endl;
			cout << "���������� �������:" <<cntAll <<endl;
			cout << "��������� ���������:" <<Summ <<endl;
			cntTypes = 0;
			cntAll = 0;
			Summ = 0;
			NumOfStock = p.NumOfStock;
			cout << "����� �" << NumOfStock << endl;
		}
		cntTypes++;
		cntAll += p.Count;
		Summ += p.Price;
	}
	cout << "���������� ������������:" << cntTypes << endl;
	cout << "���������� �������:" << cntAll << endl;
	cout << "��������� ���������:" << Summ << endl;
}

bool InputQuery(string str) {
	cout << str << endl;
	cout << "0 - ���" << endl;
	cout << "1 - ��" << endl;
	int ans;
	while (!(cin >> ans && (ans == 0 || ans == 1)));
	return ans == 1;
}

template <class T>
bool Base<T>::Add(T p) {
	if (LinSearch(CompCode,p).size() > 0) {
		if (InputQuery("����� ������� ����. ��������?")) {
			Change(p);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		base.push_back(p);
		return true;
	}
}

template <class T>
bool Base<T>::Delete(T p) {
	for (auto tmp = base.begin(); tmp != base.end(); tmp++) {
		if (!CompCode(*tmp,p)&& !CompCode(p, *tmp)) {
			base.erase(tmp);
			return true;
		}
	}
	return false;
}

template <class T>
bool Base<T>::Change(T p) {
	for (auto tmp = base.begin(); tmp != base.end(); tmp++) {
		if (!CompCode(*tmp, p) && !CompCode(p, *tmp)) {
			*tmp = p;
			return true;
		}
	}
	return false;
}

template <class T>
int Base<T>::Count() {
	return base.size();
}
template <class T>
void Base<T>::ChangeStockOfChoosenElems(Base<Product> res, int newStock) {
	for (Product p : res.base) {
		for (Product &p1 : base) {
			if (p.Code == p1.Code && p.NumOfStock == p1.NumOfStock) {
				p1.NumOfStock = newStock;
				break;
			}
		}
	}
}



int PrintMenu(int p) {
	cout << "1 - �������� �������" << endl;
	if (p > 2) {
		cout << "2 - ������� �������" << endl;
		cout << "3 - �������� �������" << endl;
		cout << "4 - ����� ������� �� ����" << endl;
		cout << "5 - �������� �������� �� ������ ������" << endl;
		cout << "6 - ����� ������������ ��������" << endl;
		cout << "7 - ����� ������ �� ���� �����������" << endl;
		cout << "8 - ���������� � �������" << endl;
		cout << "9 - ����� ����� �� ���������" << endl;
		cout << "10 - �������� ������� ����� �� �������" << endl;
	}
	cout << "0 - �����" << endl;
	int res;
	while (!(cin >> res && res <= p && res>=0));
	return res;
}

void ChooseProductWithCriteries(Base<Product> &res) {
	cout << "1 - ����� ������" << endl;
	cout << "2 - ���� ���������" << endl;
	cout << "3 - ���� ��������" << endl;
	cout << "4 - ���������� ������" << endl;
	cout << "5 - ��������� ������" << endl;
	int ans = 0;
	while (!(cin >> ans) && (ans <= 0 || ans > 5));
	switch (ans) {
	case 1: {
		Product p;
		InputNum("������� ����� ������", p.NumOfStock);
		res.base = res.BinSearch(CompNumOfStock, p);
		break; }
	case 2: {
		Product p;
		p.InputDate.Input("������� ���� ���������");
		res.base = res.BinSearch(CompInputDate, p);
		break;
	}
	case 3: {
		Product p;
		p.OutPutDate.Input("������� ���� ��������� ����� ��������");
		res.base = res.BinSearch(CompOutPutDate, p);
		break;
	}
	case 4: {
		Product p;
		InputNum("������� ���������� ������", p.Count);
		res.base = res.BinSearch(CompCount, p);
		break; }
	case 5: {
		Product p;
		InputNum("������� ���������", p.Price);
		res.base = res.BinSearch(CompPrice, p);
		break; }
	}
}

int FiltrType() {
	cout << "�� ������ �������� �����������?" << endl;
	int res=0;
	do {
		cout << "1 - �� ���� ����������� �� �����" << endl;
		cout << "2 - �� ����� ��������" << endl;
		cout << "3 - �� ���������� ������" << endl;
		cout << "4 - �� ����" << endl;
		cin >> res;
	} 
	while (res <= 0 || res > 4);
	return res;
}

bool ChooseType() {
	cout << "�������� ��� ������:" << endl;
	cout << "0 - ��������" << endl;
	cout << "1 - ��������" << endl;
	int ans;
	while (!(cin >> ans && (ans == 1 || ans == 0)));
	return ans == 1;
}


int main() {
	setlocale(LC_ALL, "Russian");

	string FileName;
	Base<Product> base;
	Base<Product> CurrentStock;
	int r;
	do {
		r = PrintMenu(base.Count()==0?2:10);
		switch (r) {
		case 1: {
			Product p;
			p.Input();
			if (base.Add(p))
				ShowMessage("������� ��������");
			break;
		}
		case 2: {
			Product p;
			InputNum("������� ��� ������", p.Code);
			if (base.Delete(p))
				ShowMessage("������� ������");
			else
				ShowMessage("������� �� ������");
			break;
		}
		case 3: {
			Product p;
			p.Input();
			if (base.Change(p))
				ShowMessage("������� �������");
			else
				ShowMessage("������� �� ������");
			break;
		}
		case 4: {
			Product p;
			InputNum("������� ��� ������", p.Code);
			Base<Product> result;
			if (ChooseType()) {

				result.Assign(base.LinSearch(CompCode,p));
			}
			else
			{
				result.Assign(base.BinSearch(CompCode, p));
			}
			result.Print();
			break;
		}
		case 5: {
			Product p;
			InputNum("������� ����� ������", p.NumOfStock);
			Base<Product> result;
			if (ChooseType()) {
				result.Assign(base.LinSearch(CompNumOfStock,p));
			}
			else
			{
				result.Assign(base.BinSearch(CompNumOfStock, p));
			}
			switch (FiltrType()) {
			case 1: {
				result.Sort(CompInputDate);
				break;
			}
			case 2: {
				result.Sort(CompOutPutDate);
				break;
			}
			case 3: {
				result.Sort(CompCount);
				break;
			}
			case 4: {
				result.Sort(CompPrice);
				break;
			}
			}
			result.Print();
			break;
		}
		case 6: {
			Product p;
			p.OutPutDate.Input("������� ������� ����");
			Base<Product> result;
			if (InputQuery("��������� ����� � ��������������� ����?")) {
				result.Assign(base.SortAndSearch_Life(p));
			}
			else
			{
				result.Assign(base.LinSearch_Life(p));
			}
			result.Print();
			if (InputQuery("���������� �������� � ����� �����?")) base = result;
			break;
		}
		case 7: {
			Product p;
			p.InputDate.Input("������� ����������� ����");
			Base<Product> result;
			if (ChooseType()) {
				result.Assign(base.LinSearch(CompInputDate, p));
			}
			else
			{
				result.Assign(base.BinSearch(CompInputDate, p));
			}
			result.Print();
			if (InputQuery("���������� �������� � ����� �����?")) base = result;
			break;
		}
		case 8: {
			base.Print();
			break;
		}
		case 9: {
			int ans = 1;
			Base<Product> res=base;
			cout << "�������� �������� ��� ������" << endl;
			while (ans == 1) {
				ChooseProductWithCriteries(res);
				res.Print();
				ans = (int)InputQuery("�������� ��� ��������?");
			}
			if (InputQuery("����������� ��������� �������� � ����� �����?")) {
				int stock;
				InputNum("������� ����� ������", stock);
				base.ChangeStockOfChoosenElems(res, stock);
			}
			break;
		}
		case 10: {
			ShowResultsForEachStock(base);
			break;
		}
		}
	} while (r != 0);
	return 0;
}


