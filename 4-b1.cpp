// 
#include <iostream>
using namespace std;

void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
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
		default:
			cout << "error";
			break;
	}
}

int main()
{
	bool z=1;
	double a, f;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, f1, f2;

	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	cout << "��д�����:" << endl;

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
	
	//"��"
	daxie(a1, 0);
	if (a1) {
		cout << "ʰ";
	}
	daxie(a2, 0);
	if (a1 || a2) {
		cout << "��";
	}

	//"��"
	if (a3 || a4 || a5 || a6) {
		z = a1 || a2;
		daxie(a3, z);
		if (a3) {
			cout << "Ǫ";
		}
		z = (a3 && (a5 || a6));
		daxie(a4, z);
		if (a4) {
			cout << "��";
		}
		z = (a4 && a6);
		daxie(a5, z);
		if (a5) {
			cout << "ʰ";
		}
		daxie(a6, 0);
		if (a3 || a4 || a5 || a6) {
			cout << "��";
		}
	}

	//"Բ"
	if (a7 || a8 || a9 || a10) {
		z = a1 || a2 || a3 || a4 || a5 || a6;
		daxie(a7, z);
		if (a7) {
			cout << "Ǫ";
		}
		z = (a7 && (a9 || a10));
		daxie(a8, z);
		if (a8) {
			cout << "��";
		}
		z = (a8 && a10);
		daxie(a9, z);
		if (a9) {
			cout << "ʰ";
		}
		daxie(a10, 0);
	}
	if (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10) {
		cout << "Բ";
		if (!f1 && !f2) {
			cout << "��";
		}
	}
	if (!a) {
		cout << "��Բ��";
	}
	

	//С������
	if (f1 || f2) {
		z = a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10;
		daxie(f1, z);
		if (f1) {
			cout << "��";
			if (!f2) {
				cout << "��";
			}
		}
		daxie(f2, 0);
		if (f2) {
			cout << "��";
		}
	}
	cout << endl;
	return 0;
}
