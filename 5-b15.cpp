// 
#include <iostream>
using namespace std;
int main()
{
	char str[3][128];
	int i = 0,j=0,U = 0, L = 0, n = 0, s = 0, o = 0;

	for (i = 0;i < 3;i++) {
		cout << "�������"<<i+1<<"��" << endl;
		for (j = 0;j < 128;j++) {
			str[i][j] = getchar();
			if (str[i][j] >= int('A') && str[i][j] <= int('Z')) {
				U++;
			}
			else if (str[i][j] >= int('a') && str[i][j] <= int('z')) {
				L++;
			}
			else if (str[i][j] >= int('0') && str[i][j] <= int('9')) {
				n++;
			}
			else if (str[i][j] == 32) {
				s++;
			}
			else if (str[i][j] == 10) {
				break;
			}
			else {
				o++;
			}
		}
	}

	cout << "��д : " << U << endl;
	cout << "Сд : " << L << endl;
	cout << "���� : " << n << endl;
	cout << "�ո� : " << s << endl;
	cout << "���� : " << o << endl;

	return 0;
}