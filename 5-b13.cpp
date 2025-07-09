// 
#include<iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
int main()
{
	const int WIDTH = 26;
	const int HEIGHT = 10;
	int i, j, k, n=0;
	char a[HEIGHT][WIDTH];
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 26;j++) {
			a[i][j]='0';
		}
	}
	srand((unsigned int)(time(0)));
	for (i = 0;i < 50;i++) {
		int w, h;
		while (1) {
			h = rand() % HEIGHT;
			w = rand() % WIDTH;
			if (a[h][w] == '*') {
				continue;
			}
			else {
				break;
			}
		}
		a[h][w] = '*';
	}
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (a[i][j] != '*') {
				n = 0;
				for (k = 0; k < 8; k++) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (ni >= 0 && ni < HEIGHT && nj >= 0 && nj < WIDTH) {
						if (a[ni][nj] == '*') {
							n++;
						}
					}
				}
				a[i][j] = char(n+int('0'));
			}
		}
	}

	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 26;j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
