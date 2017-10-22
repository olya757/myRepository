#include <iostream>
#include <string>



using namespace std;
class Nex {
	char number[100];
private:
	
	int NumOfLet(char c) {
		if (c >= '0' && c <= '9')
			return (int)c - (int)'0';
		return (int)c - (int)'A' + 10;
	}
	char let[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	char one[100] = { '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	char zero[100] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
	
	Nex Ost(Nex a, Nex b, int p) {
		Nex copya = a;
		Nex D;
		while (MoreOrEqualThan(copya, b)) {
			copya = Diff(copya, b);
			D = Summ(D, one);
		}
		if (p == 0) return D;
		return copya;
	}
public:
	Nex() {
		setNex(zero);
	}
	Nex(char num[100]) {
		setNex(num);
	}

	int size() {
		int j = 99;
		for (; j >= 0 && number[j] == '0'; j--);
		return j + 1;
	}
	
	void setNex( char num[100]) {
		for (int i = 0; 0<100; i++)
			number[i] = num[i];
		
	}

	int NexToDec(Nex a) {
		int res = 0;
		for (int i = 0; i < a.size(); i++) {
			res = res * 16 + NumOfLet(a.number[i]);
		}
		return res;
	}

	bool isEqual(Nex a, Nex b) {
		if (a.size() != b.size()) return false;
		int i = 0;
		for (; i < a.size() && a.number[i] == b.number[i]; i++);
		if (i == a.size()) return true;
		return false;
	}

	bool MoreThan(Nex a, Nex b) {
		if (a.size() > b.size())
			return true;
		if (a.size() < b.size())
			return false;
		int i = a.size() - 1;
		while (i>=0 && a.number[i] == b.number[i]) {
			i--;
		}
		if (i < 0) return false;
		if (NumOfLet(a.number[i]) > NumOfLet(b.number[i]))
			return true;
		return false;
	}

	bool MoreOrEqualThan(Nex a, Nex b) {
		if (a.size() >= b.size())
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

	bool LessThan(Nex a, Nex b) {
		return MoreThan(b, a);
	}
	bool LessOrEqualThan(Nex a, Nex b) {
		return MoreOrEqualThan(b, a);
	}

	Nex Summ(Nex a, Nex b) {
		Nex res;
		char c;
		Nex minn;
		Nex maxx;
		if (a.size() > b.size()) {
			minn.setNex( b.number);
			maxx.setNex( a.number);
		}
		else {
			minn.setNex( a.number);
			maxx.setNex( b.number);
		}
				
		int x=0;
		int i = 0;
		int j = 0;
		for (; i < minn.size(); i++, j++) {
			int t = NumOfLet(a.number[i]) + NumOfLet(b.number[i])+x;
			res.number[j]=let[t % 16];
			x =  t / 16;
		}
		if (i == maxx.size() && x == 1) {
			res.number[j]='1';
			j++;
		}
		else
			for (; i < maxx.size();i++,j++) {
				int t = NumOfLet(maxx.number[i]) + x;
				res.number[j]=let[t % 16];
				x = t / 16;
			}
		for (; i < 100; i++) {
			res.number[i] = '0';
		}
		return res;
	}
	
	Nex Diff(Nex a, Nex b) {
		if (LessThan(a, b)) return zero;
		Nex res;
		char c;
			

		int x = 0;
		int i = 0;
		for (; i < b.size(); i++) {
			int t = NumOfLet(a.number[i]) - NumOfLet(b.number[i]) + x;
			if (t >= 0 ) {
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
				res.number[i]=let[t];
				x = 0;
			}
			for (; i < 100; i++) {
				res.number[i] = '0';
			}
		return res;

	}
	
	Nex Div(Nex a, Nex b) {
		return Ost(a,b,0);
	}

	Nex Mod(Nex a, Nex b) {
		return Ost(a, b, 1);
	}

	Nex Mult(Nex a, Nex b) {
		Nex copya = a;
		Nex res;
		for (; MoreThan(copya, zero); copya = Diff(copya, one)) {
			res = Summ(res, b);
		}
		return res;
	}

	

};


int main(){

	return 0;
}