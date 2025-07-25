// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int y, m, d, n;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &y, &m, &d);

	//月份判断
	if (m > 12 || m < 1) {
		printf("输入错误-月份不正确\n");
		return 0;
	}

	//2月单独判断天数
	if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
		if (m == 2) {
			if (d > 28) {
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
	}
	else {
		if (m == 2) {
			if (d > 29) {
				printf("输入错误-日与月的关系非法\n");
				return 0;
			}
		}
	}

	//其他月份天数判断
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		if (d > 31 || d < 1) {
			printf("输入错误-日与月的关系非法\n");
			return 0;
		}
	}
	else {
		if (d > 30) {
			printf("输入错误-日与月的关系非法\n");
			return 0;
		}
	}

	//非闰年输入正确时的输出
	if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
		if (m == 1) {
			n = d;
		}
		else if (m == 2) {
			n = 31 + d;
		}
		else if (m == 3) {
			n = 59 + d;
		}
		else if (m == 4) {
			n = 90 + d;
		}
		else if (m == 5) {
			n = 120 + d;
		}
		else if (m == 6) {
			n = 151 + d;
		}
		else if (m == 7) {
			n = 181 + d;
		}
		else if (m == 8) {
			n = 212 + d;
		}
		else if (m == 9) {
			n = 243 + d;
		}
		else if (m == 10) {
			n = 273 + d;
		}
		else if (m == 11) {
			n = 304 + d;
		}
		else if (m == 12) {
			n = 334 + d;
		}
	}

	//闰年输入正确时的输出
	else {
		if (m == 1) {
			n = d;
		}
		else if (m == 2) {
			n = 31 + d;
		}
		else if (m == 3) {
			n = 60 + d;
		}
		else if (m == 4) {
			n = 91 + d;
		}
		else if (m == 5) {
			n = 121 + d;
		}
		else if (m == 6) {
			n = 152 + d;
		}
		else if (m == 7) {
			n = 182 + d;
		}
		else if (m == 8) {
			n = 213 + d;
		}
		else if (m == 9) {
			n = 244 + d;
		}
		else if (m == 10) {
			n = 274 + d;
		}
		else if (m == 11) {
			n = 305 + d;
		}
		else if (m == 12) {
			n = 335 + d;
		}
	}

	printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, n);

	return 0;
}
