// 
#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;
int main() {

	int y, m, d, w = 0, i, n = 1, k;

	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> y >> m;
		
		if (cin.good() == 1 && (y < 2000 || y>2030||m<1||m>12)) {
			cout << "输入非法，请重新输入" << endl;
		}
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if(y>=2000&&y<=2030&&m>=1&&m<=12){
			break;
		}
	}

	while (1) {
		cout << "请输入" << y << "年" << m << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> d;
		if (cin.good() == 1 && (d < 0 || d>6)) {
			cout << "输入非法，请重新输入" << endl;
		}
		else if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		else {
			break;
		}
	}
	

	cout <<"\n"<< y << "年" << m << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;

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
				cout <<endl<<"  ";
				w -= 52;
				break;
			}
		}
		if (n <= 9) {
			cout <<" "<< n;
		}
		else {
			cout << n;
		}
		w += 2;
	}

	return 0;
}
