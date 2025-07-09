// 
#pragma once

/* 将所有const常量定义的头文件包含进来 */
#include "hanoi_const_value.h"

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
int menu();
void input(int *n,char *src, char *tmp,char *dst,int m);
void output(int m);
void poles(int m);
void initblocks(int n, char src,int m);
void moveblocks(int n, char src, char dst, int srclayer, int dstlayer,int s,int m);
void move(int n, char src, char dst, int s, int m,bool b=0);
void hanoi(int n, char src, char tmp, char dst, int m);
int mode9(int n,char dst);