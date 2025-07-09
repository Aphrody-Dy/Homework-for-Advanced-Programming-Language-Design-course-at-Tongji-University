// 
#include<iostream>
#include<conio.h>
#include"hanoi.h"
#include"cmd_console_tools.h"
#include"cmd_hdc_tools.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	cout << "请确认当前cmd窗口的大小为40行*120列以上，字体为新宋体/16，按C继续，Q退出" << endl;
	while (1) {
		char ch = _getch();
		if (ch == 'C' || ch == 'c')
			break;
		if (ch == 'Q' || ch == 'q')
			return 0;
	}

	int n=0,m=0;
	char src=0, dst=0, tmp=0;
	while (1) {
		m = menu();
		if (m == 0) {
			return 0;
		}
		else if (m == 5) {
			cct_cls();
			poles(m);
		}
		else {
			input(&n, &src, &tmp, &dst, m);
			if (m == 6 || m == 7 || m == 8||m==9) {
				if (m == 6) {
					cct_cls();
				}
				if (m == 8||m==9) {
					move(n, src, dst, 0, m, 1);
				}
				poles(m);
				initblocks(n, src,m);
				if (m == 7) {
					moveblocks(1, src, dst, n - 1, 0,0,m);
				}
			}
			if (m == 4) {
				move(n, src, dst, 0, m, 1);
			}
			if (m != 9) {
				hanoi(n, src, tmp, dst, m);
			}
		}
		if (m == 9) {
			while (1) {
				if (mode9(n,dst)) {
					continue;
				}
				else {
					break;
				}
			}
		}
		if (m == 4) {
			cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y+2);
		}
		if (m != 5 && m != 6) {
			cout << endl << endl << endl;
		}
		cout<< "按回车键继续";
		while (1) {
			if (_getch()==13) {
				break;
			}
			else {
				continue;
			}
		}
		continue;
	}
	return 0;
}