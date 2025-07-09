// 
#include <iostream>
using namespace std;

void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
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

	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	cout << "大写结果是:" << endl;

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
	
	//"亿"
	daxie(a1, 0);
	if (a1) {
		cout << "拾";
	}
	daxie(a2, 0);
	if (a1 || a2) {
		cout << "亿";
	}

	//"万"
	if (a3 || a4 || a5 || a6) {
		z = a1 || a2;
		daxie(a3, z);
		if (a3) {
			cout << "仟";
		}
		z = (a3 && (a5 || a6));
		daxie(a4, z);
		if (a4) {
			cout << "佰";
		}
		z = (a4 && a6);
		daxie(a5, z);
		if (a5) {
			cout << "拾";
		}
		daxie(a6, 0);
		if (a3 || a4 || a5 || a6) {
			cout << "万";
		}
	}

	//"圆"
	if (a7 || a8 || a9 || a10) {
		z = a1 || a2 || a3 || a4 || a5 || a6;
		daxie(a7, z);
		if (a7) {
			cout << "仟";
		}
		z = (a7 && (a9 || a10));
		daxie(a8, z);
		if (a8) {
			cout << "佰";
		}
		z = (a8 && a10);
		daxie(a9, z);
		if (a9) {
			cout << "拾";
		}
		daxie(a10, 0);
	}
	if (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10) {
		cout << "圆";
		if (!f1 && !f2) {
			cout << "整";
		}
	}
	if (!a) {
		cout << "零圆整";
	}
	

	//小数部分
	if (f1 || f2) {
		z = a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10;
		daxie(f1, z);
		if (f1) {
			cout << "角";
			if (!f2) {
				cout << "整";
			}
		}
		daxie(f2, 0);
		if (f2) {
			cout << "分";
		}
	}
	cout << endl;
	return 0;
}
