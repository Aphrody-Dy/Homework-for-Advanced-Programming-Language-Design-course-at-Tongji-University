// 
#include<iostream>
#include<string>
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";
int test(int p1[],char pw[])
{
	int i = 0, j = 0, p2[5] = {0};
	if (strlen(pw) != p1[0]) {
		return 0;
	}
	for (i = 0;i < p1[0];i++) {
		if (int(pw[i]) >= int('A') && int(pw[i]) <= int('Z')) {
			p2[1]++;
			continue;
		}
		if (int(pw[i]) >= int('a') && int(pw[i]) <= int('z')) {
			p2[2]++;
			continue;
		}
		if (int(pw[i]) >= int('0') && int(pw[i]) <= int('9')) {
			p2[3]++;
			continue;
		}
		for (j = 0;j < 15;j++) {
			if (pw[i]==other[j]) {
				p2[4]++;
				break;
			}
		}
	}
	for (i = 1;i < 5;i++) {
		if (p2[i] < p1[i]) {
			return 0;
		}
	}
	return 1;
}
int main()
{
	int p1[5] = { 0 }, i = 0, b[10] = {0};
	char pw[17];
	cin.ignore(100, '\n');
	for (i = 0;i < 5;i++) {
		cin >> p1[i];
	}
	cin.ignore(100, '\n');
	for (i = 0;i < 10;i++) {
		cin.getline(pw, 17, '\n');
		if (test(p1, pw)) {
			b[i] = 1;
		}
	}
	for (i = 0;i < 10;i++) {
		if (!b[i]) {
			cout << "´íÎó" << endl;
			return 0;
		}
	}
	cout << "ÕýÈ·" << endl;
	return 0;
}