// 
#include <iostream>
using namespace std;
int reverse()
{
	char c[80], * pc,* pcr;
	bool b=1;
	fgets(c, 80, stdin);
	for (pc = c, pcr = c + strlen(c)-2;*pc != '\n';pc++, pcr--) {
		if (*pc == *pcr) {
			continue;
		}
		else {
			return 0;
		}
	}
	return 1;
}
int main()
{
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	if (reverse()) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}