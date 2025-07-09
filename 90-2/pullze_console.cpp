// 
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "pullze.h"
#include "cmd_console_tools.h"
using namespace std;


/***************************************************************************
  函数名称：visualPrint
  功    能：D-G无边边框模式下的打印
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
void visualPrint(bool cheat, char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE])
{
	cct_cls();
	cct_setfontsize("新宋体", 35);//改成根据size调字体大小
	cct_setconsoleborder(120, 50,-1,100);
	if (m == 'F') {
		cout << "测试键盘/鼠标左键/右键，按回车退出";
	}
	if (m == 'G') {
		cout << "左键选〇/右键选×,Y/y提交,Z/z作弊,Q/q结束";
	}
	cout << endl;
	int x, y;
	if (m != 'D') {
		//打印上边线
		cct_getxy(x, y);
		cct_showstr(x+ *rowHintLen * 2 + 6, y, "╔", 7, 0);
		cct_getxy(x, y);
		cct_showstr(x, y, "═", 7, 0, size);
		cct_getxy(x, y);
		cct_showstr(x, y, "╗", 7, 0);
		cct_setcolor();
		cout << endl;
		//打印列提示数字
		for (int j = 0;j < *colHintLen;j++) {
			cct_getxy(x, y);
			cct_showstr(x + *rowHintLen * 2 + 6, y, "║", 7, 0);
			for (int i = 0;i < size;i++) {
				cct_setcolor(7, 0);
				cct_getxy(x, y);
				cout << ' ' << (colHints[i][*colHintLen - 1 - j] ? char(colHints[i][*colHintLen - 1 - j] + '0') : ' ');
			}
			cct_getxy(x,y);
			cct_showstr(x, y, "║", 7, 0);
			cct_setcolor();
			cout << endl;
		}
		//打印中间线
		cct_getxy(x, y);
		cct_showstr(x + *rowHintLen * 2 + 6, y, "╠", 7, 0);
		cct_getxy(x, y);
		cct_showstr(x, y, "═", 7, 0, size);
		cct_getxy(x, y);
		cct_showstr(x, y, "╣", 7, 0);
		cct_setcolor();
		cout << endl;
		cct_getxy(x, y);
		cct_showstr(x + *rowHintLen * 2 + 6, y, "║", 7, 0);
		cct_setcolor();
	}
	else {
		cout << setw(3) << ' ';
	}
	//打印列序号字母
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
		cct_showstr(x, y, "║", 7, 0);
	}
	cct_setcolor();
	cout << endl;
	//打印中间线
	if (m != 'D') {
		cct_getxy(x, y);
		cct_showstr(x, y, "╔", 7, 0);
		cct_showstr(x + 2, y, "═", 7, 0, *rowHintLen);
		cct_showstr(x + 2 + *rowHintLen * 2, y, "╦═╬",7, 0);
	}
	else {
		cout << setw(2) << ' ';
		cct_getxy(x, y);
		cct_showstr(x, y, "╔", 7, 0);
		Sleep(1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "═", 7, 0, size);
	if (m == 'D') {
		Sleep(1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y,m=='D'?"╗":"╣", 7, 0);
	cct_setcolor();
	cout << endl;
	//打印行提示、行序号及数组内容
	for (int i = 0;i < size;i++) {
		if (m != 'D') {
			cct_setcolor(7, 0);
			cct_getxy(x, y);
			cct_showstr(x, y, "║",7,0);
			for (int j = 0;j < *rowHintLen;j++) {
				cct_getxy(x, y);
				cct_showch(x, y, ' ',7, 0);
				cct_showch(x + 1, y, (rowHints[i][*rowHintLen - 1 - j] ? char(rowHints[i][*rowHintLen - 1 - j] + '0') : ' '), 7, 0);
			}
			cct_getxy(x, y);
			cct_showstr(x, y, "║ ",7,0);

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
		cct_showstr(x, y, "║",7,0);
		for (int j = 0;j < size;j++) {
			if (m == 'D') {
				Sleep(1);
			}
			cct_getxy(x, y);
			if (m != 'G') {
				cct_showstr(x, y, answer[i][j] ? "〇" : "  ", answer[i][j] ? 1 : 7, 0);
			}
			else {
				cct_showstr(x, y, "  ", 7,7);
			}
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "║", 7, 0);
		cct_setcolor();
		cout << endl;
	}
	//打印下边线
	if (m != 'D' && m != 'H') {
		cct_getxy(x, y);
		cct_showstr(x, y, "╚", 7, 0);
		cct_showstr(x + 2, y, "═", 7, 0, *rowHintLen);
		cct_showstr(x + 2 + *rowHintLen * 2, y, "╩═╩", 7, 0);
	}
	else {
		cct_setcolor();
		cout << setw(2) << ' ';
		Sleep(1);
		cct_getxy(x, y);
		cct_showstr(x, y, "╚", 7, 0);
		Sleep(1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "═", 7, 0, size);
	cct_getxy(x, y);
	cct_showstr(x, y, "╝", 7, 0);
	cct_setcolor();
	cout << endl;
}

/***************************************************************************
  函数名称：frameCell
  功    能：在H-K有边框模式下，在指定位置绘制单个方格
  输入参数：int X ：该模式下球板起点（坐上角，不含行列提示）的横坐标
			int Y ：该模式下球板起点（坐上角，不含行列提示）的纵坐标
			int i ：所绘制元素在所属数组中的第一个下标
			int j ：所绘制元素在所属数组中的第二个下标
			int shape ：用于控制绘制的形状内容（0-空格，1-〇，2-×）
			const int bg ：背景色对应编号
			const int fg：前景色对应编号
  返 回 值：无
  说    明：
***************************************************************************/
void frameCell(int X, int Y, int i, int j, int shape,const int bg, const int fg)
{
	int x = X + 3 + 8 * j;
	int y = Y + 1 + 4 * i;
	if (shape == 0) {
		cct_showstr(x, y, "  ", bg, fg);
	}
	else if (shape == 1) {
		cct_showstr(x, y, "〇", bg, fg);
	}
	else {
		cct_showstr(x, y, "×", bg, fg);
	}
	cct_showstr(x-2, y, !shape?"  ":"║", bg, fg);
	cct_showstr(x + 2, y, !shape ? "  " : "║", bg, fg);
	cct_showstr(x, y-1, !shape ? "  " : "═", bg, fg);
	cct_showstr(x, y + 1, !shape ? "  " : "═", bg, fg);
	cct_showstr(x+2, y + 1, !shape ? "  " : "╝", bg, fg);
	cct_showstr(x - 2, y + 1, !shape ? "  " : "╚", bg, fg);
	cct_showstr(x - 2, y - 1, !shape ? "  " : "╔", bg, fg);
	cct_showstr(x + 2, y - 1, !shape ? "  " : "╗", bg, fg);
}

/***************************************************************************
  函数名称：framePrint
  功    能：H-K有边边框模式下的打印
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
void framePrint(bool cheat, char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE])
{
	int x, y;
	cct_cls();
	cct_setfontsize("新宋体", 9+(4-size/5)*4);
	cct_setconsoleborder(size*8+(*rowHintLen+5)*2, size * 4 + *colHintLen + 10,50,50);

	if (m == 'J') {
		cout << "测试键盘/鼠标左键/右键，按回车退出";
	}
	if (m == 'K') {
		cout << "左键选〇/右键选×,Y/y提交,Z/z作弊,Q/q结束";
	}
	if (m != 'H') {
		//打印列提示及上方边框
		cct_showstr((*rowHintLen + 3) * 2, 1, "╔", 7, 0);
		cct_getxy(x, y);
		cct_showstr(x, y, "═", 7, 0, size * 4 - 1);
		cct_getxy(x, y);
		cct_showstr(x, y, "╗", 7, 0);
		cct_setcolor();
		cout << endl;
		for (int j = 0;j < *colHintLen;j++) {
			cct_showstr((*rowHintLen + 3) * 2, 2 + j, "║", 7, 0);
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
			cct_showstr(x, y, "║", 7, 0);
			cct_setcolor();
			cout << endl;
		}
		cct_getxy(x, y);
		cct_showstr((*rowHintLen + 3) * 2, y, "╠", 7, 0);
		cct_getxy(x, y);
		cct_showstr(x, y, "═", 7, 0, ((size - 1) * 8 + 6) / 2);
		cct_getxy(x, y);
		cct_showstr(x, y, "╣", 7, 0);
		cct_setcolor();
		cout << endl;
		cct_getxy(x, y);
		cct_showstr((*rowHintLen + 3) * 2, y, "║  ", 7, 0);
	}
	else {
		cct_showch(0, 0, ' ', 0, 7, 6);
	}
	//打印列序号
	for (int i = 0;i < size;i++) {
		Sleep(1);
		cct_getxy(x, y);
		cct_showch(x, y, char('a' + i),m=='H'?0:7,m=='H'?7:0);
		cct_showch(x+1, y, ' ', m == 'H' ? 0 : 7, m == 'H' ? 7 : 0, i==size-1?3:7);
	}
	if (m != 'H') {
		cct_getxy(x, y);
		cct_showstr(x, y, "║", 7, 0);
	}
	cct_setcolor();
	cout << endl;
	
	//打印列提示与列序号分割线
	if (m != 'H') {
		cct_getxy(x, y);
		cct_showstr(x, y, "╔", 7, 0);
		cct_showstr(x+2, y, "═", 7, 0, *rowHintLen);
		cct_showstr(x + 2 + *rowHintLen * 2, y, "╦═╬", 7, 0);

	}
	else {
		cct_showstr(2, 1, "╔", 7, 0);
	}
	for (int i = 0;i < size;i++) {
		Sleep(1);
		cct_getxy(x, y);
		cct_showstr(x, y, "═", 7, 0, 3);
		cct_getxy(x, y);
		if (i == size - 1) {
			cct_showstr(x, y, m=='H'?"╗":"╣", 7, 0);
			break;
		}
		cct_showstr(x, y, "╦", 7, 0);
	}
	cct_setcolor();
	cout << endl;
	//打印中部框线
	for (int i = 0;i < size;i++) {
		int j = 0;
		for (j = 0;j < 4;j++) {
			Sleep(1);
			if (m != 'H') {
				if (i == size - 1 && j == 3) {
					break;
				}
				cct_getxy(x, y);
				cct_showstr(x, y, "║", 7, 0);
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
				cct_showstr(x, y, "║", 7, 0);
			}
			cct_getxy(x, y);
			cct_showch(x, y, j==1?char('A' + i):' ', m=='H'?0:7,m=='H'? 7:0);
			cct_showch(x + 1, y, ' ', m == 'H' ? 0 : 7, m == 'H' ? 7 : 0);
			cct_getxy(x, y);
			if (i == size - 1 && j == 3) {
				break;
			}
			cct_showstr(x, y, j == 3 ? "╠" : "║", 7, 0);
			for (int k = 0;k < size;k++) {
				cct_getxy(x, y);
				cct_showstr(x, y, j==3?"═":"  ", 7, 0, 3,6);
				cct_getxy(x, y);
				if (k == size - 1) {
					break;
				}
				cct_showstr(x-1, y, j == 3 ? " ╬" : " ║", 7, 0);
			}
			cct_getxy(x, y);
			cct_showstr(x, y, j==3?"╣": "║", 7, 0);
			cct_setcolor();
			cout << endl;
		}
		if (i == size - 1 && j == size - 2) {
			break;
		}
	}
	//打印下边线
	if (m != 'H') {
		cct_getxy(x, y);
		cct_showstr(x, y, "╚", 7, 0);
		cct_showstr(x + 2, y, "═", 7, 0, *rowHintLen);
		cct_showstr(x + 2 + *rowHintLen * 2, y, "╩═╩", 7, 0);
	}
	else {
		cct_getxy(x, y);
		cct_showstr(x, y, "╚", 7, 0);
	}
	for (int i = 0;i < size;i++) {
		Sleep(1);
		cct_getxy(x, y);
		cct_showstr(x, y, "═", 7, 0, 3);
		cct_getxy(x, y);
		if (i == size - 1) {
			cct_showstr(x, y, "╝", 7, 0);
			break;
		}
		cct_showstr(x, y, "╩", 7, 0);
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
  函数名称：convertXY
  功    能：根据元素在所属数组的索引，转换成所在位置的坐标
  输入参数：char m ：选择的模式
			int* x ：所绘制元素在所属数组中的第一个下标的地址
			int* y ：所绘制元素在所属数组中的第二个下标的地址
			int* rowHintLen ：行提示数组最大长度的地址
			int* colHintLen ：列提示数组最大长度的地址
  返 回 值：无
  说    明：
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
  函数名称：drawCell
  功    能：配合读取鼠键的函数，判断每个鼠键操作对应的图形绘制操作
  输入参数：char m ：选择的模式
			bool cheat ：作弊模式开关
			int user1 ：本次操作前user数组对应元素的值
			int user2 ：本次操作后user数组对应元素的值
			int answer ：答案数组中相应位置元素的值
			int i ：所绘制元素在所属数组中的第一个下标
			int j ：所绘制元素在所属数组中的第二个下标
			int* rowHintLen ：行提示数组最大长度的地址
			int* colHintLen ：列提示数组最大长度的地址
			int left ：鼠标操作（0-右，1-左，2-非鼠标操作引发的绘图）
  返 回 值：
  说    明：
***************************************************************************/
int drawCell(char m,bool cheat,int user1,int user2,int answer,int i,int j,int* rowHintLen,int* colHintLen,int left)
{
	int X = (m == 'K' ? (*rowHintLen + 3) * 2 + 1 : (*rowHintLen + 1) * 2 + 6 + j * 2);
	int Y = (m == 'K' ? *colHintLen + 5 : *colHintLen + 4 + i + 1);
	if (left == 2) {
		if (cheat) {
			if (!user2) {
				if (m == 'G') {
					cct_showstr(X, Y, answer ? "〇" : "  ", answer ? 8 : 7, answer ? 0 : 7);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, answer ? 1 : 0, answer ? 8 : 7, answer ? 0 : 7);
				}
			}
			if (user2 == 1) {
				if (m == 'G') {
					cct_showstr(X, Y, "〇", answer ? 1 : 4, 0);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, 1, answer ? 1 : 4, 0);
				}
			}
			if (user2 == 2) {
				if (m == 'G') {
					cct_showstr(X, Y, "×", answer ? 1 : 4, 0);
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
					cct_showstr(X, Y, "〇", 1, 0);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, 1, 1,0);
				}
				break;
			case 2:
				if (m == 'G') {
					cct_showstr(X, Y, "×", 4, 0);
				}
				if (m == 'K') {
					frameCell(X, Y, i, j, 2, 4, 0);
				}
		}
	}
	if (cheat) {
		if (!user1) {
			if (m == 'G') {
				cct_showstr(X, Y, left ? "〇" : "×", answer ? 1 : 4, 0);
			}
			if (m == 'K') {
				frameCell(X, Y, i, j, left?1:2, answer ? 1 : 4, 0);
			}
		}
		else if (!user2) {
			if (m == 'G') {
				cct_showstr(X, Y, answer ? "〇" : "×", answer ? 8 : 7, answer ? 0 : 7);
			}
			if (m == 'K') {
				frameCell(X, Y, i, j, answer ? 1 : 2, answer ? 8 : 7, answer ? 0 : 7);
			}
		}
		else{
			if (m == 'G') {
				cct_showstr(X, Y, user2 == 2 ? "×" : "〇", answer ? 1 : 4, 0);
			}
			if (m == 'K') {
				frameCell(X, Y, i, j, user2 == 2 ? 2 : 1, answer ? 1 : 4, 0);
			}
		}
	}
	return 0;
}

/***************************************************************************
  函数名称：readMouseKey
  功    能：读取鼠标和键盘的操作并转化为界面中对应的打印操作
  输入参数：bool cheat ：作弊模式开关
			char m ：选择的模式
			int size ：选择的球板大小
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ：行提示数组的引用
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ：列提示数组的引用
			int* rowHintLen ：行提示数组最大长度的地址
			int* colHintLen ：列提示数组最大长度的地址
			int (&answer)[MAX_SIZE][MAX_SIZE] ：答案数组的引用
			int (&user)[MAX_SIZE][MAX_SIZE] ：用户作答数组的引用
  返 回 值：用于“退出”状态下提前终止函数运行并衔接下一步操作
  说    明：
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
			cout << "[读到回车键]" << endl;
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
				cout << (m=='J'||m=='K'? char((Y - *colHintLen - 5) / 4 + 'A'):char(Y - 5 - *colHintLen + 'A') )<< ' ' << "行" <<( m=='J'||m=='K'? char((X - (*rowHintLen + 4) * 2 - 1) / 8 + 'a'):char((((X - 7 - (*rowHintLen + 1) * 2) % 2 == 0) ? (X - 7 - (*rowHintLen + 1) * 2) / 2 : ((X - 7 - (*rowHintLen + 1) * 2) + 1) / 2) + 'a') )<< ' ' << "列";
				int t = 0;
				switch (maction) {
					case MOUSE_ONLY_MOVED:
						cct_showstr(6 + *rowHintLen * 2,  *colHintLen  + 6+ size * (m == 'J' || m == 'K' ? 4 : 1), "[当前光标] ",0,7);
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
						cct_showstr(6 + *rowHintLen * 2, *colHintLen + 6 + size * (m == 'J' || m == 'K' ? 4 : 1), "[读到左键] ");
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
						cct_showstr(6 + *rowHintLen * 2, *colHintLen + 6 + size * (m == 'J' || m == 'K' ? 4 : 1), "[读到右键] ");
						continue;
				}
			}
			else {
				cct_showstr(6 + *rowHintLen * 2,*colHintLen + size * (m == 'J' || m == 'K' ? 4 : 1) +6, "[当前光标] 位置非法");
			}
		}
		else if (ret == CCT_KEYBOARD_EVENT) {
			cct_showch(6 + *rowHintLen * 2, *colHintLen + size * (m == 'J' || m == 'K' ? 4 : 1) + 6, ' ', 0, 7, 19);
			cct_gotoxy(6 + *rowHintLen * 2, *colHintLen + size * (m == 'J' || m == 'K' ? 4 : 1) + 6);
			switch (keycode1) {
				case 113:
					if (m == 'G' || m == 'K') {
						cout << "[读到Q/q，游戏结束]" << endl;
						end();
						return 0;
					}
					else {
						cout << "[读到键码] " << keycode1 << '/' << keycode2;
						break;
					}
				case 121:
					if (m == 'G' || m == 'K') {
						cout << "[读到提交键]";
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
						cout << "[读到键码] " << keycode1 << '/' << keycode2;
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
						cout << "[作弊模式" << (cheat ? "开" : "关") << "]";
						continue;
					}
					else {
						cout << "[读到键码] " << keycode1 << '/' << keycode2;
						break;
					}
				case 224:
					switch (keycode2) {
						case KB_ARROW_UP:
							cout << "[读到上箭头]";
							continue;
						case KB_ARROW_DOWN:
							cout << "[读到下箭头]";
							continue;
						case KB_ARROW_LEFT:
							cout << "[读到左箭头]";
							continue;
						case KB_ARROW_RIGHT:
							cout << "[读到右箭头]";
							continue;
					}
				default:
					cout << "[读到键码] " << keycode1 << '/' << keycode2;
			}
		}
		if (b == 1) {
			break;
		}
	}
	return 0;
}

/***************************************************************************
  函数名称：visualMode
  功    能：D-K伪图形界面的整体运行
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
