// 
#include<iostream>
using namespace std;
int main()
{
	cout << "������9 * 9�ľ���ֵΪ1 - 9֮��" << endl;
	int a[9][9] = { 0 };
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cin >> a[i][j];
			if (a[i][j] > 0 && a[i][j] < 10) {
				continue;
			}
			else {
				if (cin.good() == 0) {
					cin.clear();
					cin.ignore(10000, '\n');
				}
				cout << "�����������"<<i+1<<"��"<<j+1<<"��(���о���1��ʼ����)��ֵ" << endl;
				if (j == 0) {
					j = 8;
					i -= 1;
				}
				else {
					j -= 1;
				}
				continue;
			}
		}
	}
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			for (int k = 0;k < 9;k++) {
				if (k!=j&&((a[i][j] == a[i][k])|| (a[j][i] == a[k][i]))) {
					cout << "���������Ľ�" << endl;
					return 0;
				}
			}
		}
	}
	for (int r = 0;r < 3;r++) {
		for (int c = 0;c < 3;c++) {
			bool b[10] = { false };
			for (int i = 0;i < 3;i++) {
				for (int j = 0;j < 3;j++) {
					int n=a[r * 3 + i][c * 3 + j];
					b[n - 1] = !b[n - 1];
					if (!b[n-1]) {
						cout << "���������Ľ�" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "�������Ľ�" << endl;

	return 0;
}