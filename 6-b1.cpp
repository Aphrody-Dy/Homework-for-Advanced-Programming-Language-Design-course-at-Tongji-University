// 
#include <iostream>
#include <cstdio>
using namespace std;


#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	cin.getline(str, 256, '\n');
	p = str;
	pa = a;
	is_num = 0;
	for (;*p != '\0'&&int(pa)-int(a)<40;p++) {
		if (int(*p)>=int('0')&&int(*p)<=int('9')) {
			if (p != str) {
				if (is_num) {
					*pa *= 10;
				}
			}
			is_num = 1;
			*pa += int(*p)-int('0');
		}
		else {
			if (is_num) {
				if (int(pa) < int(a) + 36) {			
					pa++;
				}
				else {
					break;
				}
			}
			is_num = 0;
		}
	}
	if (int(*--p) >= int('0') && int(*p) <= int('9'));
	else {
		pa--;
	}
	if ((pa!=a&&int(pa) < int(a) + 36)||(pa == a && *pa)) {
		pa++;
		*pa = -1;
		pa--;
	}
	if (pa != a||(pa==a&&*pa)) {
		cout << "����" << min((int(pa) - int(a) + 4) / 4, N) << "������" << endl;
	}
	else {
		cout << "����0������" << endl;
		*pa = -1;
	}
	for (pa = a;(int(pa) - int(a)+4)/4 <= N;pa++) {
		if (*pa >= 0) {
			cout << *pa << " ";
		}
		else {
			break;
		}
	}
	cout << endl;
	return 0;
}
