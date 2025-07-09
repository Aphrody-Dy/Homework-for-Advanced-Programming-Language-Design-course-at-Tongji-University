// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	double a, f;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, f1, f2;
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
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
	a10 =(int)(a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3 - a8 * 1e2 - a9 * 1e1);

	f = a - a1 * 1e9 - a2 * 1e8 - a3 * 1e7 - a4 * 1e6 - a5 * 1e5 - a6 * 1e4 - a7 * 1e3 - a8 * 1e2 - a9 * 1e1 - a10;
	f1 = (int)((f + 3.81e-6) * 10);
	f2 = (int)(((f + 3.81e-6) * 10 - f1) * 10);

	printf("´óÐ´½á¹ûÊÇ:\n");

	//"ÒÚ"
	if (a1 != 0 || a2 != 0) {
		if (a1 != 0 && a2 != 0) {
			switch (a1) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
			switch (a2) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("ÒÚ");
		}
		if (a1 != 0 && a2 == 0) {
			switch (a1) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°ÒÚ");
		}
		if (a1 == 0 && a2 != 0) {
			switch (a2) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("ÒÚ");
		}
	}

	//"Íò"
	if (a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
		if (a3 != 0 && a4 == 0 && a5 == 0 && a6 == 0) {
			switch (a3) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("ÇªÍò");
		}
		if (a3 == 0 && a4 != 0 && a5 == 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				printf("Áã");
			}
			switch (a4) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°ÛÍò");
		}
		if (a3 == 0 && a4 == 0 && a5 != 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				printf("Áã");
			}
			switch (a5) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°Íò");
		}
		if (a3 == 0 && a4 == 0 && a5 == 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				printf("Áã");
			}
			switch (a6) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Íò");
		}
		if (a3 != 0 && a4 != 0 && a5 == 0 && a6 == 0) {
			switch (a3) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
			switch (a4) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°ÛÍò");
		}
		if (a3 != 0 && a4 == 0 && a5 != 0 && a6 == 0) {
			switch (a3) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("ÇªÁã");
			switch (a5) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°Íò");
		}
		if (a3 != 0 && a4 == 0 && a5 == 0 && a6 != 0) {
			switch (a3) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("ÇªÁã");
			switch (a6) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Íò");
		}
		if (a3 == 0 && a4 != 0 && a5 != 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				printf("Áã");
			}
			switch (a4) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
			switch (a5) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°Íò");
		}
		if (a3 == 0 && a4 != 0 && a5 == 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				printf("Áã");
			}
			switch (a4) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°ÛÁã");
			switch (a6) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Íò");
		}
		if (a3 == 0 && a4 == 0 && a5 != 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				printf("Áã");
			}
			switch (a5) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
			switch (a6) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Íò");
		}
		if (a3 != 0 && a4 != 0 && a5 != 0 && a6 == 0) {
			switch (a3) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
			switch (a4) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
			switch (a5) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°Íò");
		}
		if (a3 != 0 && a4 != 0 && a5 == 0 && a6 != 0) {
			switch (a3) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
			switch (a4) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°ÛÁã");
			switch (a6) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Íò");
		}
		if (a3 != 0 && a4 == 0 && a5 != 0 && a6 != 0) {
			switch (a3) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("ÇªÁã");
			switch (a5) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
			switch (a6) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Íò");
		}
		if (a3 == 0 && a4 != 0 && a5 != 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				printf("Áã");
			}
			switch (a4) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
			switch (a5) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
			switch (a6) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Íò");
		}
		if (a3 != 0 && a4 != 0 && a5 != 0 && a6 != 0) {
			switch (a3) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
			switch (a4) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
			switch (a5) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
			switch (a6) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Íò");
		}
	}
	if ((a1 != 0 || a2 != 0) && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0) {
		printf("Áã");
	}

	//¡°Ô²¡±
	if (a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
		if (a7 != 0 && a8 == 0 && a9 == 0 && a10 == 0) {
			switch (a7) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
		}
		if (a7 == 0 && a8 != 0 && a9 == 0 && a10 == 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("Áã");
			}
			switch (a8) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
		}
		if (a7 == 0 && a8 == 0 && a9 != 0 && a10 == 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("Áã");
			}
			switch (a9) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
		}
		if (a7 == 0 && a8 == 0 && a9 == 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("Áã");
			}
			switch (a10) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 == 0 && a10 == 0) {
			switch (a7) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
			switch (a8) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
		}
		if (a7 != 0 && a8 == 0 && a9 != 0 && a10 == 0) {
			switch (a7) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("ÇªÁã");
			switch (a9) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
		}
		if (a7 != 0 && a8 == 0 && a9 == 0 && a10 != 0) {
			switch (a7) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("ÇªÁã");
			switch (a10) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
		}
		if (a7 == 0 && a8 != 0 && a9 != 0 && a10 == 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("Áã");
			}
			switch (a8) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
			switch (a9) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
		}
		if (a7 == 0 && a8 != 0 && a9 == 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("Áã");
			}
			switch (a8) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°ÛÁã");
			switch (a10) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
		}
		if (a7 == 0 && a8 == 0 && a9 != 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("Áã");
			}
			switch (a9) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
			switch (a10) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 != 0 && a10 == 0) {
			switch (a7) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
			switch (a8) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
			switch (a9) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
		}
		if (a7 != 0 && a8 != 0 && a9 == 0 && a10 != 0) {
			switch (a7) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
			switch (a8) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°ÛÁã");
			switch (a10) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
		}
		if (a7 != 0 && a8 == 0 && a9 != 0 && a10 != 0) {
			switch (a7) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("ÇªÁã");
			switch (a9) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
			switch (a10) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
		}
		if (a7 == 0 && a8 != 0 && a9 != 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("Áã");
			}
			switch (a8) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
			switch (a9) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
			switch (a10) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 != 0 && a10 != 0) {
			switch (a7) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
			switch (a8) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
			switch (a9) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
			switch (a10) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
		}
	}
	if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0 && a7 == 0 && a8 == 0 && a9 == 0 && a10 == 0 && f1 == 0 && f2 == 0) {
		printf("Áã");
	}
	//Ð¡Êý
	if (f1 == 0 && f2 == 0) {
		printf("Ô²Õû");
	}
	if (f1 != 0 && f2 == 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			printf("Ô²");
		}
		switch (f1) {
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("½ÇÕû");
	}
	if (f1 == 0 && f2 != 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			printf("Ô²Áã");
		}
		switch (f2) {
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("·Ö");
	}
	if (f1 != 0 && f2 != 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			printf("Ô²");
		}
		switch (f1) {
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("½Ç");
		switch (f2) {
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("·Ö");
	}
	
	return 0;

}
