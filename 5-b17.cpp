// 
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";
void password(char pw[], int p1[], int p)
{
	int i = 0;
	int p2[4] = { 0 };
	for (i = 0;i < p;i++) {
		pw[i] = rand() % 4;
		p2[pw[i]]++;
	}
	for (i = 0;i < 4;i++) {
		while (p1[i] > p2[i]) {
			int t = rand()%p;
			if (pw[t] != i && p1[pw[t]]<p2[pw[t]]) {
				int z = pw[t];
				pw[t] = i;
				p2[z]--;
				p2[i]++;
			}
		}
	}
	for (i = 0;i < p;i++) {
		switch (pw[i]) {
			case 0:
				pw[i] = char(rand() % 26 + int('A'));
				break;
			case 1:
				pw[i] = char(rand() % 26 + int('a'));
				break;
			case 2:
				pw[i] = char(rand() % 10 + int('0'));
				break;
			case 3:
				pw[i] = other[rand() % 15];
		}
	}
}
int main()
{
	srand((unsigned int)(time(0)));
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	int p, i, j, p1[4] = { 0 };
	char pw[17];
	cin >> p;
	for (i = 0;i < 4;i++) {
		cin >> p1[i];
	}
	if (cin.good() != 1) {
		cout << "输入非法" << endl;
		return 0;
	}
	if (p < 12 || p>16) {
		cout << "密码长度[" << p << "]不正确" << endl;
		return 0;
	}
	if (p1[0]<2 || p1[0]>p) {
		cout << "大写字母个数[" << p1[0] << "]不正确" << endl;
		return 0;
	}
	if (p1[1]<2 || p1[1]>p) {
		cout << "小写字母个数[" << p1[1] << "]不正确" << endl;
		return 0;
	}
	if (p1[2]<2 || p1[2]>p) {
		cout << "数字个数[" << p1[2] << "]不正确" << endl;
		return 0;
	}
	if (p1[3]<2 || p1[3]>p) {
		cout << "其它符号个数[" << p1[3] << "]不正确" << endl;
		return 0;
	}
	if ((p1[0] + p1[1] + p1[2] + p1[3]) > p) {
		cout << "所有字符类型之和[" << p1[0] << "+" << p1[1] << "+" << p1[2] << "+" << p1[3] << "]大于总密码长度[" << p << "]" << endl;
		return 0;
	}
	cout << p << " " << p1[0] << " " << p1[1] << " " << p1[2] << " " << p1[3] << endl;
	pw[p] = '\0';
	for (i = 0;i < 10;i++) {
		password(pw, p1,p);
		for (j = 0;j < p;j++) {
			cout << pw[j];
		}
		cout << endl;
	}
	return 0;
}
