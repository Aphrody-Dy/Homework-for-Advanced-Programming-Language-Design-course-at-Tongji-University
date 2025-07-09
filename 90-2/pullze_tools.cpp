// 
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "pullze.h"
using namespace std;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

/* 提示：空文件，仅为了提醒你不要忘记首行 && 不要把文件名弄错 */

/***************************************************************************
  函数名称：menu
  功    能：打印菜单并输入所选模式
  输入参数：int* size ：所选球板大小的指针
  返 回 值：所选模式对应的序号字符
  说    明：
***************************************************************************/
char menu(int *size)
{
	cct_setfontsize("新宋体", 16);
	cct_cls();
	cct_setconsoleborder(120, 60,1000,1000);
	cout << "---------------------------------------------------------" << endl;
	cout << "A.内部数组，原样输出" << endl;
	cout << "B.内部数组，生成提示行列并输出" << endl;
	cout << "C.内部数组，游戏版" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "D.n * n的框架(无分隔线)，原样输出" << endl;
	cout << "E.n * n的框架(无分隔线)，含提示行列" << endl;
	cout << "F.n * n的框架(无分隔线)，显示初始状态，鼠标移动可显示坐标" << endl;
	cout << "G.cmd图形界面完整版(无分隔线)" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "H.n * n的框架(有分隔线)，原样输出" << endl;
	cout << "I.n * n的框架(有分隔线)，含提示行列" << endl;
	cout << "J.n * n的框架(有分隔线)，显示初始状态，鼠标移动可显示坐标" << endl;
	cout << "K.cmd图形界面完整版(有分隔线)" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Q.退出" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "[请选择:]";

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
		cout << "请输入区域大小(5/10/15)：";
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
  函数名称：end
  功    能：实现每小题结束后输入end（无需回车！）返回菜单
  输入参数：无
  返 回 值：无
  说    明：麻烦老师/助教注意下，这里的设计是end输入正确自动跳转回菜单，
			若满3个字符且输入错误自动清除，光标回到待输入原位，无需按回车。
***************************************************************************/
void end() 
{
	cout << endl;
	cout << "本小题结束，请输入End继续...";
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
			cct_showstr(0, y + 1, "输入错误，请重新输入");
			cct_showch(x, y, ' ',0,7,3);
			cct_gotoxy(x, y);
			continue;
		}
	}
}

/***************************************************************************
  函数名称：checkWin
  功    能：判断提交是否正确
  输入参数：bool cheat ：作弊模式开关
			int size ：选择的球板大小
			int (&user)[MAX_SIZE][MAX_SIZE] ：用户作答数组的引用
			int (&rowHints)[MAX_SIZE][MAX_SIZE/2+1] ：行提示数组的引用
			int (&colHints)[MAX_SIZE][MAX_SIZE/2+1] ：列提示数组的引用
			int* rowHintLen ：行提示数组最大长度的地址
			int* colHintLen ：列提示数组最大长度的地址
  返 回 值：0-提交成功，1-提交错误
  说    明：
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
				cout<< "提交错误，可用作弊模式查看" << endl;
				return 1;
			}
		}
	}
	if (b) {
		cout << endl << "提交成功，游戏结束" << endl;
		end();
	}
	return 0;
}
















