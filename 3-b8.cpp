// 
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {

	while (true) {
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		int x, n = 0;
		double e = 0;
		cin >> x;

		if (x >= -10 && x <= 65) {
			while (fabs(pow(x,n) / tgamma(n + 1)) >= 1e-6) {
					e += pow(x,n) / tgamma(n + 1);
					n += 1;
			}
			cout << "e^" <<setprecision(10)<< x << "=" << e << endl;
			break;
		}
		else {
			cout << "����Ƿ�������������" << endl;
			continue;
		}
	}
	
	return 0;

}