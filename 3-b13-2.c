// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>
int main() {

	int y, m, d, w = 0, i, n = 1, k,ret1,ret2;

	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret1=scanf("%d%d", &y, &m);

		if ((y < 2000 || y>2030 || m < 1 || m>12) || (ret1 != 2)) {
			printf("����Ƿ�������������\n");
			if (ret1 != 2) {
				clearerr(stdin);
				scanf("%*[^\n]");
				scanf("%*c");
				continue;
			}
		}
		if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12) {
			break;
		}
	}

	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ",y,m);
		ret2=scanf("%d", &d);
		if ((d < 0 || d>6)||(ret2==0) ){
			printf("����Ƿ�������������\n");
			if (ret2 == 0) {
				clearerr(stdin);
				scanf("%*[^\n]");
				scanf("%*c");
				continue;
			}
		}
		else {
			break;
		}
	}


	printf("%d��%d�µ�����Ϊ:\n",y,m);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");

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

	printf("%*d",8*d+4,1);
	w += (8 * d + 4);
	for (n = 2; n <= k; n++) {
		for (i = 1;i <= 6;i++) {
			w += 1;
			printf(" ");
			if (w == 54) {
				printf("\n  ");
				w -= 52;
				break;
			}
		}
		if (n <= 9) {
			printf(" %d", n);
		}
		else {
			printf("%d", n);
		}
		w += 2;
	}

	return 0;
}
