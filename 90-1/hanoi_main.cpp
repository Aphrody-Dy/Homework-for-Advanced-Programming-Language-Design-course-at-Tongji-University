// 
#include<iostream>
#include<conio.h>
#include"hanoi.h"
#include"cmd_console_tools.h"
#include"cmd_hdc_tools.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	cout << "��ȷ�ϵ�ǰcmd���ڵĴ�СΪ40��*120�����ϣ�����Ϊ������/16����C������Q�˳�" << endl;
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
		cout<< "���س�������";
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