// 
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	const double Pi = 3.14159;
	int a, b, c;
	double s;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> c;

	s = a * b * sin(c * Pi / 180) / 2;
	cout << "�����ε����Ϊ : " << fixed << setprecision(3) << s << endl;
	
	return 0;
}