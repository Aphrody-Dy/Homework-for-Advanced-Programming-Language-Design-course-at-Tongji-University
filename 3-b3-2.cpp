//
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	double a,f;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, f1, f2;

	cout << "请输入[0-100亿]之间的数字:" << endl;
	cin >> a;

	a1 = int(a / 1e9);
	a2 = int((a - a1*1e9) / 1e8);
	a3 = int((a - a1 * 1e9 - a2 * 1e8) / 1e7);
	a4 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7) / 1e6);
	a5 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6) / 1e5);
	a6 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5) / 1e4);
	a7 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4) / 1e3);
	a8 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3) / 1e2);
	a9 = int((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3 - a8 * 1e2) / 1e1);
	a10 = int(a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3 - a8 * 1e2 - a9 * 1e1);

	f = a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3 - a8 * 1e2 - a9 * 1e1 - a10;
	
	/*
	这里解释如何得到后续使用的3.81e-6

	double b, bp, bn, epsilon;		//bp、bn分别为大于/小于b且最接近b的浮点数
	cin>>b;

	bp = nextafter(b, b + 1e2);
	bn = nextafter(b, b - 1e2);
	epsilon = bp - bn;

	cout << epsilon << fixed << setprecision(20) << endl;
	
	依次输入测试数据计算后，得本题数据范围内最大epsilon为3.81e-6，且在最终结果保留2位小数的要求下，不影响其他指数范围内数据的输出结果，故在后续程序中使用。
	*/

	f1 = int((f+3.81e-6) * 10);
	f2 = int(((f+3.81e-6) * 10 - f1) * 10);

	cout << "十亿位 : " << a1 << endl;
	cout << "亿位   : " << a2 << endl;
	cout << "千万位 : " << a3 << endl;
	cout << "百万位 : " << a4 << endl;
	cout << "十万位 : " << a5 << endl;
	cout << "万位   : " << a6 << endl;
	cout << "千位   : " << a7 << endl;
	cout << "百位   : " << a8 << endl;
	cout << "十位   : " << a9 << endl;
	cout << "圆     : " << a10 << endl;
	cout << "角     : " << f1 << endl;
	cout << "分     : " << f2 << endl;


	return 0;

}