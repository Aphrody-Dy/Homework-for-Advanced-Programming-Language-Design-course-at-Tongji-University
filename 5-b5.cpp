// 
#include<iostream>
using namespace std;
int main()
{
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	int a[1000],i,j,m=0,n=0;
	for (i = 0;i < 1000;i++) {
		a[i] = 0;
	}
	for (i = 0;i < 1000;i++) {
		cin >> a[i];
		m++;
		if (a[i] < 0) {
			m -= 1;
			break;
		}
	}
	if (a[0] < 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	cout << "输入的数组为:" << endl;
	for (i = 0;i < m;i++) {
		cout << a[i] << ' ';
		n++;
		if (n % 10 == 0) {
			cout << endl;
			n = 0;
		}
	}
	if (n) {
		cout << endl;
		n = 0;
	}
	cout << "分数与名次的对应关系为:" << endl;
	for (i = 0;i < m;i++) {
		for (j = 0;j < m - i;j++) {
			if (a[j] >= 0) {
				if (a[j] < a[j + 1]) {
					int t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}
		}
	}
	for (i = 0;i < m;i++) {
		n++;
		static int r=1;
		if (i == 0) {
			cout << a[i] << ' ' << r << endl;
		}
		if (a[i] == a[i + 1] && a[i] >= 0) {
			cout << a[i] << ' ' << r << endl;
		}
		if (a[i] != a[i + 1] && a[i+1] >= 0) {
			r = n+1;
			cout << a[i + 1] << ' ' << r << endl;
		}
	}
	return 0;
}