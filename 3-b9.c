// 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(){
	int i, j;
	for (i = 1;i <= 9;i++) {
		for (j = 1;j <= i;j++) {
			if (j * i < 10) {
				printf("%dx%d=%d   ", j, i, j * i);
			}
			else {
				printf("%dx%d=%d  ", j, i, j * i);
			}
		}
		printf("\n");
	}
	return 0;
}
