// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void input(char id[][7], char name[][8], int s[])
{
	int i = 0, j = 0;
	for (i = 0;i < 10;i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		for (j = 0;j < 7;j++) {
			id[i][j] = getchar();
		}
		while (getchar() == '\n');
		for (j = 0;j < 8;j++) {
			name[i][j] = getchar();
			if ((int)(name[i][j]) == 32) {
				name[i][j] = '\0';
				break;
			}
		}
		scanf("%d", &s[i]);
		getchar();
	}
}
void exchange(char id[][7], char name[][8], int s[], int a, int b)
{
	char c[8];
	int i = 0, j = 0, t;
	t = s[a];
	s[a] = s[b];
	s[b] = t;
	for (i = 0;i < 7;i++) {
		c[i] = id[a][i];
	}
	for (i = 0;i < 7;i++) {
		id[a][i] = id[b][i];
	}
	for (i = 0;i < 7;i++) {
		id[b][i] = c[i];
	}
	for (i = 0;i < 7;i++) {
		c[i] = name[a][i];
	}
	for (i = 0;i < 7;i++) {
		name[a][i] = name[b][i];
	}
	for (i = 0;i < 7;i++) {
		name[b][i] = c[i];
	}
}
void sort(char id[][7], char name[][8], int s[])
{
	int id1[10] = { 0 },i=0,j=0;
	for (i = 0;i < 10;i++) {
		for (j = 0;j < 7;j++) {
			id1[i] += (id[i][j]-(int)('0')) * (int)(pow(10, 6 - j));
		}
	}
	for (i = 0;i < 9;i++) {
		for (j = 0;j < 9 - i;j++) {
			if (id1[j] < id1[j + 1]) {
				exchange(id, name, s,j,j+1);
				int t = id1[j];
				id1[j] = id1[j + 1];
				id1[j + 1] = t;
			}
		}
	}
}
void output(char id[][7],char name[][8],int s[])
{
	printf("\n及格名单(学号降序):\n");
	for (int i = 0;i < 10;i++) {
		if (s[i] >= 60) {
			for (int j = 0;j < 8;j++) {
				printf("%c", name[i][j]);
				if (name[i][j] == '\0') {
					printf(" ");
					break;
				}
			}
			for (int j = 0;j < 7;j++) {
				printf("%c", id[i][j]);
			}
			printf(" ");
			printf("%d\n", s[i]);
		}
	}
}
int main()
{
	char id[10][7], name[10][8];
	int s[10];

	input(id, name, s);
	sort(id, name, s);
	output(id, name, s);

	return 0;
}
