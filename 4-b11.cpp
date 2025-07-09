//
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

//number of equal signs
int noe(char end_ch) {
	int n, e;
	e = int(end_ch);
	n = (e - 65) * 2 + 1;
	return n;
}

//print equal signs
char pes(int n) {
	if (n == 1) {
		return '=';
	}
	else {
		cout << '=';
		return(pes(n - 1));
	}
}

//print characters in order
void pco(char end_ch) {
	if (end_ch == 'A') {
		cout<< 'A';
	}
	else {
		cout << end_ch;
		pco(char(end_ch - 1));
	}
}

//print characters in reversal order
void pcr(int n, char end_ch) {
	int e = int(end_ch) - 64;
	if (n - e == 1) {
		cout<< end_ch;
	}
	else {
		cout << char(end_ch + 1 - n + e);
		pcr(n - 1, end_ch);
	}
}



/***************************************************************************
  函数名称：
  功    能：打印字母塔
  输入参数：
  返 回 值：
  说    明：形参按需设置
			提示：有一个参数order，指定正序/倒序
***************************************************************************/
void print_tower(char end_ch,int order)
{
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
	static char c = end_ch;
	int w0 = c - end_ch + 1;
	int w1 = end_ch - 64;    // (c-64)-(c-end_ch)
	switch (order) {
		case 0: 
			if (end_ch == 'A') {
				cout << setfill(' ') << setw(w0) << end_ch << endl;
			}
			else {
				cout << setfill(' ') << setw(w0);
				pco(end_ch);
				pcr(noe(end_ch), end_ch);
				cout << endl;
				print_tower(end_ch - 1, order);
			}
			break;
		case 1: 
			if (c == 'A') {
				cout << 'A' << endl;
				break;
			}
			if (end_ch - 'A' == 0) {
				pco(c);
				pcr(noe(c), c);
				cout << endl;
			}
			else {
				cout << setfill(' ') << setw(w1);
				pco(char(c - end_ch + 65));
				if (c - end_ch != 0) {
					pcr(noe(char(c - end_ch + 65)), char(c - end_ch + 65));
				}
				cout << endl;
				print_tower(end_ch - 1, order);
			}
			break;
	}
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << pes(noe(end_ch)) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << pes(noe(end_ch)) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch,1); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << pes(noe(end_ch)) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << pes(noe(end_ch)) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch,0); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << pes(noe(end_ch)) << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << pes(noe(end_ch)) << endl;/* 按字母塔最大宽度输出= */
	print_tower(end_ch,1);   //打印 A~结束字符的正三角 
	if (end_ch != 'A') {
		print_tower(end_ch - 1, 0);   //打印 A~结束字符-1的倒三角 
	}
	cout << endl;

	return 0;
}
