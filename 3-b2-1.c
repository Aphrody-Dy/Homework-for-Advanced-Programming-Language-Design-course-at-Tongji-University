// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a, a1, a2, a3, a4, a5;
	printf("请输入一个[1..30000]间的整数:\n");
	scanf("%d", &a);

	a1 = a / 10000;
	a2 = (a - a1 * 10000) / 1000;
	a3 = (a - a1 * 10000 - a2 * 1000) / 100;
	a4 = (a - a1 * 10000 - a2 * 1000 - a3 * 100) / 10;
	a5 = a - a1 * 10000 - a2 * 1000 - a3 * 100 - a4 * 10;

	printf("万位 : %d\n", a1);
	printf("千位 : %d\n", a2);
	printf("百位 : %d\n", a3);
	printf("十位 : %d\n", a4);
	printf("个位 : %d\n", a5);

	return 0;
}
