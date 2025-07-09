// 
#include<iostream>
using namespace std;

int max(int a,int b)
{
	return (a > b ? a : b);
}
int max(int a, int b,int c)
{
	int t;
	t = a > b ? a : b;
	return (t > c ? t : c);
}
int max(int a, int b,int c,int d)
{
	int t1, t2;
	t1 = a > b ? a : b;
	t2 = c > d ? c : d;
	return (t1 > t2 ? t1 : t2);
}
int main() 
{
	int n,a, b, c=1,d=1,m=0;
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
			m = max(a, b);
		}
		if (n == 3) {
			cin >> a >> b >> c;
			m = max(a, b, c);
		}
		if (n == 4) {
			cin >> a >> b >> c >> d;
			m = max(a, b, c, d);
		}
		if (!cin.good()||a<1||b<1||c<1||d<1) {
			cin.clear();
			cin.ignore(100000, '\n');
			continue;
		}
		else {
			break;
		}
	}
	
	cout << "max=" << m << endl;
	
	return 0;
}