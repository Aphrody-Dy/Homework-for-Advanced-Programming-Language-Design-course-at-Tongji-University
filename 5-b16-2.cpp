// 
#include<iostream>
#include<cmath>
using namespace std;
void input(string id[], string name[], int s[])
{
	int i = 0, j = 0;
	for (i = 0;i < 10;i++) {
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		for (j = 0;j < 7;j++) {
			id[i] += getchar();
		}
		getchar();
		for (j = 0;j < 8;j++) {
			char c;
			c = getchar();
			if (c == 32) {
				name[i] += "\0";
				break;
			}
			else {
				name[i] += c;
			}
		}
		cin >> s[i];
		getchar();
	}
}
void exchange(string id[], string name[], int s[], int i, int j)
{
	string t1;
	int t2 = 0;
	t1 = id[i];
	id[i] = id[j];
	id[j] = t1;
	t1 = name[i];
	name[i] = name[j];
	name[j] = t1;
	t2 = s[i];
	s[i] = s[j];
	s[j] = t2;

}
void sort(string id[], string name[], int s[])
{
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9 - i;j++) {
			if (s[j] > s[j + 1]) {
				exchange(id, name, s, j, j + 1);
			}
		}
	}
}
void output(string id[], string name[], int s[])
{
	cout << endl;
	cout << "����������(�ɼ�����):" << endl;
	for (int i = 0;i < 10;i++) {
		if (s[i] < 60) {
			cout << name[i] << ' ' << id[i] << " " << s[i] << endl;
		}
	}
}
int main()
{
	string id[10], name[10];
	int s[10];
	input(id, name, s);
	sort(id, name, s);
	output(id, name, s);

	return 0;
}
