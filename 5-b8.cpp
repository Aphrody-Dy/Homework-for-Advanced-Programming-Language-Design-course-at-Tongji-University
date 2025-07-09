// 
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

#define N_POW	112		//幂的次数
#define N_NUM	N_POW+1	//十进制形式的小数位数

void output1(const char prompt[], const int d[])
{
	cout << "2^" << setw(4) << right << d[0] << " : 0.";
	for (int i = 1;i < N_NUM;i++) {
		if (d[i-1]==5&&!d[i]&&!d[i+1]&&!d[i+2]) {
			break;
		}
		else {
			if (i == N_NUM - 1) {
				if (d[i - 1] == 5 && !d[i]) {
					break;
				}
			}
			cout << d[i];
		}
	}
	cout << endl;
}

void calc_next(int d_cur[], int d_next[]) {

	d_next[1] = d_cur[1] / 2;
	for (int i = 1;i < N_NUM;i++) {
		d_next[i + 1] = (d_cur[i + 1]+(d_cur[i]%2) * 10) / 2;
	}
	
}

void calc_num(char pure_decimal[], int out[], int power_table[][N_NUM+1])
{
	for (int i = 1;i < N_POW;i++) {
		for (int j = 1;j < N_POW;j++) {
			if (pure_decimal[j]=='1') {
				out[i] += power_table[j][i];
			}
		}
	}
	for (int i = N_POW;i > 0;i--) {
		for (int i = N_POW; i > 1; i--) {
			out[i - 1] += out[i] / 10;
			out[i] %= 10;
		}
	}
}

void input_pure_decimal(char pd[])
{
	while (1) {
		int z = 0;
		bool b = 1;
		cin.getline(pd, N_NUM, '\n');
		if (pd[0] != '.') {
			cout << "不是以.开头，请重输" << endl;
			b = 0;
			continue;
		}
		else {
			if (strlen(pd) < 2) {
				cout << "输入数据为空，请重输" << endl;
				b = 0;
				continue;
			}
			else {
				for (unsigned int i = 1;i < strlen(pd);i++) {
					if (pd[i] == '0') {
						z++;
					}
				}
				if (z == (strlen(pd) - 1)) {
					cout << "输入为全0，请重输" << endl;
					b = 0;
					continue;
				}
				for (unsigned int i = 1;i < strlen(pd);i++) {
					if (pd[i] != '0' && pd[i] != '1') {
						cout << "输入的不是0/1，请重输" << endl;
						b = 0;
						break;;
					}
				}
				if (b == 0) {
					continue;
				}
			}
		}
		break;
	}
}

void output_rod(const bool is_upper)
{
	if (is_upper) { //上标尺
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "----------- 上标尺  1         2         3         4         5         6         7         8         9         A         B         C" << endl;
		cout << "-----------123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	else {//下标尺
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-----------123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
		cout << "----------- 下标尺  1         2         3         4         5         6         7         8         9         A         B         C" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

int main()
{
	int power_table[N_POW + 1][N_NUM + 1] = { 0 };
	int i;
	for (i = 1; i <= N_POW; i++) {
		power_table[i][0] = -i; //幂次 -1 ~ -52
	}
	power_table[1][1] = 5;
	for (i = 1; i < N_POW; i++)
		calc_next(power_table[i], power_table[i + 1]); //已知2^-i，求2^-(i+1)
	

	/* 上标尺 */
	output_rod(1);

	/* 输出 */
	for (i = 1; i <= N_POW; i++)
		output1("", power_table[i]);

	/* 下标尺 */
	output_rod(0);
	cout << endl;
	
	cout << "请输入一个二进制纯小数，小数点开头，小数点后不超过112位(例：.101101)" << endl;
	char pure_decimal[N_NUM + 1] = { 0 };
	input_pure_decimal(pure_decimal);

	cout << endl;
	output_rod(1);

	cout << "输入数据 : ";
	int b = 0;
	for(unsigned int i = 1;i < strlen(pure_decimal);i++) {
		if (pure_decimal[i]) {
			if (pure_decimal[i] == '1') {
				b=0;
			}
			if (pure_decimal[i] == '0') {
				b++;
			}
			if (b == strlen(pure_decimal) - i) {
				break;
			}
			else {
				cout << pure_decimal[i];
			}
		}
	}
	cout << endl;
	
	int out[N_NUM + 1] = { 0 };
	calc_num(pure_decimal, out, power_table);
	cout << "计算值 : 0.";
	for (i = 1;i < N_NUM;i++) {
		int b=0;
		for (int j = i;j < N_NUM;j++) {
			if (!out[j]) {
				b++;
			}
		}
		if (b == N_NUM - i) {
			continue;
		}
		else {
			cout << out[i];
		}
	}
	cout << endl;

	output_rod(0);

	cout << endl;
	
	return 0;
}


