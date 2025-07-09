// 
#include <iostream>
#include <conio.h>
#include "7-b6.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
/***************************************************************************
  函数名称：is_leap
  功    能：判断是否是闰年
  输入参数：int y年份
  返 回 值：1-是闰年；0-不是闰年
  说    明：
***************************************************************************/
bool Date::is_leap(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

/***************************************************************************
  函数名称：get_days_in_month
  功    能：获取某年某月的天数
  输入参数：int y ：年份
            int m ：月份
  返 回 值：该年该月的天数
  说    明：
***************************************************************************/
int Date::get_days_in_month(int y, int m) const {
    if (m < 1 || m > 12) {
        return 0;
    }
    const int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && is_leap(y)) {
        return 29;
    }
    return days_in_month[m];
}
/***************************************************************************
  函数名称：add_day
  功    能：将日期增加一天
  输入参数：无
  返 回 值：无
  说    明：
***************************************************************************/
void Date::add_day() {
    day++;
    if (day > get_days_in_month(year, month)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

// 规范化日期，处理所有非法值（核心逻辑）
void Date::normalize() {
    // 1. 按顺序处理年份
    if (year < 1900 || year > 2099) {
        year = 2000;
    }
    // 2. 按顺序处理月份
    if (month < 1 || month > 12) {
        month = 1;
    }
    // 3. 按顺序处理日期 (此时年、月已修正)
    if (day < 1 || day > get_days_in_month(year, month)) {
        day = 1;
    }
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
Date::Date() {
    year = 2000;
    month = 1;
    day = 1;
}
Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
    normalize(); 
}
Date::Date(int total_days) {
    if (total_days < 1) {
        total_days = 1;
    }
    if (total_days > 73049) {
        total_days = 73049;
    }
    year = 1900;
    month = 1;
    day = 1;
    for (int i = 1; i < total_days; ++i) {
        add_day();
    }
}
void Date::set(int y, int m, int d) {
    if (y != 0) {
        this->year = y;
    }
    if (m != 0) {
        this->month = m;
    }
    if (d != 0) {
        this->day = d;
    }
    normalize(); 
}
void Date::get(int& y, int& m, int& d) const {
    y = this->year;
    m = this->month;
    d = this->day;
}
void Date::show() const {
    cout << year << "." << month << "." << day << endl;
}
