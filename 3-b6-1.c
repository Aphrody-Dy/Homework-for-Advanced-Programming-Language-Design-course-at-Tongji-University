// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	double a, f;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, f1, f2;
	printf("������[0-100��)֮�������:\n");
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

	printf("��д�����:\n");

	//"��"
	if (a1 != 0 || a2 != 0) {
		if (a1 != 0 && a2 != 0) {
			switch (a1) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
			switch (a2) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		if (a1 != 0 && a2 == 0) {
			switch (a1) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ��");
		}
		if (a1 == 0 && a2 != 0) {
			switch (a2) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
	}

	//"��"
	if (a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
		if (a3 != 0 && a4 == 0 && a5 == 0 && a6 == 0) {
			switch (a3) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ��");
		}
		if (a3 == 0 && a4 != 0 && a5 == 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				printf("��");
			}
			switch (a4) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("����");
		}
		if (a3 == 0 && a4 == 0 && a5 != 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				printf("��");
			}
			switch (a5) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ��");
		}
		if (a3 == 0 && a4 == 0 && a5 == 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				printf("��");
			}
			switch (a6) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		if (a3 != 0 && a4 != 0 && a5 == 0 && a6 == 0) {
			switch (a3) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
			switch (a4) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("����");
		}
		if (a3 != 0 && a4 == 0 && a5 != 0 && a6 == 0) {
			switch (a3) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ��");
			switch (a5) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ��");
		}
		if (a3 != 0 && a4 == 0 && a5 == 0 && a6 != 0) {
			switch (a3) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ��");
			switch (a6) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		if (a3 == 0 && a4 != 0 && a5 != 0 && a6 == 0) {
			if (a1 != 0 || a2 != 0) {
				printf("��");
			}
			switch (a4) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
			switch (a5) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ��");
		}
		if (a3 == 0 && a4 != 0 && a5 == 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				printf("��");
			}
			switch (a4) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("����");
			switch (a6) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		if (a3 == 0 && a4 == 0 && a5 != 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				printf("��");
			}
			switch (a5) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
			switch (a6) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		if (a3 != 0 && a4 != 0 && a5 != 0 && a6 == 0) {
			switch (a3) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
			switch (a4) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
			switch (a5) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ��");
		}
		if (a3 != 0 && a4 != 0 && a5 == 0 && a6 != 0) {
			switch (a3) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
			switch (a4) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("����");
			switch (a6) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		if (a3 != 0 && a4 == 0 && a5 != 0 && a6 != 0) {
			switch (a3) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ��");
			switch (a5) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
			switch (a6) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		if (a3 == 0 && a4 != 0 && a5 != 0 && a6 != 0) {
			if (a1 != 0 || a2 != 0) {
				printf("��");
			}
			switch (a4) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
			switch (a5) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
			switch (a6) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		if (a3 != 0 && a4 != 0 && a5 != 0 && a6 != 0) {
			switch (a3) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
			switch (a4) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
			switch (a5) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
			switch (a6) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
	}
	if ((a1 != 0 || a2 != 0) && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0) {
		printf("��");
	}

	//��Բ��
	if (a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
		if (a7 != 0 && a8 == 0 && a9 == 0 && a10 == 0) {
			switch (a7) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
		}
		if (a7 == 0 && a8 != 0 && a9 == 0 && a10 == 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("��");
			}
			switch (a8) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		if (a7 == 0 && a8 == 0 && a9 != 0 && a10 == 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("��");
			}
			switch (a9) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
		}
		if (a7 == 0 && a8 == 0 && a9 == 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("��");
			}
			switch (a10) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 == 0 && a10 == 0) {
			switch (a7) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
			switch (a8) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		if (a7 != 0 && a8 == 0 && a9 != 0 && a10 == 0) {
			switch (a7) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ��");
			switch (a9) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
		}
		if (a7 != 0 && a8 == 0 && a9 == 0 && a10 != 0) {
			switch (a7) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ��");
			switch (a10) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
		}
		if (a7 == 0 && a8 != 0 && a9 != 0 && a10 == 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("��");
			}
			switch (a8) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
			switch (a9) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
		}
		if (a7 == 0 && a8 != 0 && a9 == 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("��");
			}
			switch (a8) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("����");
			switch (a10) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
		}
		if (a7 == 0 && a8 == 0 && a9 != 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("��");
			}
			switch (a9) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
			switch (a10) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 != 0 && a10 == 0) {
			switch (a7) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
			switch (a8) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
			switch (a9) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
		}
		if (a7 != 0 && a8 != 0 && a9 == 0 && a10 != 0) {
			switch (a7) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
			switch (a8) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("����");
			switch (a10) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
		}
		if (a7 != 0 && a8 == 0 && a9 != 0 && a10 != 0) {
			switch (a7) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ��");
			switch (a9) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
			switch (a10) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
		}
		if (a7 == 0 && a8 != 0 && a9 != 0 && a10 != 0) {
			if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0) {
				printf("��");
			}
			switch (a8) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
			switch (a9) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
			switch (a10) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
		}
		if (a7 != 0 && a8 != 0 && a9 != 0 && a10 != 0) {
			switch (a7) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
			switch (a8) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
			switch (a9) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
			switch (a10) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
		}
	}
	if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0 && a7 == 0 && a8 == 0 && a9 == 0 && a10 == 0 && f1 == 0 && f2 == 0) {
		printf("��");
	}
	//С��
	if (f1 == 0 && f2 == 0) {
		printf("Բ��");
	}
	if (f1 != 0 && f2 == 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			printf("Բ");
		}
		switch (f1) {
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("����");
	}
	if (f1 == 0 && f2 != 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			printf("Բ��");
		}
		switch (f2) {
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("��");
	}
	if (f1 != 0 && f2 != 0) {
		if (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0 || a7 != 0 || a8 != 0 || a9 != 0 || a10 != 0) {
			printf("Բ");
		}
		switch (f1) {
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("��");
		switch (f2) {
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("��");
	}
	
	return 0;

}
