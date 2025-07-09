// 
#include <iostream>
#include <cmath>
using namespace std;
long long convert(char *pb,int L)
{
	long long d=0;
	for (int i=0;i<L;pb--,i++) {
		if (*pb=='1') {
			d += (long long) (pow(2, i));
		}
	}
	return d;
}
int main()
{
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	char b[33] = {0}, * pb;
	cin.getline(b, 33, '\n');
	int L = strlen(b);
	pb = b + L-1;
	cout << convert(pb,L) << endl;
}
