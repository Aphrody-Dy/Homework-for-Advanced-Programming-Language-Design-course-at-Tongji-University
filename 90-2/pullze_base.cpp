// 
#include <iostream>
#include <conio.h>
#include "pullze.h"
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  �������ƣ�initBoard
  ��    �ܣ���ʼ����壬������ɰ�����
  ���������int size ��ѡ�������С
			int (&answer)[MAX_SIZE][MAX_SIZE] �������������
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void initBoard(int size,int (&answer)[MAX_SIZE][MAX_SIZE])
{
	srand((unsigned int) (time(0)));
	for (int i = 0;i < MAX_SIZE;i++) {
		for (int j = 0;j < MAX_SIZE;j++) {
			answer[i][j] = 0;
		}
	}
	int n = 0;
	while (n < ((size * size) % 2 == 0 ? size * size / 2 : (size * size / 2 + 1))) {
		int x = rand() % size;
		int y = rand() % size;
		if (!answer[x][y]) {
			answer[x][y] = 1;
			n++;
		}
	}
}

/***************************************************************************
  �������ƣ�generateHints
  ��    �ܣ�������������С�����ʾ����
  ���������bool cheat ���Ƿ�������ģʽ
			int size ��ѡ�������С
			int (&answer)[MAX_SIZE][MAX_SIZE] �������������
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int* rowHintLen ������ʾ������󳤶ȵĵ�ַ
			int* colHintLen ������ʾ������󳤶ȵĵ�ַ
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void generateHints(char m,bool cheat,int size,int (& answer)[MAX_SIZE][MAX_SIZE], int (&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int (&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen)
{
	int* p;
	for (int i = 0;i < MAX_SIZE;i++) {
		for (int j = 0;j < MAX_SIZE / 2 + 1;j++) {
			rowHints[i][j] = 0;
		}
	}
	for (int i = 0;i < MAX_SIZE;i++) {
		for (int j = 0;j < MAX_SIZE / 2 + 1;j++) {
			colHints[i][j] = 0;
		}
	}
	*rowHintLen = 0;
	*colHintLen = 0;
	if (cheat) {
		for (int i = 0;i < MAX_SIZE;i++) {
			for (int j = 0;j < MAX_SIZE;j++) {
				if (m == 'G'||m=='K') {
					answer[i][j] = answer[i][j] == 1 ? 1 : 0;
				}
				else {
					answer[i][j] = answer[i][j] == 2 ? 1 : 0;
				}
			}
		}
	}
	// ��������ʾ
	for (int i = 0;i < size;i++) {
		bool b = 0;
		int L = 0;
		p = &rowHints[i][0];
		for (int j = size-1;j >=0; j--) { // Ϊ�˱��ڴ�ӡ���룬������ʾʱÿ�е���Ӻ���ǰ��
			if (answer[i][j]) {
				if (j==size-1|| (j<size-1 && answer[i][j +1])) {
					(*p)++;
					b = 1;
				}
				else {
					if (!answer[i][j +1]) {
						if (b) {
							p++;
							L++;
						}
						(*p)++;
						b = 1;
					}
				}
			}
		}
		*rowHintLen = *rowHintLen > L ? *rowHintLen : L;
	}
	*rowHintLen += 1;
	// ��������ʾ
	for (int i = 0;i < size;i++) {
		bool b = 0;
		int L = 0;
		p = &colHints[i][0];
		for (int j = size - 1;j >=0; j--) {
			if (answer[j][i]) {
				if (j == size - 1 || (j < size - 1 && answer[j + 1][i])) {
					(*p)++;
					b = 1;
				}
				else {
					if (!answer[j+1][i]) {
						if (b) {
							p++;
							L++;
						}
						(*p)++;
						b = 1;
					}
				}
			}
		}
		*colHintLen = *colHintLen > L ? *colHintLen : L;
	}
	*colHintLen += 1;
}

/***************************************************************************
  �������ƣ�basePrint
  ��    �ܣ�����ڲ�����ģʽ�µĸ��ִ�ӡ
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
void basePrint(bool cheat,char m,int size, int (& answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int (&user)[MAX_SIZE][MAX_SIZE])
{
	int x, y;
	if (m != 'C') {
		cout << "��ʼ���飺" << endl;
	}
	if (m != 'A' ) {
		//��ӡ�ϱ���
		cct_getxy(x, y);
		cct_showch(x, y, '-', 0, 7, *rowHintLen*2+3);
		cout << "+";
		for (int i = 0;i < size / 5;i++) {
			cct_getxy(x, y);
			cct_showch(x, y, '-', 0, 7, 5*2+1);
			if (i + 1 == size / 5) {
				break;
			}
			if (m == 'C') {
				cout << "+";
			}
			else {
				cct_getxy(x, y);
				cct_showch(x, y, ' ');
				cct_gotoxy(x - 1, y);
			}
		}
		cout << "+" << endl;
		//��ӡ����ʾ����
		for (int j = 0;j < *colHintLen;j++) {
			cct_getxy(x, y);
			cct_showch(x, y, ' ', 0, 7, *rowHintLen * 2 + 3);
			cout << "|";
			for (int k = 0;k < size / 5;k++) {
				for (int i = k*5;i < k*5+5;i++) {
					cout << ' ' << (colHints[i][*colHintLen - 1 - j] ? char(colHints[i][*colHintLen - 1 - j] + '0') : ' ');
				}
				if (k + 1 == size / 5) {
					break;
				}
				if (m == 'C') {
					cout << ' ' << "|";
				}
			}
			cout << ' ' << "|" << endl;
		}
		//��ӡ�м���
		cct_getxy(x, y);
		cct_showch(x, y, '-', 0, 7, *rowHintLen*2 + 1);
	}
	cout << "+-+";
	for (int i = 0;i < size / 5;i++) {
		cct_getxy(x, y);
		cct_showch(x, y, '-', 0, 7, 5 * 2 + 1);
		if (i + 1 == size / 5) {
			break;
		}
		if (m == 'C') {
			cout << "+";
		}
		else {
			cct_getxy(x, y);
			cct_showch(x, y, ' ');
			cct_gotoxy(x - 1, y);
		}
	}
	cout << "+" << endl;
	//��ӡ�������ĸ
	if (m != 'A' ) {
		cct_getxy(x, y);
		cct_showch(x, y, ' ', 0, 7, *rowHintLen * 2 + 3);
	}
	else {
		cout << "| ";
	}
	cout << "|";
	for (int j = 0;j < size / 5;j++) {
		for (int i = j*5;i < j*5+5;i++) {
			cout << ' ' << char('a' + i);
		}
		if (j + 1 == size / 5) {
			break;
		}
		if (m == 'C') {
			cout<< " |";
		}
	}
	cout << " |" << endl;
	//��ӡ�м���
	if (m != 'A' ) {
		cct_getxy(x, y);
		cct_showch(x, y, '-', 0, 7, *rowHintLen*2 + 1);
	}
	cout << "+-+";
	for (int i = 0;i < size / 5;i++) {
		cct_getxy(x, y);
		cct_showch(x, y, '-', 0, 7, 5 * 2 + 1);
		if (i + 1 == size / 5) {
			break;
		}
		if (m == 'C') {
			cout << "+";
		}
		else {
			cct_getxy(x, y);
			cct_showch(x, y, ' ');
			cct_gotoxy(x - 1, y);
		}
	}
	cout << "+" << endl;
	//��ӡ����ʾ������ż���������
	for (int i = 0;i < size;i++) {
		if (m != 'A' ) {
			for (int j = 0;j < *rowHintLen;j++) {
				cout << ' ' << (rowHints[i][*rowHintLen - 1 - j] ? char(rowHints[i][*rowHintLen - 1 - j] + '0') : ' ');
			}
			cout << ' ';
		}
		cout << "|" << char('A' + i) << "|";
		if (m != 'C') {
			for (int j = 0;j < size;j++) {
				cout << ' ' << (answer[i][j] ? 'O' : ' ');
			}
			cout << ' '<<"|" << endl;
		}
		else {
			for (int k = 0;k < size / 5;k++) {
				for (int j = k*5;j < k*5+5;j++) {
					//cout << ' ' << ((cheat?answer[i][j]:user[i][j]) ? '0' : ' ');
					cct_getxy(x, y);
					cct_showch(x , y, ' ');
					if (!cheat) {
						cct_showch(x + 1, y, (user[i][j]? '0' : ' '), (user[i][j] ? 14 : 0), (user[i][j] ? 1: 7));
					}
					else {
						if (user[i][j] == 3) {
							cct_showch(x + 1, y, 'X', 14, 1);
						}
						else {
							cct_showch(x + 1, y, (user[i][j]?'0':' '), user[i][j]==2?14:0,user[i][j]==2?1:7);
						}
					}
				}
				cct_setcolor();
				cout << " |" ;
			}
			cout << endl;
			if ((i+1) % 5 == 0) {
				cct_getxy(x, y);
				cct_showch(x, y, '-', 0, 7, *rowHintLen * 2 + 1);
				cout << "+-+";
				for (int i = 0;i < size / 5;i++) {
					cct_getxy(x, y);
					cct_showch(x, y, '-', 0, 7, 2 * 5 + 1);
					cout << "+";
				}
				cout << endl;
			}
		}
	}
	//��ӡ�±���
	if (m != 'C') {
		if (m != 'A') {
			cct_getxy(x, y);
			cct_showch(x, y, '-', 0, 7, *rowHintLen * 2 + 1);
		}
		cout << "+-+";
		cct_getxy(x, y);
		cct_showch(x, y, '-', 0, 7, size * 2 + 1);
		cout << "+" << endl;
	}
}

/***************************************************************************
  �������ƣ�cMenu
  ��    �ܣ���ӡCģʽ�µ���Ϸ��ʾ
  �����������
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void cMenu()
{
	cout << endl;
	cout << "������ʽ��Aa=�ȼ���ͼ����Ϸ��������ѡ��Aaλ(���ִ�Сд)" << endl;
	cout << "          (����Ҫ֧��ͼ�ν�����Ҽ���棬�ٴ�����Aa�൱�����)" << endl;
	cout << "X/x=�˳�(���н���X/x�����ִ�Сд)" << endl;
	cout << "Y/y=�ύ(���н���Y/y�����ִ�Сд)" << endl;
	cout << "Z / z = ����(���н���Z / z�����ִ�Сд)" << endl;
	cout << "Ctrl+c ǿ���˳�" << endl;
	cout << "������ : ";
}

/***************************************************************************
  �������ƣ�baseMode
  ��    �ܣ����������������A,B,C�����ڲ�����ģʽ��ʵ��
  ���������bool cheat ������ģʽ����
			char m ��ѡ���ģʽ
			int size ��ѡ�������С
			int (&answer)[MAX_SIZE][MAX_SIZE] �������������
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ������ʾ���������
			int* rowHintLen ������ʾ������󳤶ȵĵ�ַ
			int* colHintLen ������ʾ������󳤶ȵĵ�ַ
			int (&user)[MAX_SIZE][MAX_SIZE] ���û��������������
  �� �� ֵ����һ����Ҫ���е�״̬��0-�˳���С��ص����˵���2-�˳���������
  ˵    ����
***************************************************************************/
int baseMode(bool cheat,char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE])
{
	int x, y;
	for (int i = 0;i < MAX_SIZE;i++) {
		for (int j = 0;j < MAX_SIZE;j++) {
			user[i][j] = 0;
		}
	}
	initBoard(size, answer);
	generateHints(m,cheat,size, answer, rowHints, colHints, rowHintLen, colHintLen);
	if (m == 'C') {
		cout << "��ʼ���飺" << endl;
	}
	basePrint(cheat,m, size, (m=='C'?user:answer), rowHints, colHints, rowHintLen, colHintLen, user);
	if (m != 'C') {
		end();
	}
	else {
		while (1) {
			cct_setcolor();
			cMenu();
			char c[2] = { 0 };
			c[0] = _getche();
			//��x�˳�
			if (c[0] == 'x' || c[0] == 'X') {
				end();
				return 0;
			}
			//��y�ύ
			if (c[0] == 'y' || c[0] == 'Y') {
				if (checkWin(m,cheat,size,user,rowHints,colHints)) {
					continue;
				}
				else {
					return 0;
				}
			}
			//��z��������ģʽ
			if (c[0] == 'z' || c[0] == 'Z') {
				cheat=(!cheat);
				cout << endl << endl;
				cout << "����Z/z��" << endl;
				if (cheat) {
					for (int i = 0;i < MAX_SIZE;i++) {
						for (int j = 0;j < MAX_SIZE;j++) {
							if (!user[i][j]) {
								user[i][j] = answer[i][j];
							}
							else {
								user[i][j] = answer[i][j] ? 2 : 3;
							}
						}
					}
				}
				else {
					for (int i = 0;i < MAX_SIZE;i++) {
						for (int j = 0;j < MAX_SIZE;j++) {
							user[i][j] = user[i][j] == 0 || user[i][j] == 1 ? 0 : 1;
						}
					}
				}
				basePrint(cheat, m, size, user, rowHints, colHints, rowHintLen, colHintLen, user);
				continue;
			}
			//��Ctrl+Cǿ�ƽ�����������
			if (c[0] == 3) {
				return 2;
			}
			c[1] = _getche();
			if (int(c[0]) >= int('A') && int(c[0]) <= int('A' + size - 1) && int(c[1]) >= int('a') && int(c[1]) <= int('a' + size - 1)) {
					cout << endl << endl;
					cout << "����" << c[0] << c[1] << "��" << endl;
					cct_getxy(x, y);
					if (!cheat) {
						if (user[int(c[0]) - int('A')][int(c[1]) - int('a')]) {
							user[int(c[0]) - int('A')][int(c[1]) - int('a')] = 0;
						}
						else {
							user[int(c[0]) - int('A')][int(c[1]) - int('a')] = 1;
						}
					}
					else {
						user[int(c[0]) - int('A')][int(c[1]) - int('a')] = 3 - user[int(c[0]) - int('A')][int(c[1]) - int('a')];
					}
					basePrint(cheat,m, size, answer, rowHints, colHints, rowHintLen, colHintLen, user);
				}
			else {
				cct_getxy(x, y);
				cct_showstr(0, y + 1, "�������");
				cout << endl << endl << endl;
				continue;
			}
		}
	}
	return 1;
}