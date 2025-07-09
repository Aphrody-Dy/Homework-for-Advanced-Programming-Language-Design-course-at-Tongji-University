// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	double a, f;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, f1, f2;

	printf("请输入[0-100亿]之间的数字:\n");
	scanf("%lf", &a);

	a1 = (int)(a / 1e9);
	a2 = (int)((a - a1 * 1e9) / 1e8);
	a3 = (int)((a - a1 * 1e9 - a2 * 1e8) / 1e7);
	a4 = (int)((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7) / 1e6);
	a5 = (int)((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6) / 1e5);
	a6 = (int)((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5) / 1e4);
	a7 = (int)((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4) / 1e3);
	a8 = (int)((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3) / 1e2);
	a9 = (int)((a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3 - a8 * 1e2) / 1e1);
	a10 = (int)(a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3 - a8 * 1e2 - a9 * 1e1);

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

	f1 = (int)((f + 3.81e-6) * 10);
	f2 = (int)(((f + 3.81e-6) * 10 - f1) * 10);

	printf("十亿位 : %d\n", a1);
	printf("亿位   : %d\n", a2);
	printf("千万位 : %d\n", a3);
	printf("百万位 : %d\n", a4);
	printf("十万位 : %d\n", a5);
	printf("万位   : %d\n", a6);
	printf("千位   : %d\n", a7);
	printf("百位   : %d\n", a8);
	printf("十位   : %d\n", a9);
	printf("圆     : %d\n", a10);
	printf("角     : %d\n", f1);
	printf("分     : %d\n", f2);

	return 0;
}
