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
			cout << "日";
			break;
		case 1:
			cout << "一";
			break;
		case 2:
			cout << "二";
			break;
		case 3:
			cout << "三";
			break;
		case 4:
			cout << "四";
			break;
		case 5:
			cout << "五";
			break;
		case 6:
			cout << "六";
			break;
	}
	cout << endl;
}
int main() {
	int y=0, m=0, d=0,dm=0;
	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;
		if (cin.fail()) {
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			continue;
		}
		if (y < 1900 || y>2100) {
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		if (m < 1 || m>12) {
			cout << "月份不正确，请重新输入" << endl;
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
			cout << "日不正确，请重新输入" << endl;
			continue;
		}
		break;
	}
	cout << "星期";
	ch(zeller(y, m, d));
	return 0;
}
