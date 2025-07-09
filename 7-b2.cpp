// 
#define _CRT_SECURE_NO_WARNINGS
#include "7-b2.h"
#include "cmd_console_tools.h"
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

#define BORDER_LEFT   "║"
#define BORDER_RIGHT  "║"
#define BORDER_TOP    "═"
#define BORDER_BOTTOM "═"
#define BORDER_TL     "╔"
#define BORDER_TR     "╗"
#define BORDER_BL     "╚"
#define BORDER_BR     "╝"

/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */

int CN(unsigned char ch) 
{
    return (ch >= 0xA1 && ch <= 0xF7);
}

int str_display_width(const char* s) 
{
    int width = 0;
    while (*s) {
        if (CN((unsigned char)*s)) {
            width += 2;
            s += 2;
        }
        else {
            width += 1;
            s += 1;
        }
    }
    return width;
}

void print_line(int x, int y, const char* s, int max_w, int bg, int fg)
{
    cct_gotoxy(x, y);
    cct_setcolor(bg, fg);
    int w = 0;
    while (*s && w < max_w) {
        if (CN((unsigned char)*s)) {
            if (w + 2 > max_w) break;
            putchar(*s); 
            putchar(*(s + 1));
            s += 2;
            w += 2;
        }
        else {
            putchar(*s);
            s++;
            w++;
        }
    }
    while (w++ < max_w) {
        putchar(' ');
    }
}

void show_menu_lines(const char menu[][MAX_ITEM_LEN], int total, int height,int offset, int sel, int top, int left, int width,int bg, int fg) 
{
    for (int i = 0; i < height; i++) {
        int idx = offset + i;
        int y = top + 1 + i;

        cct_showch(left + 1, y, ' ', bg, fg, width);

        cct_gotoxy(left, y);
        cout << BORDER_LEFT;

        if (idx < total) {
            if (i == sel) {
                if (left > 30) {
                    print_line(left + 2, y, menu[idx], width - 2, fg, bg);
                }
                else {
                    print_line(left + 2, y, menu[idx], width - 1, fg, bg);
                }
            }
            else {
                if (left > 30) {
                    print_line(left + 2, y, menu[idx], width - 2, bg, fg);
                }
                else {
                    print_line(left + 2, y, menu[idx], width - 1, bg, fg);
                }
            }
        }
    }
}

int pop_menu(const char menu[][MAX_ITEM_LEN], const PopMenu* original_para)
{
    if (!original_para) {
        return 0;
    }
    int total = 0;
    while (menu && *menu[total]) {
        total++;
    }

    int width = original_para->width;
    int title_w = str_display_width(original_para->title);
    if (title_w % 2 != 0){
        title_w++;
    }
    if (title_w + 2 > width) {
        width = title_w + 2;
    }
    if (width % 2) {
        width++;
    }
    int height = original_para->high;
    if (total > 0 && height > total) {
        height = total;
    }
    int top = original_para->start_y;
    int left = original_para->start_x;
    int bg = original_para->bg_color, fg = original_para->fg_color;

    // Top border
    cct_setcolor(bg, fg);
    cct_gotoxy(left, top); 
    cout << BORDER_TL;
    for (int i = 0; i < width; i++) {
        cout << BORDER_TOP;
    }
    cout << BORDER_TR;
    cct_showch(left + width + 2, top, ' ', bg, fg);

    // Sides and content area
    for (int i = 1; i <= (height > 0 ? height : 1); i++) {
        int y = top + i;
        cct_gotoxy(left, y);
        cout << BORDER_LEFT;
        cct_showch(left + 1, y, ' ', bg, fg, width);
        cct_gotoxy(left + width + 1, y);
        cout << BORDER_RIGHT;
        cct_showch(left + width + 2, y, ' ', bg, fg);
    }

    // Bottom border
    int bottom_y = top + (height > 0 ? height : 1) + 1;
    cct_gotoxy(left, bottom_y);
    cout << BORDER_BL;
    for (int i = 0; i < width; i++) {
        cout << BORDER_BOTTOM;
    }
    cout << BORDER_BR;
    cct_showch(left + width + 2, bottom_y, ' ', bg, fg);

    // Title
    int tx = left + 1 + (width - title_w) / 2;
    char padded_title[MAX_ITEM_LEN];
    strcpy(padded_title, original_para->title);
    if (str_display_width(original_para->title) % 2 != 0) {
        strcat(padded_title, " ");
    }
    if (tx - 1 > left) {
        cct_gotoxy(tx - 1, top); 
        putchar(' ');
    }
    print_line(tx, top, padded_title, title_w, bg, fg);

    if (total == 0) {
        while (_getch() != 13);
        return 0;
    }

    int sel = 0, offset = 0;
    show_menu_lines(menu, total, height, offset, sel, top, left, width, bg, fg);

    while (true) {
        int ch = _getch();
        if (ch == 13) {
            return offset + sel + 1;
        }
        if (ch == 224 || ch == 0) {
            ch = _getch();
            if (ch == 72) {
                if (sel > 0) {
                    sel--;
                }
                else if (offset > 0) {
                    offset--;
                }
            }
            else if (ch == 80) {
                if (sel < height - 1 && offset + sel + 1 < total) {
                    sel++;
                }
                else if (offset + height < total) {
                    offset++;
                }
            }
            show_menu_lines(menu, total, height, offset, sel, top, left, width, bg, fg);
        }
    }
    return 0;
}
