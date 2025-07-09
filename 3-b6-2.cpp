// 
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	double a, f;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, f1, f2;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
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

	cout << "´óĞ´½á¹ûÊÇ:" << endl;

	//"ÒÚ"
	if (a1 != 0 || a2 != 0) {
		if (a1 != 0 && a2 != 0) {
			switch (a1) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
			switch (a2) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "ÒÚ";
		}
		if (a1 != 0 && a2 == 0) {
			switch (a1) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°" << "ÒÚ";
		}
		if (a1 == 0 && a2 != 0) {
			switch (a2) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "ÒÚ";
		}
	}

	//"Íò"
	if (a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
		if (a3 != 0 && a4 == 0 && a5 == 0 && a6 == 0) {
			switch (a3) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "ÇªÍò";
		}
		if (a3 == 0 && a4 != 0 && a5 == 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "Áã";
			}
			switch (a4) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°ÛÍò";
		}
		if (a3 == 0 && a4 == 0 && a5 != 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "Áã";
			}
			switch (a5) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°Íò";
		}
		if (a3 == 0 && a4 == 0 && a5 == 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "Áã";
			}
			switch (a6) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Íò";
		}
		if (a3 != 0 && a4 != 0 && a5 == 0 && a6 == 0) {
			switch (a3) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
			switch (a4) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°ÛÍò";
		}
		if (a3 != 0 && a4 == 0 && a5 != 0 && a6 == 0) {
			switch (a3) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "ÇªÁã";
			switch (a5) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°Íò";
		}
		if (a3 != 0 && a4 == 0 && a5 == 0 && a6 != 0) {
			switch (a3) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "ÇªÁã";
			switch (a6) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Íò";
		}
		if (a3 == 0 && a4 != 0 && a5 != 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "Áã";
			}
			switch (a4) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
			switch (a5) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°Íò";
		}
		if (a3 == 0 && a4 != 0 && a5 == 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "Áã";
			}
			switch (a4) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°ÛÁã";
			switch (a6) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Íò";
		}
		if (a3 == 0 && a4 == 0 && a5 != 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "Áã";
			}
			switch (a5) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
			switch (a6) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Íò";
		}
		if (a3 != 0 && a4 != 0 && a5 != 0 && a6 == 0) {
			switch (a3) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
			switch (a4) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
			switch (a5) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°Íò";
		}
		if (a3 != 0 && a4 != 0 && a5 == 0 && a6 != 0) {
			switch (a3) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
			switch (a4) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°ÛÁã";
			switch (a6) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Íò";
		}
		if (a3 != 0 && a4 == 0 && a5 != 0 && a6 != 0) {
			switch (a3) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "ÇªÁã";
			switch (a5) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
			switch (a6) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Íò";
		}
		if (a3 == 0 && a4 != 0 && a5 != 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				cout << "Áã";
			}
			switch (a4) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
			switch (a5) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
			switch (a6) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Íò";
		}
		if (a3 != 0 && a4 != 0 && a5 != 0 && a6 != 0) {
			switch (a3) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
			switch (a4) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
			switch (a5) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
			switch (a6) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Íò";
		}
	}
	if ((a1 != 0 || a2 != 0) && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0) {
		cout << "Áã";
	}

	//¡°Ô²¡±
	if (a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
		if (a7 != 0 && a8 == 0 && a9 == 0 && a10 == 0) {
			switch (a7) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
		}
		if (a7 == 0 && a8 != 0 && a9 == 0 && a10 == 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "Áã";
			}
			switch (a8) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
		}
		if (a7 == 0 && a8 == 0 && a9 != 0 && a10 == 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "Áã";
			}
			switch (a9) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
		}
		if (a7 == 0 && a8 == 0 && a9 == 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "Áã";
			}
			switch (a10) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 == 0 && a10 == 0) {
			switch (a7) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
			switch (a8) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
		}
		if (a7 != 0 && a8 == 0 && a9 != 0 && a10 == 0) {
			switch (a7) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "ÇªÁã";
			switch (a9) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
		}
		if (a7 != 0 && a8 == 0 && a9 == 0 && a10 != 0) {
			switch (a7) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "ÇªÁã";
			switch (a10) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
		}
		if (a7 == 0 && a8 != 0 && a9 != 0 && a10 == 0) {
			if(a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "Áã";
			}
			switch (a8) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
			switch (a9) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
		}
		if (a7 == 0 && a8 != 0 && a9 == 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "Áã";
			}
			switch (a8) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°ÛÁã";
			switch (a10) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
		}
		if (a7 == 0 && a8 == 0 && a9 != 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "Áã";
			}
			switch (a9) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
			switch (a10) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 != 0 && a10 == 0) {
			switch (a7) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
			switch (a8) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
			switch (a9) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
		}
		if (a7 != 0 && a8 != 0 && a9 == 0 && a10 != 0) {
			switch (a7) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
			switch (a8) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°ÛÁã";
			switch (a10) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
		}
		if (a7 != 0 && a8 == 0 && a9 != 0 && a10 != 0) {
			switch (a7) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "ÇªÁã";
			switch (a9) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
			switch (a10) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
		}
		if (a7 == 0 && a8 != 0 && a9 != 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				cout << "Áã";
			}
			switch (a8) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
			switch (a9) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
			switch (a10) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 != 0 && a10 != 0) {
			switch (a7) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
			switch (a8) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
			switch (a9) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
			switch (a10) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
		}	
	}
	if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0 && a7 == 0 && a8 == 0 && a9 == 0 && a10 == 0&&f1==0&&f2==0) {
		cout << "Áã";
	}
	//Ğ¡Êı
	if (f1 == 0 && f2 == 0) {
		cout << "Ô²Õû";
	}
	if (f1 != 0 && f2 == 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			cout << "Ô²";
		}
		switch (f1) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
		}
		cout << "½ÇÕû";
	}
	if (f1 == 0 && f2 != 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			cout << "Ô²Áã";
		}
		switch (f2) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
		}
		cout << "·Ö";
	}
	if (f1 != 0 && f2 != 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			cout << "Ô²";
		}
		switch (f1) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
		}
		cout << "½Ç";
		switch (f2) {
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
		}
		cout << "·Ö";
	}
	cout<<'\n'; 
	return 0;

}
