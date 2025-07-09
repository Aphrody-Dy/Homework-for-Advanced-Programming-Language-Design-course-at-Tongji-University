// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x, n=0;

	while (1) {
		printf("请输入x的值[0-100] : ");
		ret = scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (ret == 1 && (x >= 0 && x <= 100))
			break;
		else {
			printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x); //确认一下，ret的值（即scanf的返回值）是什么含义:成功读取并复制变量的【个数】
			if (ret == 0) {
				clearerr(stdin);
				scanf("%*[^\n]");
				scanf("%*c");
				continue;
			}
		}
	}

	printf("ret=%d x=%d\n", ret, x);

	return 0;
}

