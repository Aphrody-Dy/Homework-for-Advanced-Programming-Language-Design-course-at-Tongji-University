// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int year(int y)
{
	if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
		return 0;
	}
	else {
		return 1;
	}
}
int day(int m2,int m,int d)
{
	int a[12][31],i,j,n=0;
	for (i = 0;i < 12;i++) {
		for (j = 0;j < 31;j++) {
			a[i][j] = 0;
		}
	}
	for (j = 0;j < 31;j++) {
		a[0][j] = j + 1;
		n++;
	}
	for (j = 0; j < m2;j++) {
		n++;
		a[1][j] = n;
	}
	for (j = 0; j < 31;j++) {
		n++;
		a[2][j] = n;
	}
	for (j = 0; j < 30;j++) {
		n++;
		a[3][j] = n;
	}
	for (j = 0; j < 31;j++) {
		n++;
		a[4][j] = n;
	}
	for (j = 0; j < 30;j++) {
		n++;
		a[5][j] = n;
	}
	for (j = 0; j < 31;j++) {
		n++;
		a[6][j] = n;
	}
	for (j = 0; j < 31;j++) {
		n++;
		a[7][j] = n;
	}
	for (j = 0; j < 30;j++) {
		n++;
		a[8][j] = n;
	}
	for (j = 0; j < 31;j++) {
		n++;
		a[9][j] = n;
	}
	for (j = 0; j < 30;j++) {
		n++;
		a[10][j] = n;
	}
	for (j = 0; j < 31;j++) {
		n++;
		a[11][j] = n;
	}
	if (d -1< 31) {
		return a[m - 1][d - 1];
	}
	else {
		return 0;
	}
}
int main()
{
	printf("请输入年，月，日\n");
	int y, m, d,m2,n;
	scanf("%d%d%d", &y, &m, &d);
	if (m < 1 || m>12) {
		printf("输入错误-月份不正确\n");
		return 0;
	}
	m2 = 28 + year(y);
	n = day(m2, m, d);
	if (!n) {
		printf("输入错误-日与月的关系非法\n");
	}
	else {
		printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);
	}
	return 0;
}
