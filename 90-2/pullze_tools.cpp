// 
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "pullze.h"
using namespace std;
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

/* ��ʾ�����ļ�����Ϊ�������㲻Ҫ�������� && ��Ҫ���ļ���Ū�� */

/***************************************************************************
  �������ƣ�menu
  ��    �ܣ���ӡ�˵���������ѡģʽ
  ���������int* size ����ѡ����С��ָ��
  �� �� ֵ����ѡģʽ��Ӧ������ַ�
  ˵    ����
***************************************************************************/
char menu(int *size)
{
	cct_setfontsize("������", 16);
	cct_cls();
	cct_setconsoleborder(120, 60,1000,1000);
	cout << "---------------------------------------------------------" << endl;
	cout << "A.�ڲ����飬ԭ�����" << endl;
	cout << "B.�ڲ����飬������ʾ���в����" << endl;
	cout << "C.�ڲ����飬��Ϸ��" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "D.n * n�Ŀ��(�޷ָ���)��ԭ�����" << endl;
	cout << "E.n * n�Ŀ��(�޷ָ���)������ʾ����" << endl;
	cout << "F.n * n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬������ƶ�����ʾ����" << endl;
	cout << "G.cmdͼ�ν���������(�޷ָ���)" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "H.n * n�Ŀ��(�зָ���)��ԭ�����" << endl;
	cout << "I.n * n�Ŀ��(�зָ���)������ʾ����" << endl;
	cout << "J.n * n�Ŀ��(�зָ���)����ʾ��ʼ״̬������ƶ�����ʾ����" << endl;
	cout << "K.cmdͼ�ν���������(�зָ���)" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Q.�˳�" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "[��ѡ��:]";

	char c;
	while (1) {
		c = _getch();
		if ((int(c) >= int('A') && int(c) <= int('K')) || (int(c) >= int('a') && int(c) <= int('k') || c == 'q' || c == 'Q') ){
			cout<<c;
			if (int(c) >= int('a') && int(c) <= int('k') ){
				c=char(c-32);
			}
			break;
		}
		else {
			continue;
		}
	}
	if (c == 'q' || c == 'Q') {
		return c;
	}
	cct_cls();
	while (1) {
		cout << "�����������С(5/10/15)��";
		cin >> *size;
		if (*size == 5 || *size == 10 || *size == 15) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
	}
	return c;
}

/***************************************************************************
  �������ƣ�end
  ��    �ܣ�ʵ��ÿС�����������end������س��������ز˵�
  �����������
  �� �� ֵ����
  ˵    �����鷳��ʦ/����ע���£�����������end������ȷ�Զ���ת�ز˵���
			����3���ַ�����������Զ���������ص�������ԭλ�����谴�س���
***************************************************************************/
void end() 
{
	cout << endl;
	cout << "��С�������������End����...";
	int x, y;
	cct_getxy(x, y);
	while (1) {
		char c[3] = { 0 };
		for (int i = 0;i < 3;i++) {
			c[i] = _getche();
			if (c[i] == 13) {
				i -= 1;
				cct_gotoxy(x, y);
			}
		}
		if ((c[0] == 'E' || c[0] == 'e') && (c[1] == 'n' || c[1] == 'N') && (c[2] == 'd' || c[2] == 'D')) {
			break;
		}
		else {
			cct_showstr(0, y + 1, "�����������������");
			cct_showch(x, y, ' ',0,7,3);
			cct_gotoxy(x, y);
			continue;
		}
	}
}

/***************************************************************************
  �������ƣ�checkWin
  ��    �ܣ��ж��ύ�Ƿ���ȷ
  ���������bool cheat ������ģʽ����
			int size ��ѡ�������С
			int (&user)[MAX_SIZE][MAX_SIZE] ���û��������������
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int* rowHintLen ������ʾ������󳤶ȵĵ�ַ
			int* colHintLen ������ʾ������󳤶ȵĵ�ַ
  �� �� ֵ��0-�ύ�ɹ���1-�ύ����
  ˵    ����
***************************************************************************/
int checkWin(char m,bool cheat,int size,int (&user)[MAX_SIZE][MAX_SIZE],int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1],int (&colHints)[MAX_SIZE][MAX_SIZE/2+1])
{
	int u_rowHints[MAX_SIZE][MAX_SIZE / 2 + 1] = { 0 };
	int u_colHints[MAX_SIZE][MAX_SIZE / 2 + 1] = { 0 };
	int u_rowHintLen = 0;
	int u_colHintLen = 0;
	generateHints(m,cheat, size, user, u_rowHints, u_colHints, &u_rowHintLen, &u_colHintLen);
	bool b = 1;
	for (int i = 0;i < MAX_SIZE;i++) {
		for (int j = 0;j < MAX_SIZE / 2 + 1;j++) {
			if (u_rowHints[i][j] != rowHints[i][j] || u_colHints[i][j] != colHints[i][j]) {
				b = 0;
				if (m != 'H') {
					cout << endl;
				}
				cout<< "�ύ���󣬿�������ģʽ�鿴" << endl;
				return 1;
			}
		}
	}
	if (b) {
		cout << endl << "�ύ�ɹ�����Ϸ����" << endl;
		end();
	}
	return 0;
}
















