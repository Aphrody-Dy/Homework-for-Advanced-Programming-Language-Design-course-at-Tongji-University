// 
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "pullze.h"
#include "cmd_console_tools.h"
using namespace std;


/***************************************************************************
  �������ƣ�visualPrint
  ��    �ܣ�D-G�ޱ߱߿�ģʽ�µĴ�ӡ
  ���������bool cheat ������ģʽ����
			char m ��ѡ���ģʽ
			int size ��ѡ�������С
			int (&answer)[MAX_SIZE][MAX_SIZE] �������������
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int* rowHintLen ������ʾ������󳤶ȵĵ�ַ
			int* colHintLen ������ʾ������󳤶ȵĵ�ַ
			int (&user)[MAX_SIZE][MAX_SIZE] ���û��������������
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void visualPrint(bool cheat, char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE])
{
	cct_cls();
	cct_setfontsize("������", 35);//�ĳɸ���size�������С
	cct_setconsoleborder(120, 50,-1,100);
	if (m == 'F') {
		cout << "���Լ���/������/�Ҽ������س��˳�";
	}
	if (m == 'G') {
		cout << "���ѡ��/�Ҽ�ѡ��,Y/y�ύ,Z/z����,Q/q����";
	}
	cout << endl;
	int x, y;
	if (m != 'D') {
		//��ӡ�ϱ���
		cct_getxy(x, y);
		cct_showstr(x+ *rowHintLen * 2 + 6, y, "�X", 7, 0);
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", 7, 0, size);
		cct_getxy(x, y);
		cct_showstr(x, y, "�[", 7, 0);
		cct_setcolor();
		cout << endl;
		//��ӡ����ʾ����
		for (int j = 0;j < *colHintLen;j++) {
			cct_getxy(x, y);
			cct_showstr(x + *rowHintLen * 2 + 6, y, "�U", 7, 0);
			for (int i = 0;i < size;i++) {
				cct_setcolor(7, 0);
				cct_getxy(x, y);
				cout << ' ' << (colHints[i][*colHintLen - 1 - j] ? char(colHints[i][*colHintLen - 1 - j] + '0') : ' ');
			}
			cct_getxy(x,y);
			cct_showstr(x, y, "�U", 7, 0);
			cct_setcolor();
			cout << endl;
		}
		//��ӡ�м���
		cct_getxy(x, y);
		cct_showstr(x + *rowHintLen * 2 + 6, y, "�d", 7, 0);
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", 7, 0, size);
		cct_getxy(x, y);
		cct_showstr(x, y, "�g", 7, 0);
		cct_setcolor();
		cout << endl;
		cct_getxy(x, y);
		cct_showstr(x + *rowHintLen * 2 + 6, y, "�U", 7, 0);
		cct_setcolor();
	}
	else {
		cout << setw(3) << ' ';
	}
	//��ӡ�������ĸ
	for (int i = 0;i < size;i++) {
		cct_getxy(x, y);
		cct_showch(x, y, ' ', (m == 'D' || m == 'H') ? 0 : 7, (m == 'D' || m == 'H') ? 7 : 0);
		cct_showch(x+1, y, char('a' + i), (m == 'D' || m == 'H') ? 0 : 7, (m == 'D' || m == 'H') ? 7 : 0);
		if (m == 'D' || m == 'H') {
			Sleep(1);
		}
	}
	if (m != 'D' && m != 'H') {
		cct_getxy(x, y);
		cct_showstr(x, y, "�U", 7, 0);
	}
	cct_setcolor();
	cout << endl;
	//��ӡ�м���
	if (m != 'D') {
		cct_getxy(x, y);
		cct_showstr(x, y, "�X", 7, 0);
		cct_showstr(x + 2, y, "�T", 7, 0, *rowHintLen);
		cct_showstr(x + 2 + *rowHintLen * 2, y, "�j�T�p",7, 0);
	}
	else {
		cout << setw(2) << ' ';
		cct_getxy(x, y);
		cct_showstr(x, y, "�X", 7, 0);
		Sleep(1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�T", 7, 0, size);
	if (m == 'D') {
		Sleep(1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y,m=='D'?"�[":"�g", 7, 0);
	cct_setcolor();
	cout << endl;
	//��ӡ����ʾ������ż���������
	for (int i = 0;i < size;i++) {
		if (m != 'D') {
			cct_setcolor(7, 0);
			cct_getxy(x, y);
			cct_showstr(x, y, "�U",7,0);
			for (int j = 0;j < *rowHintLen;j++) {
				cct_getxy(x, y);
				cct_showch(x, y, ' ',7, 0);
				cct_showch(x + 1, y, (rowHints[i][*rowHintLen - 1 - j] ? char(rowHints[i][*rowHintLen - 1 - j] + '0') : ' '), 7, 0);
			}
			cct_getxy(x, y);
			cct_showstr(x, y, "�U ",7,0);

		}
		else {
			Sleep(1);
			cct_setcolor();
		}
		cct_getxy(x, y);
		cct_showch(x, y, char('A' + i), (m == 'D' || m == 'H') ? 0 : 7, (m == 'D' || m == 'H') ? 7 : 0);
		if (m == 'D') {
			cout << ' ';
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "�U",7,0);
		for (int j = 0;j < size;j++) {
			if (m == 'D') {
				Sleep(1);
			}
			cct_getxy(x, y);
			if (m != 'G') {
				cct_showstr(x, y, answer[i][j] ? "��" : "  ", answer[i][j] ? 1 : 7, 0);
			}
			else {
				cct_showstr(x, y, "  ", 7,7);
			}
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "�U", 7, 0);
		cct_setcolor();
		cout << endl;
	}
	//��ӡ�±���
	if (m != 'D' && m != 'H') {
		cct_getxy(x, y);
		cct_showstr(x, y, "�^", 7, 0);
		cct_showstr(x + 2, y, "�T", 7, 0, *rowHintLen);
		cct_showstr(x + 2 + *rowHintLen * 2, y, "�m�T�m", 7, 0);
	}
	else {
		cct_setcolor();
		cout << setw(2) << ' ';
		Sleep(1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�^", 7, 0);
		Sleep(1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�T", 7, 0, size);
	cct_getxy(x, y);
	cct_showstr(x, y, "�a", 7, 0);
	cct_setcolor();
	cout << endl;
}

/***************************************************************************
  �������ƣ�frameCell
  ��    �ܣ���H-K�б߿�ģʽ�£���ָ��λ�û��Ƶ�������
  ���������int X ����ģʽ�������㣨���Ͻǣ�����������ʾ���ĺ�����
			int Y ����ģʽ�������㣨���Ͻǣ�����������ʾ����������
			int i ��������Ԫ�������������еĵ�һ���±�
			int j ��������Ԫ�������������еĵڶ����±�
			int shape �����ڿ��ƻ��Ƶ���״���ݣ�0-�ո�1-����2-����
			const int bg ������ɫ��Ӧ���
			const int fg��ǰ��ɫ��Ӧ���
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void frameCell(int X, int Y, int i, int j, int shape,const int bg, const int fg)
{
	int x = X + 3 + 8 * j;
	int y = Y + 1 + 4 * i;
	if (shape == 0) {
		cct_showstr(x, y, "  ", bg, fg);
	}
	else if (shape == 1) {
		cct_showstr(x, y, "��", bg, fg);
	}
	else {
		cct_showstr(x, y, "��", bg, fg);
	}
	cct_showstr(x-2, y, !shape?"  ":"�U", bg, fg);
	cct_showstr(x + 2, y, !shape ? "  " : "�U", bg, fg);
	cct_showstr(x, y-1, !shape ? "  " : "�T", bg, fg);
	cct_showstr(x, y + 1, !shape ? "  " : "�T", bg, fg);
	cct_showstr(x+2, y + 1, !shape ? "  " : "�a", bg, fg);
	cct_showstr(x - 2, y + 1, !shape ? "  " : "�^", bg, fg);
	cct_showstr(x - 2, y - 1, !shape ? "  " : "�X", bg, fg);
	cct_showstr(x + 2, y - 1, !shape ? "  " : "�[", bg, fg);
}

/***************************************************************************
  �������ƣ�framePrint
  ��    �ܣ�H-K�б߱߿�ģʽ�µĴ�ӡ
  ���������bool cheat ������ģʽ����
			char m ��ѡ���ģʽ
			int size ��ѡ�������С
			int (&answer)[MAX_SIZE][MAX_SIZE] �������������
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int* rowHintLen ������ʾ������󳤶ȵĵ�ַ
			int* colHintLen ������ʾ������󳤶ȵĵ�ַ
			int (&user)[MAX_SIZE][MAX_SIZE] ���û��������������
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void framePrint(bool cheat, char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE])
{
	int x, y;
	cct_cls();
	cct_setfontsize("������", 9+(4-size/5)*4);
	cct_setconsoleborder(size*8+(*rowHintLen+5)*2, size * 4 + *colHintLen + 10,50,50);

	if (m == 'J') {
		cout << "���Լ���/������/�Ҽ������س��˳�";
	}
	if (m == 'K') {
		cout << "���ѡ��/�Ҽ�ѡ��,Y/y�ύ,Z/z����,Q/q����";
	}
	if (m != 'H') {
		//��ӡ����ʾ���Ϸ��߿�
		cct_showstr((*rowHintLen + 3) * 2, 1, "�X", 7, 0);
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", 7, 0, size * 4 - 1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�[", 7, 0);
		cct_setcolor();
		cout << endl;
		for (int j = 0;j < *colHintLen;j++) {
			cct_showstr((*rowHintLen + 3) * 2, 2 + j, "�U", 7, 0);
			cct_getxy(x, y);
			cct_showch(x, y, ' ', 7, 0, 2);
			for (int i = 0;i < size;i++) {
				cct_getxy(x, y);
				if (colHints[i][*colHintLen - 1 - j] < 10) {
					cct_showch(x, y, (colHints[i][*colHintLen - 1 - j] ? char(colHints[i][*colHintLen - 1 - j] + '0') : ' '), 7, 0);
				}
				else {
					cct_showch(x, y, '1', 7, 0);
					cct_showch(x+1, y, char(colHints[i][*colHintLen - 1 - j] % 10 + '0'), 7, 0);
				}
				cct_getxy(x, y);
				if (colHints[i][*colHintLen - 1 - j] < 10) {
					cct_showch(x, y, ' ', 7, 0, i == size - 1 ? 3 : 7);
				}
			}
			cct_getxy(x, y);
			cct_showstr(x, y, "�U", 7, 0);
			cct_setcolor();
			cout << endl;
		}
		cct_getxy(x, y);
		cct_showstr((*rowHintLen + 3) * 2, y, "�d", 7, 0);
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", 7, 0, ((size - 1) * 8 + 6) / 2);
		cct_getxy(x, y);
		cct_showstr(x, y, "�g", 7, 0);
		cct_setcolor();
		cout << endl;
		cct_getxy(x, y);
		cct_showstr((*rowHintLen + 3) * 2, y, "�U  ", 7, 0);
	}
	else {
		cct_showch(0, 0, ' ', 0, 7, 6);
	}
	//��ӡ�����
	for (int i = 0;i < size;i++) {
		Sleep(1);
		cct_getxy(x, y);
		cct_showch(x, y, char('a' + i),m=='H'?0:7,m=='H'?7:0);
		cct_showch(x+1, y, ' ', m == 'H' ? 0 : 7, m == 'H' ? 7 : 0, i==size-1?3:7);
	}
	if (m != 'H') {
		cct_getxy(x, y);
		cct_showstr(x, y, "�U", 7, 0);
	}
	cct_setcolor();
	cout << endl;
	
	//��ӡ����ʾ������ŷָ���
	if (m != 'H') {
		cct_getxy(x, y);
		cct_showstr(x, y, "�X", 7, 0);
		cct_showstr(x+2, y, "�T", 7, 0, *rowHintLen);
		cct_showstr(x + 2 + *rowHintLen * 2, y, "�j�T�p", 7, 0);

	}
	else {
		cct_showstr(2, 1, "�X", 7, 0);
	}
	for (int i = 0;i < size;i++) {
		Sleep(1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", 7, 0, 3);
		cct_getxy(x, y);
		if (i == size - 1) {
			cct_showstr(x, y, m=='H'?"�[":"�g", 7, 0);
			break;
		}
		cct_showstr(x, y, "�j", 7, 0);
	}
	cct_setcolor();
	cout << endl;
	//��ӡ�в�����
	for (int i = 0;i < size;i++) {
		int j = 0;
		for (j = 0;j < 4;j++) {
			Sleep(1);
			if (m != 'H') {
				if (i == size - 1 && j == 3) {
					break;
				}
				cct_getxy(x, y);
				cct_showstr(x, y, "�U", 7, 0);
				for (int k = 0;k < *rowHintLen;k++) {
					cct_getxy(x, y);
					if (rowHints[i][*rowHintLen - 1 - k] < 10) {
						cct_showch(x, y, ' ', 7, 0);
						cct_showch(x + 1, y, j == 1 ? (rowHints[i][*rowHintLen - 1 - k] ? char(rowHints[i][*rowHintLen - 1 - k] + '0') : ' ') : ' ', 7, 0);
					}
					else {
						cct_showch(x, y, '1', 7, 0);
						cct_showch(x + 1, y, char(rowHints[i][*rowHintLen - 1 - k] % 10 + '0'), 7, 0);
					}
				}
				cct_getxy(x, y);
				cct_showstr(x, y, "�U", 7, 0);
			}
			cct_getxy(x, y);
			cct_showch(x, y, j==1?char('A' + i):' ', m=='H'?0:7,m=='H'? 7:0);
			cct_showch(x + 1, y, ' ', m == 'H' ? 0 : 7, m == 'H' ? 7 : 0);
			cct_getxy(x, y);
			if (i == size - 1 && j == 3) {
				break;
			}
			cct_showstr(x, y, j == 3 ? "�d" : "�U", 7, 0);
			for (int k = 0;k < size;k++) {
				cct_getxy(x, y);
				cct_showstr(x, y, j==3?"�T":"  ", 7, 0, 3,6);
				cct_getxy(x, y);
				if (k == size - 1) {
					break;
				}
				cct_showstr(x-1, y, j == 3 ? " �p" : " �U", 7, 0);
			}
			cct_getxy(x, y);
			cct_showstr(x, y, j==3?"�g": "�U", 7, 0);
			cct_setcolor();
			cout << endl;
		}
		if (i == size - 1 && j == size - 2) {
			break;
		}
	}
	//��ӡ�±���
	if (m != 'H') {
		cct_getxy(x, y);
		cct_showstr(x, y, "�^", 7, 0);
		cct_showstr(x + 2, y, "�T", 7, 0, *rowHintLen);
		cct_showstr(x + 2 + *rowHintLen * 2, y, "�m�T�m", 7, 0);
	}
	else {
		cct_getxy(x, y);
		cct_showstr(x, y, "�^", 7, 0);
	}
	for (int i = 0;i < size;i++) {
		Sleep(1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", 7, 0, 3);
		cct_getxy(x, y);
		if (i == size - 1) {
			cct_showstr(x, y, "�a", 7, 0);
			break;
		}
		cct_showstr(x, y, "�m", 7, 0);
	}
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			Sleep(1);
			if (answer[i][j]&&m!='K') {
				frameCell(m=='H'?3:(*rowHintLen+3)*2+1, m == 'H' ? 2 : *colHintLen+5, i, j,1);
			}
		}
	}
	cct_setcolor();
	cct_gotoxy(0,size*4+(m=='H'?5:10));
	if (m != 'J' && m != 'K') {
		end();
	}
}

/***************************************************************************
  �������ƣ�convertXY
  ��    �ܣ�����Ԫ�������������������ת��������λ�õ�����
  ���������char m ��ѡ���ģʽ
			int* x ��������Ԫ�������������еĵ�һ���±�ĵ�ַ
			int* y ��������Ԫ�������������еĵڶ����±�ĵ�ַ
			int* rowHintLen ������ʾ������󳤶ȵĵ�ַ
			int* colHintLen ������ʾ������󳤶ȵĵ�ַ
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void convertXY(char m,int* x,int* y,int* rowHintLen,int* colHintLen)
{
	int t = *x;
	if (m != 'K') {
		*x = *y - 5 - *colHintLen;
		*y = (((t - 7 - (*rowHintLen + 1) * 2) % 2 == 0) ? (t - 7 - (*rowHintLen + 1) * 2) / 2 : ((t - 7 - (*rowHintLen + 1) * 2) + 1) / 2);
	}
	else {
		*x = (*y - *colHintLen - 5) / 4;
		*y = (t - (*rowHintLen + 4) * 2 -1) / 8;
	}
}

/***************************************************************************
  �������ƣ�drawCell
  ��    �ܣ���϶�ȡ����ĺ������ж�ÿ�����������Ӧ��ͼ�λ��Ʋ���
  ���������char m ��ѡ���ģʽ
			bool cheat ������ģʽ����
			int user1 �����β���ǰuser�����ӦԪ�ص�ֵ
			int user2 �����β�����user�����ӦԪ�ص�ֵ
			int answer ������������Ӧλ��Ԫ�ص�ֵ
			int i ��������Ԫ�������������еĵ�һ���±�
			int j ��������Ԫ�������������еĵڶ����±�
			int* rowHintLen ������ʾ������󳤶ȵĵ�ַ
			int* colHintLen ������ʾ������󳤶ȵĵ�ַ
			int left ����������0-�ң�1-��2-�������������Ļ�ͼ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int drawCell(char m,bool cheat,int user1,int user2,int answer,int i,int j,int* rowHintLen,int* colHintLen,int left)
{
	int X = (m == 'K' ? (*rowHintLen + 3) * 2 + 1 : (*rowHintLen + 1) * 2 + 6 + j * 2);
	int Y = (m == 'K' ? *colHintLen + 5 : *colHintLen + 4 + i + 1);
	if (left == 2) {
		if (cheat) {
			if (!user2) {
				if (m == 'G') {
					cct_showstr(X, Y, answer ? "��" : "  ", answer ? 8 : 7, answer ? 0 : 7);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, answer ? 1 : 0, answer ? 8 : 7, answer ? 0 : 7);
				}
			}
			if (user2 == 1) {
				if (m == 'G') {
					cct_showstr(X, Y, "��", answer ? 1 : 4, 0);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, 1, answer ? 1 : 4, 0);
				}
			}
			if (user2 == 2) {
				if (m == 'G') {
					cct_showstr(X, Y, "��", answer ? 1 : 4, 0);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, 2, answer ? 1 : 4, 0);
				}
			}
		}
		else {
			if (!user2 && answer) {
				if (m == 'G') {
					cct_showstr(X, Y, "  ", 7, 7);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, 0, 7,7);
				}
			}
			drawCell(m,cheat, -1, user2, answer, i, j, rowHintLen, colHintLen, 1);
		}
		return 0;
	}
	if (!cheat&&left!=2) {
		switch (user2){
			case 0:
				if (m == 'G') {
					cct_showstr(X, Y, "  ", 7, 7);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, 0, 7, 7);
				}
				break;
			case 1:
				if (m == 'G') {
					cct_showstr(X, Y, "��", 1, 0);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, 1, 1,0);
				}
				break;
			case 2:
				if (m == 'G') {
					cct_showstr(X, Y, "��", 4, 0);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, 2, 4, 0);
				}
		}
	}
	if (cheat) {
		if (!user1) {
			if (m == 'G') {
				cct_showstr(X, Y, left ? "��" : "��", answer ? 1 : 4, 0);
			}
			if (m == 'K') {
				frameCell(X, Y, i, j, left?1:2, answer ? 1 : 4, 0);
			}
		}
		else if (!user2) {
			if (m == 'G') {
				cct_showstr(X, Y, answer ? "��" : "��", answer ? 8 : 7, answer ? 0 : 7);
			}
			if (m == 'K') {
				frameCell(X, Y, i, j, answer ? 1 : 2, answer ? 8 : 7, answer ? 0 : 7);
			}
		}
		else{
			if (m == 'G') {
				cct_showstr(X, Y, user2 == 2 ? "��" : "��", answer ? 1 : 4, 0);
			}
			if (m == 'K') {
				frameCell(X, Y, i, j, user2 == 2 ? 2 : 1, answer ? 1 : 4, 0);
			}
		}
	}
	return 0;
}

/***************************************************************************
  �������ƣ�readMouseKey
  ��    �ܣ���ȡ���ͼ��̵Ĳ�����ת��Ϊ�����ж�Ӧ�Ĵ�ӡ����
  ���������bool cheat ������ģʽ����
			char m ��ѡ���ģʽ
			int size ��ѡ�������С
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int* rowHintLen ������ʾ������󳤶ȵĵ�ַ
			int* colHintLen ������ʾ������󳤶ȵĵ�ַ
			int (&answer)[MAX_SIZE][MAX_SIZE] �������������
			int (&user)[MAX_SIZE][MAX_SIZE] ���û��������������
  �� �� ֵ�����ڡ��˳���״̬����ǰ��ֹ�������в��ν���һ������
  ˵    ����
***************************************************************************/
int readMouseKey(bool cheat, char m, int size, int(&rowHints)[MAX_SIZE][MAX_SIZE/2+1], int(&colHints)[MAX_SIZE][MAX_SIZE/2+1],int* rowHintLen, int* colHintLen, int(&answer)[MAX_SIZE][MAX_SIZE], int(&user)[MAX_SIZE][MAX_SIZE])
{
	int X = 0, Y = 0, i, j, b = 0;
	int ret, maction;
	int keycode1, keycode2;
	for (int i = 0;i < MAX_SIZE;i++) {
		for (int j = 0;j < MAX_SIZE;j++) {
			user[i][j] = 0;
		}
	}
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (1) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (keycode1 == 13) {
			cct_showch(6 + *rowHintLen * 2, *colHintLen + size*(m=='J'||m=='K'?4:1) + 6, ' ', 0, 7, 19);
			cct_gotoxy(6 + *rowHintLen * 2, *colHintLen + size * (m == 'J' || m == 'K' ? 4 : 1) + 6);
			cout << "[�����س���]" << endl;
			end();
			break;
		}
		else if (ret == CCT_MOUSE_EVENT) {
			bool range=0;
			if (m == 'J' || m == 'K') {
				if (X >=(*rowHintLen + 4) * 2 && X <= (*rowHintLen + 4) * 2 + size * 4 * 2-3 &&Y>*colHintLen+4&&Y<*colHintLen+4+size*4) {
					range = 1;
				}
				for (int i = 0;i < size;i++) {
					if (X == (*rowHintLen + 4) * 2 + 6+8*i || X == (*rowHintLen + 4) * 2 + 7 + 8 * i || Y == *colHintLen + 8 + i* 4) {
						range = 0;
					}
				}
			}
			if (m=='J'||m=='K'?range:(X > 5 + 2 * (*rowHintLen + 1) && X <= 2 * (*rowHintLen + 1 + size) + 5 && Y > *colHintLen + 4 && Y <= *colHintLen + size + 4)) {

				cct_gotoxy(6 + *rowHintLen * 2+11, *colHintLen + 6 + size * (m == 'J' || m == 'K' ? 4 : 1));
				cout << (m=='J'||m=='K'? char((Y - *colHintLen - 5) / 4 + 'A'):char(Y - 5 - *colHintLen + 'A') )<< ' ' << "��" <<( m=='J'||m=='K'? char((X - (*rowHintLen + 4) * 2 - 1) / 8 + 'a'):char((((X - 7 - (*rowHintLen + 1) * 2) % 2 == 0) ? (X - 7 - (*rowHintLen + 1) * 2) / 2 : ((X - 7 - (*rowHintLen + 1) * 2) + 1) / 2) + 'a') )<< ' ' << "��";
				int t = 0;
				switch (maction) {
					case MOUSE_ONLY_MOVED:
						cct_showstr(6 + *rowHintLen * 2,  *colHintLen  + 6+ size * (m == 'J' || m == 'K' ? 4 : 1), "[��ǰ���] ",0,7);
						cct_gotoxy(0,2);
						continue;
					case MOUSE_LEFT_BUTTON_CLICK:
						i = X;
						j = Y;
						convertXY(m,&i, &j, rowHintLen, colHintLen);
						t = user[i][j];
						if (user[i][j]!=1) {
							user[i][j] = 1;
						}
						else {
							user[i][j] =0;
						}
						if (m == 'G' || m == 'K') {
							drawCell(m,cheat, t, user[i][j], answer[i][j], i, j, rowHintLen, colHintLen, 1);
						}
						cct_showstr(6 + *rowHintLen * 2, *colHintLen + 6 + size * (m == 'J' || m == 'K' ? 4 : 1), "[�������] ");
						continue;
					case MOUSE_RIGHT_BUTTON_CLICK:
						i = X;
						j = Y;
						convertXY(m,&i, &j, rowHintLen, colHintLen);
						t = user[i][j];
						if (user[i][j] != 2) {
							user[i][j] = 2;
						}
						else {
							user[i][j] = 0;
						}
						if (m == 'G' || m == 'K') {
							drawCell(m,cheat, t, user[i][j], answer[i][j], i, j, rowHintLen, colHintLen, 2);
						}
						cct_showstr(6 + *rowHintLen * 2, *colHintLen + 6 + size * (m == 'J' || m == 'K' ? 4 : 1), "[�����Ҽ�] ");
						continue;
				}
			}
			else {
				cct_showstr(6 + *rowHintLen * 2,*colHintLen + size * (m == 'J' || m == 'K' ? 4 : 1) +6, "[��ǰ���] λ�÷Ƿ�");
			}
		}
		else if (ret == CCT_KEYBOARD_EVENT) {
			cct_showch(6 + *rowHintLen * 2, *colHintLen + size * (m == 'J' || m == 'K' ? 4 : 1) + 6, ' ', 0, 7, 19);
			cct_gotoxy(6 + *rowHintLen * 2, *colHintLen + size * (m == 'J' || m == 'K' ? 4 : 1) + 6);
			switch (keycode1) {
				case 113:
					if (m == 'G' || m == 'K') {
						cout << "[����Q/q����Ϸ����]" << endl;
						end();
						return 0;
					}
					else {
						cout << "[��������] " << keycode1 << '/' << keycode2;
						break;
					}
				case 121:
					if (m == 'G' || m == 'K') {
						cout << "[�����ύ��]";
						Sleep(500);
						if (checkWin(m, cheat, size, user, rowHints, colHints)) {
							Sleep(2000);
							cct_showch(6 + *rowHintLen * 2, *colHintLen + size * (m == 'J' || m == 'K' ? 4 : 1) + 6, ' ', 0, 7, 19);
							cct_showch(0, *colHintLen + size * (m == 'J' || m == 'K' ? 4 : 1) + 7, ' ', 0, 7, 26);
							continue;
						}
						else {
							b = 1;
							break;
						}
					}
					else {
						cout << "[��������] " << keycode1 << '/' << keycode2;
						break;
					}
				case 122:
					if (m == 'G' || m == 'K') {
						cheat = (!cheat);
						for (int p = 0;p < size;p++) {
							for (int n = 0;n < size;n++) {
								drawCell(m,cheat, -1, user[p][n], answer[p][n], p, n, rowHintLen, colHintLen, 2);
							}
						}
						cct_setcolor();
						cct_gotoxy(6 + *rowHintLen * 2, *colHintLen + size * (m == 'J' || m == 'K' ? 4 : 1) + 6);
						cout << "[����ģʽ" << (cheat ? "��" : "��") << "]";
						continue;
					}
					else {
						cout << "[��������] " << keycode1 << '/' << keycode2;
						break;
					}
				case 224:
					switch (keycode2) {
						case KB_ARROW_UP:
							cout << "[�����ϼ�ͷ]";
							continue;
						case KB_ARROW_DOWN:
							cout << "[�����¼�ͷ]";
							continue;
						case KB_ARROW_LEFT:
							cout << "[�������ͷ]";
							continue;
						case KB_ARROW_RIGHT:
							cout << "[�����Ҽ�ͷ]";
							continue;
					}
				default:
					cout << "[��������] " << keycode1 << '/' << keycode2;
			}
		}
		if (b == 1) {
			break;
		}
	}
	return 0;
}

/***************************************************************************
  �������ƣ�visualMode
  ��    �ܣ�D-Kαͼ�ν������������
  ���������bool cheat ������ģʽ����
			char m ��ѡ���ģʽ
			int size ��ѡ�������С
			int (&answer)[MAX_SIZE][MAX_SIZE] �������������
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int* rowHintLen ������ʾ������󳤶ȵĵ�ַ
			int* colHintLen ������ʾ������󳤶ȵĵ�ַ
			int (&user)[MAX_SIZE][MAX_SIZE] ���û��������������
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void visualMode(bool cheat, char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE])
{
	for (int i = 0;i < MAX_SIZE;i++) {
		for (int j = 0;j < MAX_SIZE;j++) {
			user[i][j] = 0;
		}
	}
	initBoard(size, answer);
	generateHints(m,cheat, size, answer, rowHints, colHints, rowHintLen, colHintLen);
	if (m == 'D' || m == 'E' || m == 'F' || m == 'G') {
		visualPrint(cheat, m, size, answer, rowHints, colHints, rowHintLen, colHintLen, user);
		if (m == 'D' || m == 'E') {
			end();
		}
	}
	else {
		framePrint(cheat, m, size, answer, rowHints, colHints, rowHintLen, colHintLen, user);
	}
	if (m == 'F' || m == 'G' || m == 'J' || m == 'K') {
		readMouseKey(cheat, m, size, rowHints, colHints, rowHintLen, colHintLen, answer, user);
	}
}
