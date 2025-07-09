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
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> c;

	s = a * b * sin(c * Pi / 180) / 2;
	cout << "三角形的面积为 : " << fixed << setprecision(3) << s << endl;
	
	return 0;
}