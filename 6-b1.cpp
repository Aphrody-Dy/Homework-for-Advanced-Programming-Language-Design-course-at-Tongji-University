// 
#include <iostream>
#include <cstdio>
using namespace std;


#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pa;
	bool is_num;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串" << endl;
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
		cout << "共有" << min((int(pa) - int(a) + 4) / 4, N) << "个整数" << endl;
	}
	else {
		cout << "共有0个整数" << endl;
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
