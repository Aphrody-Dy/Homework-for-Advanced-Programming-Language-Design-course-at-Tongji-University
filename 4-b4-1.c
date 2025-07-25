// 
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu() {
	while (1) {
		printf("1.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界停止)\n");
		printf("2.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界回绕)\n");
		printf("3.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界停止）\n");
		printf("4.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界回绕）\n");
		printf("0.退出\n");
		printf("请选择[0-4]");
		int m = _getche() - 48;
		if (m >= 0 && m <= 4) {
			return m;
		}
		else {
			const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
			cls(hout);
			continue;
		}
	}
}

void move_by(const int m) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int c0, X = 35, Y = 9;
	while (1) {
		char n = 0, s = 0, w = 0, e = 0;
		c0 = _getch();
		if (m == 1 || m == 2) {
			switch (c0) {
				case 73:
				case 105:
					n = 1;
					break;
				case 74:
				case 106:
					w = 1;
					break;
				case 75:
				case 107:
					s = 1;
					break;
				case 76:
				case 108:
					e = 1;
					break;
			}
		}
		if (m == 3 || m == 4) {
			if (c0 == 224) {
				c0 = _getch();
				switch (c0) {
					case 72:
						n = 1;
						break;
					case 75:
						w = 1;
						break;
					case 80:
						s = 1;
						break;
					case 77:
						e = 1;
						break;
				}
			}
			else {
				n = s = w = e = 0;
			}

		}
		COORD coord;
		coord.X = X;
		coord.Y = Y;
		if (n) {
			if (Y == 1) {
				switch (m) {
					case 1:
					case 3:
						break;
					case 2:
					case 4:
						Y += 16;
						gotoxy(hout, X, Y);
						break;
				}
			}
			else {
				Y--;
				gotoxy(hout, X, Y);
			}
			continue;
		}
		if (s) {
			if (Y == 17) {
				switch (m) {
					case 1:
					case 3:
						break;
					case 2:
					case 4:
						Y -= 16;
						gotoxy(hout, X, Y);
						break;
				}
			}
			else {
				Y++;
				gotoxy(hout, X, Y);
			}
			continue;
		}
		if (w) {
			if (X == 1) {
				switch (m) {
					case 1:
					case 3:
						break;
					case 2:
					case 4:
						X += 68;
						gotoxy(hout, X, Y);
				}
			}
			else {
				X--;
				gotoxy(hout, X, Y);
			}
			continue;
		}
		if (e) {
			if (X == 69) {
				switch (m) {
					case 1:
					case 3:
						break;
					case 2:
					case 4:
						X -= 68;
						gotoxy(hout, X, Y);
				}
			}
			else {
				gotoxy(hout, X + 1, Y);
				X++;
			}
			continue;
		}
		if (c0 == 32) {
			showch(hout, X, Y, ' ');
			gotoxy(hout, X, Y);
		}
		if (c0 == 224) {
			c0 = _getch();
			while (c0 != ' ') {
				c0 = ' ';
				continue;
			}
			continue;
		}
		if (c0 == 113 || c0 == 81) {
			break;
		}
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	srand((unsigned int)(time(0)));		//生成伪随机数的种子，只需在程序开始时执行一次即可

	while (1) {
		cls(hout);		//此句的作用是调用系统的cls命令清屏
		int m = menu();
		if (m == 0) {
			return 0;
		}
		cls(hout);
		init_border(hout);		//显示初始的边框及其中的随机字符
		gotoxy(hout, 35, 9);
		move_by(m);

		gotoxy(hout, 0, 23);
		printf( "游戏结束，按回车键返回菜单.");
		//(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
		while (1) {
			int o = _getch();
			if (o == 13) {
				break;
			}
			else {
				continue;
			}
		}
		continue;
	}
}
