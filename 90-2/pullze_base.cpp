// 
#include <iostream>
#include <conio.h>
#include "pullze.h"
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  函数名称：initBoard
  功    能：初始化球板，随机生成半数球
  输入参数：int size ：选择的球板大小
			int (&answer)[MAX_SIZE][MAX_SIZE] ：答案数组的引用
  返 回 值：无
  说    明：
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
  函数名称：generateHints
  功    能：根据球板生成行、列提示数组
  输入参数：bool cheat ：是否开启作弊模式
			int size ：选择的球板大小
			int (&answer)[MAX_SIZE][MAX_SIZE] ：答案数组的引用
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ：行提示数组的引用
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ：列提示数组的引用
			int* rowHintLen ：行提示数组最大长度的地址
			int* colHintLen ：列提示数组最大长度的地址
  返 回 值：无
  说    明：
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
	// 生成行提示
	for (int i = 0;i < size;i++) {
		bool b = 0;
		int L = 0;
		p = &rowHints[i][0];
		for (int j = size-1;j >=0; j--) { // 为了便于打印对齐，生成提示时每行的球从后往前数
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
	// 生成列提示
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
  函数名称：basePrint
  功    能：完成内部数组模式下的各种打印
  输入参数：bool cheat ：作弊模式开关
			char m ：选择的模式
			int size ：选择的球板大小
			int (&answer)[MAX_SIZE][MAX_SIZE] ：答案数组的引用
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ：行提示数组的引用
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ：列提示数组的引用
			int* rowHintLen ：行提示数组最大长度的地址
			int* colHintLen ：列提示数组最大长度的地址
			int (&user)[MAX_SIZE][MAX_SIZE] ：用户作答数组的引用
  返 回 值：无
  说    明：
***************************************************************************/
void basePrint(bool cheat,char m,int size, int (& answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int (&user)[MAX_SIZE][MAX_SIZE])
{
	int x, y;
	if (m != 'C') {
		cout << "初始数组：" << endl;
	}
	if (m != 'A' ) {
		//打印上边线
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
		//打印列提示数字
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
		//打印中间线
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
	//打印列序号字母
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
	//打印中间线
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
	//打印行提示、行序号及数组内容
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
	//打印下边线
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
  函数名称：cMenu
  功    能：打印C模式下的游戏提示
  输入参数：无
  返 回 值：无
  说    明：
***************************************************************************/
void cMenu()
{
	cout << endl;
	cout << "命令形式：Aa=等价于图形游戏中鼠标左键选择Aa位(区分大小写)" << endl;
	cout << "          (不需要支持图形界面的右键打叉，再次输入Aa相当于清除)" << endl;
	cout << "X/x=退出(新行仅有X/x，不分大小写)" << endl;
	cout << "Y/y=提交(新行仅有Y/y，不分大小写)" << endl;
	cout << "Z / z = 作弊(新行仅有Z / z，不分大小写)" << endl;
	cout << "Ctrl+c 强制退出" << endl;
	cout << "请输入 : ";
}

/***************************************************************************
  函数名称：baseMode
  功    能：调用上述函数完成A,B,C三个内部数组模式的实现
  输入参数：bool cheat ：作弊模式开关
			char m ：选择的模式
			int size ：选择的球板大小
			int (&answer)[MAX_SIZE][MAX_SIZE] ：答案数组的引用
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ：行提示数组的引用
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ：列提示数组的引用
			int* rowHintLen ：行提示数组最大长度的地址
			int* colHintLen ：列提示数组最大长度的地址
			int (&user)[MAX_SIZE][MAX_SIZE] ：用户作答数组的引用
  返 回 值：下一步将要进行的状态（0-退出该小题回到主菜单，2-退出整个程序）
  说    明：
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
		cout << "初始数组：" << endl;
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
			//按x退出
			if (c[0] == 'x' || c[0] == 'X') {
				end();
				return 0;
			}
			//按y提交
			if (c[0] == 'y' || c[0] == 'Y') {
				if (checkWin(m,cheat,size,user,rowHints,colHints)) {
					continue;
				}
				else {
					return 0;
				}
			}
			//按z进入作弊模式
			if (c[0] == 'z' || c[0] == 'Z') {
				cheat=(!cheat);
				cout << endl << endl;
				cout << "输入Z/z后：" << endl;
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
			//按Ctrl+C强制结束整个程序
			if (c[0] == 3) {
				return 2;
			}
			c[1] = _getche();
			if (int(c[0]) >= int('A') && int(c[0]) <= int('A' + size - 1) && int(c[1]) >= int('a') && int(c[1]) <= int('a' + size - 1)) {
					cout << endl << endl;
					cout << "输入" << c[0] << c[1] << "后：" << endl;
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
				cct_showstr(0, y + 1, "输入错误");
				cout << endl << endl << endl;
				continue;
			}
		}
	}
	return 1;
}