//
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	double a,f;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, f1, f2;

	cout << "������[0-100��]֮�������:" << endl;
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
	���������εõ�����ʹ�õ�3.81e-6

	double b, bp, bn, epsilon;		//bp��bn�ֱ�Ϊ����/С��b����ӽ�b�ĸ�����
	cin>>b;

	bp = nextafter(b, b + 1e2);
	bn = nextafter(b, b - 1e2);
	epsilon = bp - bn;

	cout << epsilon << fixed << setprecision(20) << endl;
	
	��������������ݼ���󣬵ñ������ݷ�Χ�����epsilonΪ3.81e-6���������ս������2λС����Ҫ���£���Ӱ������ָ����Χ�����ݵ������������ں���������ʹ�á�
	*/

	f1 = int((f+3.81e-6) * 10);
	f2 = int(((f+3.81e-6) * 10 - f1) * 10);

	cout << "ʮ��λ : " << a1 << endl;
	cout << "��λ   : " << a2 << endl;
	cout << "ǧ��λ : " << a3 << endl;
	cout << "����λ : " << a4 << endl;
	cout << "ʮ��λ : " << a5 << endl;
	cout << "��λ   : " << a6 << endl;
	cout << "ǧλ   : " << a7 << endl;
	cout << "��λ   : " << a8 << endl;
	cout << "ʮλ   : " << a9 << endl;
	cout << "Բ     : " << a10 << endl;
	cout << "��     : " << f1 << endl;
	cout << "��     : " << f2 << endl;


	return 0;

}