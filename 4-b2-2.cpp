// 
#include<iostream>
#include<cstdio>
#include<limits>
using namespace std;
int zeller(int y, int m, int d) {
	int c = 0, dm = 0, w = 0, i = 0;

	if (m == 1 || m == 2) {
		m += 12;
		y -= 1;
	}
	c = int(y / 100);
	y -= c*100;
	w = y + int(y / 4) + int(c / 4) - 2 * c + int(26 * (m + 1) / 10) + d - 1;
	if (w < 0) {
		for (i = 1; w < 0; i++) {
			w += 7 * i;
		}
	}
	w %= 7;
	return w;
}
void ch(int w) {
	switch (w) {
		case 0:
			cout << "��";
			break;
		case 1:
			cout << "һ";
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
			cout << "��";
			break;
	}
	cout << endl;
}
int main() {
	int y=0, m=0, d=0,dm=0;
	while (1) {
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;
		if (cin.fail()) {
			cout << "�����������������" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			continue;
		}
		if (y < 1900 || y>2100) {
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		if (m < 1 || m>12) {
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
		else {
			if (m == 2) {
				if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
					dm = 28;
				}
				else {
					dm = 29;
				}
			}
			else if (m == 4 || m == 6 || m == 9 || m == 11) {
				dm = 30;
			}
			else {
				dm = 31;
			}
		}
		if (d<1 || d>dm) {
			cout << "�ղ���ȷ������������" << endl;
			continue;
		}
		break;
	}
	cout << "����";
	ch(zeller(y, m, d));
	return 0;
}
