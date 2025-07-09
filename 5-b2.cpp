//
#include<iostream>
using namespace std;
int main()
{
	int a[100],i;
	bool b[100];
	for (i = 0;i < 100;i++) {
		a[i] = i + 1;
		b[i] = 0;
	}

	for (i = 0;i < 100;i++) {
		for (int j = 0;j < 100;j++) {
			if ((j+1) % (i+1) == 0) {
				b[j] = !b[j];
			}
		}
	}

	for (i = 0;i < 100;i++) {
		if (b[i]) {
			cout << a[i] << ' ';
		}
	}
	return 0;

}