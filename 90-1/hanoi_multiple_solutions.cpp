// 
#include"cmd_console_tools.h"
#include"hanoi_const_value.h"
#include"cmd_hdc_tools.h"
#include<iostream>
#include<iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;
int h[3][10], s = 0,v=0,srclayer=0,dstlayer=0,layer=0;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：input
  功    能：将二维数组的内容进行横向&纵向输出
  输入参数：int *n：层数的地址
            char *src：起始柱的地址
            char *tmp：中间柱的地址
            char *dst：目标住的地址
            int m：所选菜单模式
  返 回 值：无
  说    明：
***************************************************************************/
void input(int *n,char *src,char *tmp,char *dst,int m)
{
    s = 0;
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> *n;
        cin.clear();
        cin.ignore(100000, '\n');
        if (*n >= 1 && *n <= 10) {
            break;
        }
        else {
            continue;
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        *src = getchar();
        while (getchar() != '\n');
        if (*src != 'A' && *src != 'B' && *src != 'C' && *src != 'a' && *src != 'b' && *src != 'c') {
            continue;
        }
        else {
            if (*src > 67) {
                *src -= 32;
            }
            break;
        }
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        *dst = getchar();
        while (getchar() != '\n');

        if ((*dst != 'A' && *dst != 'B' && *dst != 'C' && *dst != 'a' && *dst != 'b' && *dst != 'c')) {
            continue;
        }
        else {
            if (*dst > 67) {
                *dst -= 32;
            }
            if (*dst == *src) {
                cout << "目标柱(" << *dst << ")不能与起始柱(" << *src << ")相同" << endl;
                continue;
            }
            break;
        }
    }
    for (int i = 65;i < 68; i++) {
        if (i != int(*src) && i != int(*dst)) {
            *tmp = char(i);
        }
    }
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 10;j++) {
            h[i][j] = 0;
        }
    }
    for (int i = 0;i < *n;i++) {
        h[int(*src - 65)][i] = *n - i;
    }
    if (m == 4) {
        while (1) {
            cout << "请输入移动速度(0-200：0-按回车单步演示 1-200:延时1-200ms)";
            cin >> v;
            if (v >= 0 && v <= 200) {
                break;
            }
            else {
                continue;
            }
        }
        cct_cls();
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y + 2);
        cout << "从 " << *src << " 移动到 " << *dst << "，共 " << *n << " 层，延时设置为 " << v << "ms";
    }
    if (m == 7) {
        while (1) {
            cout << "请输入移动速度(0-10：0-按回车单步演示 1-20:延时1-20ms) ";
            cin >> v;
            if (v >= 0 || v <= 20) {
                break;
            }
            else {
                continue;
            }
        }
        cct_cls();
        cct_gotoxy(0, 90);
        cout << "从 " << *src << " 移动到 " << *dst << "，共 " << *n << " 层，延时设置为 " << v << "ms";
    }
    if (m == 8||m==9) {
        while (1) {
            cout << "请输入移动速度(0-10：0-按回车单步演示 1-20:延时1-20ms)";
            cin >> v;
            if (v >= 0 || v <= 20) {
                break;
            }
            else {
                continue;
            }
        }
        cct_cls();
        cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y+13);
        cout << "从 " << *src << " 移动到 " << *dst << "，共 " << *n << " 层";
        if (m == 8) {
            cout<<"，延时设置为 " << v << "ms（前7步，后面自动变为0ms）";
        }
    }
}
/***************************************************************************
  函数名称：output
  功    能：将二维数组的内容进行横向&纵向输出
  输入参数：int m：所选菜单模式
  返 回 值：无
  说    明：
***************************************************************************/
void output(int m)
{
    for (int i = 0;i < 3;i++) {
        cout << char(i + 65) << ":";
        for (int j = 0;j < 10;j++) {
            if (j == 0) {
                if (h[i][j]) {
                    cout << setw(2) << right << h[i][j] << " ";
                }
                else {
                    cout << "   ";
                }
            }
            else {
                if (h[i][j]) {
                    cout << h[i][j];
                }
                else {
                    cout << " ";
                }
                cout << ' ';
            }
        }
    }
    cout << endl;
    if (m == 4||m==8||m==9) {
        for (int i = 0;i < 3;i++) {
            for (int j = 0;j < 10;j++) {
                if (m == 4) {
                    cct_gotoxy(MenuItem4_Start_X + Underpan_A_X_OFFSET + Underpan_Distance * i, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - 2 - j);
                }
                if (m == 8||m==9) {
                    cct_gotoxy(MenuItem8_Start_X+ Underpan_A_X_OFFSET + Underpan_Distance * i, MenuItem8_Start_Y+10 + Underpan_A_Y_OFFSET - 2 - j);
                }
                if (h[i][j]) {
                    cout << h[i][j];
                }
                else {
                    cout << " ";
                }
            }
        }
    }
}
/***************************************************************************
  函数名称：poles
  功    能：画三个底座和柱子
  输入参数：int m：所选菜单模式
  返 回 值：无
  说    明：
***************************************************************************/
void poles(int m)
{
    hdc_init(HDC_COLOR[0],0,1000, 1000);
    for (int i = 0;i < 3;i++) {
        Sleep(HDC_Init_Delay);
        hdc_rectangle(HDC_Start_X+i*(23 * HDC_Base_Width+HDC_Underpan_Distance), HDC_Start_Y,  23 * HDC_Base_Width, HDC_Base_High, HDC_COLOR[11]);
    }
    for (int i = 0;i < 3;i++) {
        Sleep(HDC_Init_Delay);
        hdc_rectangle(HDC_Start_X + 11 * HDC_Base_Width+i * (23 * HDC_Base_Width + HDC_Underpan_Distance), HDC_Start_Y- 12 * HDC_Base_High, HDC_Base_Width, 12*HDC_Base_High, HDC_COLOR[11]);
    }
}
/***************************************************************************
  函数名称：initblocks
  功    能：在起始柱上画n个盘子
  输入参数：int n：层数
            char src：起始柱
            int m：所选菜单模式
  返 回 值：无
  说    明：
***************************************************************************/
void initblocks(int n,char src,int m)
{
    hdc_init(HDC_COLOR[0], 0, 1000, 1000);
    for (int i = 0;i < n;i++) {
        Sleep(HDC_Init_Delay);
        hdc_rectangle(HDC_Start_X + (src - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance) + HDC_Base_Width * (11-n+i), HDC_Start_Y - HDC_Base_High * (i + 1), (21 - 2 * (10-n+i)) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[n-i]);
    }
}
/***************************************************************************
  函数名称：moveblocks
  功    能：图解版圆盘的单步移动
  输入参数：int n：层数
            char src：起始柱
            char dst：目标柱
            int srclayer：移动前圆盘在起始柱所处的位置
            int dstlayer：移动后圆盘在目标住所处的位置
            int s：总步数
            int m：所选菜单模式
  返 回 值：无
  说    明：
***************************************************************************/
void moveblocks(int n, char src, char dst,int srclayer,int dstlayer,int s,int m)
{
    hdc_init(HDC_COLOR[0], 0, 1000, 1000);
    for (int i = HDC_Start_Y - HDC_Base_High * (srclayer+1);i > HDC_Top_Y;i -= HDC_Step_Y) {
        if (s <= 7) {
            if (v) {
                Sleep(v);
            }
            if (v == 0) {
                while (1) {
                    if (_getch() == 13) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
            }
        }
        else {
            Sleep(0);
        }
        hdc_rectangle(HDC_Start_X + (src - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance) + HDC_Base_Width * (11-n), i, (1+2*n) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[0]);
        if (i >= HDC_Start_Y - 12 * HDC_Base_High) {
            hdc_rectangle(HDC_Start_X + 11 * HDC_Base_Width + (src - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance), i, HDC_Base_Width, HDC_Base_High, HDC_COLOR[11]);
        }
        hdc_rectangle(HDC_Start_X + (src - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance) + HDC_Base_Width * (11-n), i - HDC_Step_Y, (1+2*n) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[n]);
    }
    if (src < dst) {
        for (int i = HDC_Start_X + (src - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance) + HDC_Base_Width * (11-n);i < HDC_Start_X + (dst - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance) + HDC_Base_Width * (11-n);i += HDC_Step_X) {
            if (s <= 7) {
                if (v) {
                    Sleep(v);
                }
                if (v == 0) {
                    while (1) {
                        if (_getch() == 13) {
                            break;
                        }
                        else {
                            continue;
                        }
                    }
                }
            }
            else {
                Sleep(0);
            }
            hdc_rectangle(i, HDC_Top_Y, (1+2*n) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[0]);
            hdc_rectangle(i + HDC_Step_X, HDC_Top_Y, (1+2*n) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[n]);
        }
    }
    else {
        for (int i = HDC_Start_X + (src - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance) + HDC_Base_Width * (11-n);i > HDC_Start_X + (dst - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance) + HDC_Base_Width * (11-n);i -= HDC_Step_X) {
            if (s <= 7) {
                if (v) {
                    Sleep(v);
                }
                if (v == 0) {
                    while (1) {
                        if (_getch() == 13) {
                            break;
                        }
                        else {
                            continue;
                        }
                    }
                }
            }
            else {
                Sleep(0);
            }
            hdc_rectangle(i, HDC_Top_Y, (1+2*n) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[0]);
            hdc_rectangle(i - HDC_Step_X, HDC_Top_Y, (1+2*n) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[n]);
        }
    }
    for (int i = HDC_Top_Y;i < HDC_Start_Y - HDC_Base_High*(dstlayer+1);i += HDC_Step_Y) {
        if (s <= 7) {
            if (v) {
                Sleep(v);
            }
            if (v == 0) {
                while (1) {
                    if (_getch() == 13) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
            }
        }
        else {
            Sleep(0);
        }
        hdc_rectangle(HDC_Start_X + (dst - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance) + HDC_Base_Width * (11-n), i, (1+2*n) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[0]);
        if (i >= HDC_Start_Y - 12 * HDC_Base_High) {
            hdc_rectangle(HDC_Start_X + 11 * HDC_Base_Width + (dst - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance), i, HDC_Base_Width, HDC_Base_High, HDC_COLOR[11]);
        }
        hdc_rectangle(HDC_Start_X + (dst - int('A')) * (23 * HDC_Base_Width + HDC_Underpan_Distance) + HDC_Base_Width * (11-n), i + HDC_Step_Y, (1+2*n) * HDC_Base_Width, HDC_Base_High, HDC_COLOR[n]);
    }
}
/***************************************************************************
  函数名称：move
  功    能：在汉诺塔移动过程中实现二维数组元素值的同步变动、简单输出
  输入参数：int n：层数
            char src：起始柱
            char dst：目标柱
            int s：总步数
            int m：所选菜单模式
            bool b：调控8/9差异（0：自动计算；1：手动操作）
  返 回 值：无
  说    明：
***************************************************************************/
void move(int n,char src, char dst, int s, int m,bool b=0)
{
    if (m == 1) {
        cout << n<<" # " << src << "---->" << dst << endl;
    }
    if (m == 2||m==3||m==4||m==8||m==9) {
        if (m == 4||m==8||m==9) {
            if (m == 4) {
                cct_gotoxy(MenuItem4_Start_X + Underpan_A_X_OFFSET - 2, MenuItem4_Start_Y + Underpan_A_Y_OFFSET - 1);
            }
            if (m == 8||m==9) {
                cct_gotoxy(MenuItem8_Start_X+ Underpan_A_X_OFFSET - 2, MenuItem8_Start_Y+10 + Underpan_A_Y_OFFSET - 1);
            }
            for (int i = 0;i < Underpan_Distance * 2 + 5;i++) {
                cout << "=";
            }
            for (int i = 0;i < 3;i++) {
                if (m == 4) {
                    cct_gotoxy(MenuItem4_Start_X + Underpan_A_X_OFFSET + Underpan_Distance * i, MenuItem4_Start_Y + Underpan_A_Y_OFFSET);
                }
                if (m == 8||m==9) {
                    cct_gotoxy(MenuItem8_Start_X+ Underpan_A_X_OFFSET + Underpan_Distance * i, MenuItem8_Start_Y+10 + Underpan_A_Y_OFFSET);
                }
                cout << char(65 + i);
            }
            if (s) {
                if (v) {
                    Sleep(v);
                }
                if (v == 0) {
                    while (1) {
                        if (_getch() == 13) {
                            break;
                        }
                        else {
                            continue;
                        }
                    }
                }
            }
            if (m == 4) {
                cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
            }
            if (m == 8||m==9) {
                cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y+10);
            }
        }
        if (s) {
            cout << "第" << setw(4) << right << s << " 步";
            cout << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        }
        else {
            cout << "初始:";
        }
        if (m ==2) {
            cout << endl;
        }
        else {
            if (m == 4) {
                cct_gotoxy(MenuItem4_Start_X+ Underpan_A_X_OFFSET+24, MenuItem4_Start_Y);
            }
            if (m == 8||m==9) {
                cct_gotoxy(MenuItem8_Start_X+ Underpan_A_X_OFFSET + 24, MenuItem8_Start_Y+10);
            }
            cout << " ";
            if (!b) {
                for (int i = 0;i < 10;i++) {
                    if (h[src - 65][i] == n) {
                        layer = n+1;
                        h[src - 65][i] = 0;
                        srclayer = i;
                    }
                }
                for (int i = 0;i < 10;i++) {
                    if (h[dst - 65][i] == 0) {
                        h[dst - 65][i] = n;
                        dstlayer = i;
                        break;
                    }
                }
            }
            output(m);
            if (m == 8&&b==0) {
                moveblocks(n, src, dst, srclayer, dstlayer,s,m);
            }
        }
    }
}
/***************************************************************************
  函数名称：hanoi
  功    能：用递归函数计算1-8模式中汉诺塔的各步移动
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：无
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst,int m)
{
    if (n == 1) {
        s++;
        move(n,src, dst, s, m);
    }
    else {
        hanoi(n - 1, src, dst, tmp,m);
        s++;
        move(n,src, dst, s, m);
        hanoi(n - 1, tmp, src, dst,m);
    }
}
/***************************************************************************
  函数名称：mode9
  功    能：模式9游戏版对应函数，
  输入参数：int n：层数
            char dst：目标柱
  返 回 值：0（按q退出/游戏结束）/1（游戏过程中的某一步，往后游戏继续进行）
  说    明：
***************************************************************************/
int mode9(int n,char dst)
{
    s++;
    int num;
    char c1, c2 = 0;
    while (1) {
        cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 11);
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
        c1 = _getch();
        if (c1 >= 33 && c1 <= 126) {
            cout << c1;
        }
        if (c1 == 'q' || c2 == 'Q') {
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + HDC_Start_Y + 12);
            cout << "游戏中止!!!!!";
            return 0;
        }
        c2 = _getch();
        if (c2 >= 33 && c2 <= 126) {
            cout << c2;
        }
        if (c1 > 67) {
            c1 -= 32;
        }
        if (c2 > 67) {
            c2 -= 32;
        }
        if ((c1 != 'A' && c1 != 'B' && c1 != 'C') || (c2 != 'A' && c2 != 'B' && c2 != 'C')) {
            cct_gotoxy(MenuItem9_Start_X+60, MenuItem9_Start_Y + HDC_Start_Y + 11);
            cout << "  ";
            continue;
        }
        else if (h[c1 - 65][0] == 0) {
            cct_gotoxy(MenuItem9_Start_X + 60, MenuItem9_Start_Y + HDC_Start_Y + 11);
            cout << "  ";
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + HDC_Start_Y + 12);
            cout << "源柱为空！";
            Sleep(500);
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + HDC_Start_Y + 12);
            cout << setw(10)<<" ";
            continue;
        }
        else if ((h[c2 - 65][dstlayer])&&(layer> h[c2 - 65][dstlayer])) {
            cct_gotoxy(MenuItem9_Start_X + 60, MenuItem9_Start_Y + HDC_Start_Y + 11);
            cout << "  ";
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + HDC_Start_Y + 12);
            cout << "大盘压小盘，非法移动！";
            Sleep(500);
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + HDC_Start_Y + 12);
            cout << setw(22) << " ";
            continue;
        }
        else {
            break;
        }
    }
    for (int i = 0;i < 10;i++) {
        if (h[c1 - 65][i] != 0) {
            num = h[c1 - 65][i];
        }
    }
    move(num, c1, c2, s, 9);
    moveblocks(num, c1, c2, srclayer, dstlayer, s, 9);
    int win=0;
    for (int i = 0;i < n;i++) {
        if (h[dst - 65][i] == n - i) {
            win++;
        }
    }
    if (win == n) {
        cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + HDC_Start_Y + 12);
        cout << "游戏结束!!!!!";
        return 0;
    }
    return 1;
}

