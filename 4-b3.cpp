// 
#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;

int zeller(int y, int m, int d) {
	int c = 0, dm = 0, w = 0, i = 0;

	if (m == 1 || m == 2) {
		m += 12;
		y -= 1;
	}
	c = int(y / 100);
	y -= c * 100;
	w = y + int(y / 4) + int(c / 4) - 2 * c + int(26 * (m + 1) / 10) + d - 1;
	if (w < 0) {
		for (i = 1; w < 0; i++) {
			w += 7 * i;
		}
	}
	w %= 7;
	return w;
}

void calendar(int y,int m, int d) {

	int w = 0, i = 0, k = 0, n = 0;

	cout <<endl<< y << "年" << m << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	if (m == 2) {
		if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
			k = 28;
		}
		else {
			k = 29;
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		k = 30;
	}
	else {
		k = 31;
	}

	cout << setw(8 * d + 3) << " " << 1;
	w += (8 * d + 4);
	for (n = 2; n <= k; n++) {
		for (i = 1;i <= 6;i++) {
			w += 1;
			cout << ' ';
			if (w == 54) {
				cout << endl << "  ";
				w -= 52;
				break;
			}
		}
		if (n <= 9) {
			cout << " " << n;
		}
		else {
			cout << n;
		}
		w += 2;
	}
	cout <<endl<< "======================================================" << endl;
}

int main() {

	int y, m, w = 0, i = 0, n = 1, k = 0;

	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m;

		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (y < 1900 || y>2100) {
			cout << "年份不正确，请重新输入" << endl;
		}
		if ( m < 1 || m>12) {
			cout << "月份不正确，请重新输入" << endl;
		}
		if (y >= 1900 && y <= 2100 && m >= 1 && m <= 12) {
			break;
		}
	}
	calendar(y, m, zeller(y, m, 1));
	return 0;
}
