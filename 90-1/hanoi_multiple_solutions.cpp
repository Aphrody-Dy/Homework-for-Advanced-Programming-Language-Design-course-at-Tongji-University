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

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�input
  ��    �ܣ�����ά��������ݽ��к���&�������
  ���������int *n�������ĵ�ַ
            char *src����ʼ���ĵ�ַ
            char *tmp���м����ĵ�ַ
            char *dst��Ŀ��ס�ĵ�ַ
            int m����ѡ�˵�ģʽ
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void input(int *n,char *src,char *tmp,char *dst,int m)
{
    s = 0;
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
        cout << "��������ʼ��(A-C)" << endl;
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
        cout << "������Ŀ����(A-C)" << endl;
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
                cout << "Ŀ����(" << *dst << ")��������ʼ��(" << *src << ")��ͬ" << endl;
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
            cout << "�������ƶ��ٶ�(0-200��0-���س�������ʾ 1-200:��ʱ1-200ms)";
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
        cout << "�� " << *src << " �ƶ��� " << *dst << "���� " << *n << " �㣬��ʱ����Ϊ " << v << "ms";
    }
    if (m == 7) {
        while (1) {
            cout << "�������ƶ��ٶ�(0-10��0-���س�������ʾ 1-20:��ʱ1-20ms) ";
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
        cout << "�� " << *src << " �ƶ��� " << *dst << "���� " << *n << " �㣬��ʱ����Ϊ " << v << "ms";
    }
    if (m == 8||m==9) {
        while (1) {
            cout << "�������ƶ��ٶ�(0-10��0-���س�������ʾ 1-20:��ʱ1-20ms)";
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
        cout << "�� " << *src << " �ƶ��� " << *dst << "���� " << *n << " ��";
        if (m == 8) {
            cout<<"����ʱ����Ϊ " << v << "ms��ǰ7���������Զ���Ϊ0ms��";
        }
    }
}
/***************************************************************************
  �������ƣ�output
  ��    �ܣ�����ά��������ݽ��к���&�������
  ���������int m����ѡ�˵�ģʽ
  �� �� ֵ����
  ˵    ����
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
  �������ƣ�poles
  ��    �ܣ�����������������
  ���������int m����ѡ�˵�ģʽ
  �� �� ֵ����
  ˵    ����
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
  �������ƣ�initblocks
  ��    �ܣ�����ʼ���ϻ�n������
  ���������int n������
            char src����ʼ��
            int m����ѡ�˵�ģʽ
  �� �� ֵ����
  ˵    ����
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
  �������ƣ�moveblocks
  ��    �ܣ�ͼ���Բ�̵ĵ����ƶ�
  ���������int n������
            char src����ʼ��
            char dst��Ŀ����
            int srclayer���ƶ�ǰԲ������ʼ��������λ��
            int dstlayer���ƶ���Բ����Ŀ��ס������λ��
            int s���ܲ���
            int m����ѡ�˵�ģʽ
  �� �� ֵ����
  ˵    ����
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
  �������ƣ�move
  ��    �ܣ��ں�ŵ���ƶ�������ʵ�ֶ�ά����Ԫ��ֵ��ͬ���䶯�������
  ���������int n������
            char src����ʼ��
            char dst��Ŀ����
            int s���ܲ���
            int m����ѡ�˵�ģʽ
            bool b������8/9���죨0���Զ����㣻1���ֶ�������
  �� �� ֵ����
  ˵    ����
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
            cout << "��" << setw(4) << right << s << " ��";
            cout << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        }
        else {
            cout << "��ʼ:";
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
  �������ƣ�hanoi
  ��    �ܣ��õݹ麯������1-8ģʽ�к�ŵ���ĸ����ƶ�
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ����
  ˵    ����
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
  �������ƣ�mode9
  ��    �ܣ�ģʽ9��Ϸ���Ӧ������
  ���������int n������
            char dst��Ŀ����
  �� �� ֵ��0����q�˳�/��Ϸ������/1����Ϸ�����е�ĳһ����������Ϸ�������У�
  ˵    ����
***************************************************************************/
int mode9(int n,char dst)
{
    s++;
    int num;
    char c1, c2 = 0;
    while (1) {
        cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 11);
        cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
        c1 = _getch();
        if (c1 >= 33 && c1 <= 126) {
            cout << c1;
        }
        if (c1 == 'q' || c2 == 'Q') {
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + HDC_Start_Y + 12);
            cout << "��Ϸ��ֹ!!!!!";
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
            cout << "Դ��Ϊ�գ�";
            Sleep(500);
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + HDC_Start_Y + 12);
            cout << setw(10)<<" ";
            continue;
        }
        else if ((h[c2 - 65][dstlayer])&&(layer> h[c2 - 65][dstlayer])) {
            cct_gotoxy(MenuItem9_Start_X + 60, MenuItem9_Start_Y + HDC_Start_Y + 11);
            cout << "  ";
            cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + HDC_Start_Y + 12);
            cout << "����ѹС�̣��Ƿ��ƶ���";
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
        cout << "��Ϸ����!!!!!";
        return 0;
    }
    return 1;
}

