// 
#pragma once

/* ������const���������ͷ�ļ��������� */
#include "hanoi_const_value.h"

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
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