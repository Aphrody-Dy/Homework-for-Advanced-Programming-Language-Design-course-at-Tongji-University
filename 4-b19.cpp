//
#include<iostream>
using namespace std;


int min(int a, int b, int c=0, int d=0)
{
	if (c && d) {
		int t1 = a < b ? a : b;
		int t2 = c < d ? c : d;
		return (t1 > t2 ? t1 : t2);
	}
	else if (c && !d) {			
		int t1 = a < b ? a : b;
		return (t1 < c ? t1 : c);
	}
	else{
		return (a < b ? a : b);
	}

}
int main()
{
	int n, a, b, c = 1, d = 1, m = 0;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> n;
		if (n != 2 && n != 3 && n != 4) {
			cout << "个数输入错误" << endl;
			return 0;
		}
		if (n < 1) {
			continue;
		}
		if (n == 2) {
			cin >> a >> b;
			m = min(a, b);
		}
		if (n == 3) {
			cin >> a >> b >> c;
			m = min(a, b, c);
		}
		if (n == 4) {
			cin >> a >> b >> c >> d;
			m = min(a, b, c, d);
		}
		if (!cin.good() || a < 1 || b < 1 || c < 1 || d < 1) {
			cin.clear();
			cin.ignore(100000, '\n');
			continue;
		}
		else {
			break;
		}
	}

	cout << "min=" << m << endl;

	return 0;
}