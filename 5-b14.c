// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main()
{
	const int WIDTH = 26;
	const int HEIGHT = 10;
	int i, j, k, n = 0;
	char a[10][26],b[10][26];
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 26;j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 26;j++) {
			b[i][j] = '0';
			if (a[i][j] == '*') {
				b[i][j] = '*';
			}
		}
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (a[i][j] == '*') {
				n++;
			}
		}
	}
	if (n != 50) {
		printf("´íÎó1\n");
		return 0;
	}
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (b[i][j] != '*') {
				n = 0;
				for (k = 0; k < 8; k++) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (ni >= 0 && ni < HEIGHT && nj >= 0 && nj < WIDTH) {
						if (b[ni][nj] == '*') {
							n++;
						}
					}
				}
				b[i][j] = (char)(n + (int)('0'));
			}
		}
	}
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 26;j++) {
			if (a[i][j] != b[i][j]) {
				printf("´íÎó2\n");
				return 0;
			}
		}
	}
	printf("ÕýÈ·");
	return 0;
}
