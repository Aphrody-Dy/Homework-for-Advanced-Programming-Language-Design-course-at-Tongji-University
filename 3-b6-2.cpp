// 
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	double a, f;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, f1, f2;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;

	a1 = int(a / 1e9);
	a2 = int((a - a1 * 1e9) / 1e8);
	a3 = int((a - a1 * 1e9 - a2 * 1e8) / 1e7);
	a4 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7) / 1e6);
	a5 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6) / 1e5);
	a6 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5) / 1e4);
	a7 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4) / 1e3);
	a8 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3) / 1e2);
	a9 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3 - a8 * 1e2) / 1e1);
	a10 = int(a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3 - a8 * 1e2 - a9 * 1e1);

	f = a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3 - a8 * 1e2 - a9 * 1e1 - a10;
	f1 = int((f + 3.81e-6) * 10);
	f2 = int(((f + 3.81e-6) * 10 - f1) * 10);

	cout << "��д�����:" << endl;

	//"��"
	if (a1 != 0 || a2 != 0) {
		if (a1 != 0 && a2 != 0) {
			switch (a1) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
			switch (a2) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		if (a1 != 0 && a2 == 0) {
			switch (a1) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ" << "��";
		}
		if (a1 == 0 && a2 != 0) {
			switch (a2) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
	}

	//"��"
	if (a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
		if (a3 != 0 && a4 == 0 && a5 == 0 && a6 == 0) {
			switch (a3) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ��";
		}
		if (a3 == 0 && a4 != 0 && a5 == 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "��";
			}
			switch (a4) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "����";
		}
		if (a3 == 0 && a4 == 0 && a5 != 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "��";
			}
			switch (a5) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ��";
		}
		if (a3 == 0 && a4 == 0 && a5 == 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "��";
			}
			switch (a6) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		if (a3 != 0 && a4 != 0 && a5 == 0 && a6 == 0) {
			switch (a3) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
			switch (a4) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "����";
		}
		if (a3 != 0 && a4 == 0 && a5 != 0 && a6 == 0) {
			switch (a3) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ��";
			switch (a5) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ��";
		}
		if (a3 != 0 && a4 == 0 && a5 == 0 && a6 != 0) {
			switch (a3) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ��";
			switch (a6) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		if (a3 == 0 && a4 != 0 && a5 != 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "��";
			}
			switch (a4) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
			switch (a5) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ��";
		}
		if (a3 == 0 && a4 != 0 && a5 == 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "��";
			}
			switch (a4) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "����";
			switch (a6) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		if (a3 == 0 && a4 == 0 && a5 != 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "��";
			}
			switch (a5) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
			switch (a6) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		if (a3 != 0 && a4 != 0 && a5 != 0 && a6 == 0) {
			switch (a3) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
			switch (a4) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
			switch (a5) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ��";
		}
		if (a3 != 0 && a4 != 0 && a5 == 0 && a6 != 0) {
			switch (a3) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
			switch (a4) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "����";
			switch (a6) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		if (a3 != 0 && a4 == 0 && a5 != 0 && a6 != 0) {
			switch (a3) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ��";
			switch (a5) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
			switch (a6) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		if (a3 == 0 && a4 != 0 && a5 != 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "��";
			}
			switch (a4) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
			switch (a5) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
			switch (a6) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		if (a3 != 0 && a4 != 0 && a5 != 0 && a6 != 0) {
			switch (a3) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
			switch (a4) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
			switch (a5) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
			switch (a6) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
	}
	if ((a1 != 0 || a2 != 0) && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0) {
		cout << "��";
	}

	//��Բ��
	if (a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
		if (a7 != 0 && a8 == 0 && a9 == 0 && a10 == 0) {
			switch (a7) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
		}
		if (a7 == 0 && a8 != 0 && a9 == 0 && a10 == 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "��";
			}
			switch (a8) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		if (a7 == 0 && a8 == 0 && a9 != 0 && a10 == 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "��";
			}
			switch (a9) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
		}
		if (a7 == 0 && a8 == 0 && a9 == 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "��";
			}
			switch (a10) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 == 0 && a10 == 0) {
			switch (a7) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
			switch (a8) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		if (a7 != 0 && a8 == 0 && a9 != 0 && a10 == 0) {
			switch (a7) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ��";
			switch (a9) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
		}
		if (a7 != 0 && a8 == 0 && a9 == 0 && a10 != 0) {
			switch (a7) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ��";
			switch (a10) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
		}
		if (a7 == 0 && a8 != 0 && a9 != 0 && a10 == 0) {
			if(a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "��";
			}
			switch (a8) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
			switch (a9) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
		}
		if (a7 == 0 && a8 != 0 && a9 == 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "��";
			}
			switch (a8) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "����";
			switch (a10) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
		}
		if (a7 == 0 && a8 == 0 && a9 != 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "��";
			}
			switch (a9) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
			switch (a10) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 != 0 && a10 == 0) {
			switch (a7) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
			switch (a8) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
			switch (a9) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
		}
		if (a7 != 0 && a8 != 0 && a9 == 0 && a10 != 0) {
			switch (a7) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
			switch (a8) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "����";
			switch (a10) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
		}
		if (a7 != 0 && a8 == 0 && a9 != 0 && a10 != 0) {
			switch (a7) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ��";
			switch (a9) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
			switch (a10) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
		}
		if (a7 == 0 && a8 != 0 && a9 != 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "��";
			}
			switch (a8) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
			switch (a9) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
			switch (a10) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 != 0 && a10 != 0) {
			switch (a7) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
			switch (a8) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
			switch (a9) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
			switch (a10) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
		}	
	}
	if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0 && a7 == 0 && a8 == 0 && a9 == 0 && a10 == 0&&f1==0&&f2==0) {
		cout << "��";
	}
	//С��
	if (f1 == 0 && f2 == 0) {
		cout << "Բ��";
	}
	if (f1 != 0 && f2 == 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			cout << "Բ";
		}
		switch (f1) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
		}
		cout << "����";
	}
	if (f1 == 0 && f2 != 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			cout << "Բ��";
		}
		switch (f2) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
		}
		cout << "��";
	}
	if (f1 != 0 && f2 != 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			cout << "Բ";
		}
		switch (f1) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
		}
		cout << "��";
		switch (f2) {
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
		}
		cout << "��";
	}
	cout<<'\n'; 
	return 0;

}
