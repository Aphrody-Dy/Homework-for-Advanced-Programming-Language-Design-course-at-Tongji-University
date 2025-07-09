// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	const double Pi = 3.14159;
	int a, b, c;
	double s0;
	float s;

	printf("请输入三角形的两边即夹角(角度)\n");
	scanf("%d %d %d", &a, &b, &c);

	s0 = a * b * sin(c * Pi / 180) / 2;
	s = (float)s0;
	printf("三角形的面积为 : %.3f", s);

	return 0;
}
