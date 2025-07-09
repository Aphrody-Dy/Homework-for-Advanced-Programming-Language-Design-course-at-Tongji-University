// 
#include <iostream>
using namespace std;
int main()
{
	int a[21], i, n;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;

	for (i = 0;i < 20;i++) {
		cin >> a[i];
		if (a[0] <= 0) {
			cout << "无有效输入" << endl;
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
	cout << "原数组为：" << endl;

	for (n = 0;n < i;n++) {
		cout << a[n] << ' ';
	}
	cout << endl;

	cout << "请输入要插入的正整数" << endl;
	cin >> a[n];
	cout << "插入后的数组为：" << endl;

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
