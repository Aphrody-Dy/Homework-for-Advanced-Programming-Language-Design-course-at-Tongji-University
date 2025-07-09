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
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	int p, i, j, p1[4] = { 0 };
	char pw[17];
	cin >> p;
	for (i = 0;i < 4;i++) {
		cin >> p1[i];
	}
	if (cin.good() != 1) {
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (p < 12 || p>16) {
		cout << "���볤��[" << p << "]����ȷ" << endl;
		return 0;
	}
	if (p1[0]<2 || p1[0]>p) {
		cout << "��д��ĸ����[" << p1[0] << "]����ȷ" << endl;
		return 0;
	}
	if (p1[1]<2 || p1[1]>p) {
		cout << "Сд��ĸ����[" << p1[1] << "]����ȷ" << endl;
		return 0;
	}
	if (p1[2]<2 || p1[2]>p) {
		cout << "���ָ���[" << p1[2] << "]����ȷ" << endl;
		return 0;
	}
	if (p1[3]<2 || p1[3]>p) {
		cout << "�������Ÿ���[" << p1[3] << "]����ȷ" << endl;
		return 0;
	}
	if ((p1[0] + p1[1] + p1[2] + p1[3]) > p) {
		cout << "�����ַ�����֮��[" << p1[0] << "+" << p1[1] << "+" << p1[2] << "+" << p1[3] << "]���������볤��[" << p << "]" << endl;
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
