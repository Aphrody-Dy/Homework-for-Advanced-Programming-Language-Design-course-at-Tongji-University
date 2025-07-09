// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	printf("请输入成绩（最多1000个），负数结束输入\n");
	int a[1000], i,j,n=0,m=0;
	for (i = 0;i < 1000;i++) {
		a[i] = 0;
	}
	for (i = 0;i < 1000;i++) {
		scanf("%d", &a[i]);
		m++;
		if (a[i] < 0) {
			if (i = 0) {
				printf("无有效输入\n");
				return 0;
			}
			else {
				m -= 1;
				break;
			}
		}
	}

	printf("输入的数组为:\n");
	for (i = 0;a[i] >= 0 && i < 1000;i++) {
		printf("%d ", a[i]);
		n++;
		if (n % 10 == 0) {
			printf("\n");
			n = 0;
		}
	}
	if (n) {
		printf("\n");
		n = 0;
	}
	printf("分数与人数的对应关系为:\n");
	for (i = 0;i < m;i++) {
		for (j = 0; j < m - i;j++) {
			if (a[j] < a[j + 1]) {
				int t = a[j];
				a[j] = a[j+1];
				a[j + 1] = t;
			}
		}
	}
	for (i = 0; i < m+1;i++) {
		if (a[i] == a[i + 1]) {
			n++;
		}
		else {
			if(a[i]>=0) {
				printf("%d %d\n", a[i], n + 1);
			}
			n = 0;
		}
	}
	return 0;
}
