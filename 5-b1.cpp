// 
#include <iostream>
using namespace std;
int main()
{
	int a[21], i, n;
	cout << "��������������������������20������0������������" << endl;

	for (i = 0;i < 20;i++) {
		cin >> a[i];
		if (a[0] <= 0) {
			cout << "����Ч����" << endl;
			return 0;
		}
		if (a[i] > 0) {
			continue;
		}
		else {
			break;
		}
	}
	cin.ignore(10000, '\n');
	cout << "ԭ����Ϊ��" << endl;

	for (n = 0;n < i;n++) {
		cout << a[n] << ' ';
	}
	cout << endl;

	cout << "������Ҫ�����������" << endl;
	cin >> a[n];
	cout << "����������Ϊ��" << endl;

	for (i = 0;i < n;i++) {
		for (int j = 0;j < n- i;j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	for (i = 0;i < n + 1;i++) {
		cout << a[i] << ' ';
	}
	cout << endl;

	return 0;
}
