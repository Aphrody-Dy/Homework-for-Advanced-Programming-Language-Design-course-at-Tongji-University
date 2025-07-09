// 
#include <iostream>
#include <conio.h>
#include "7-b6.h"
using namespace std;

/* ���� Date ������г�Ա����������ʵ�� */
/***************************************************************************
  �������ƣ�is_leap
  ��    �ܣ��ж��Ƿ�������
  ���������int y���
  �� �� ֵ��1-�����ꣻ0-��������
  ˵    ����
***************************************************************************/
bool Date::is_leap(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

/***************************************************************************
  �������ƣ�get_days_in_month
  ��    �ܣ���ȡĳ��ĳ�µ�����
  ���������int y �����
            int m ���·�
  �� �� ֵ��������µ�����
  ˵    ����
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
  �������ƣ�add_day
  ��    �ܣ�����������һ��
  �����������
  �� �� ֵ����
  ˵    ����
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

// �淶�����ڣ��������зǷ�ֵ�������߼���
void Date::normalize() {
    // 1. ��˳�������
    if (year < 1900 || year > 2099) {
        year = 2000;
    }
    // 2. ��˳�����·�
    if (month < 1 || month > 12) {
        month = 1;
    }
    // 3. ��˳�������� (��ʱ�ꡢ��������)
    if (day < 1 || day > get_days_in_month(year, month)) {
        day = 1;
    }
}

/* �������Ҫ������ȫ�ֺ�����ʵ�֣�����д�ڴ˴� */
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
