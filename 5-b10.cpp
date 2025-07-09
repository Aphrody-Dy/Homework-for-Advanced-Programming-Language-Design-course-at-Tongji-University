// 
#include <iostream>
#include <iomanip>
using namespace std;

// 判断闰年
bool run(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

//各月最大天数
int L(int y, int month) {
    int L[12] = { 31, 28 + run(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return L[month];
}

//填充月历
void fill(int days[42], int y, int m, int s) {
    for (int i = 0; i < 42; i++) {
        days[i] = 0;
    }
    for (int i = 0; i < L(y, m); i++) {
        days[s + i] = i + 1;
    }
}

void output(int y, int i, int p, int d1[]) {
    const int ROWS = 6;
    int m[12][42];

    for (int j = 0; j < p && (i + j) < 12; j++) {
        fill(m[j], y, i + j, d1[i + j]);
    }

    for (int j = 0; j < p && (i + j) < 12; j++) {
        cout << setw(13) << right << (i + j + 1) << "月" << setw(17) << "";
    }
    cout << endl;

    for (int j = 0; j < p && (i + j) < 12; j++) {
        cout << "Sun Mon Tue Wed Thu Fri Sat " << setw(4) << "";
    }
    cout << endl;
    int row = 0;
    for (row = 0; row < ROWS; row++) {
        bool n = true;
        for (int j = 0; j < p && (i + j) < 12; j++) {
            for (int d = 0; d < 7; d++) {
                if (m[j][row * 7 + d]) {
                    n = false;
                    cout << setw(4) << left << m[j][row * 7 + d];
                }

                else {
                    cout << setw(4) << left << "";
                }
            }
            cout << setw(4) << "";
        }
        if (n) {
            break;
        }
        else {
            cout << endl;
        }
    }
    cout << endl;
}

int main() 
{
    int p, y;
    while (1) {
        cout << "请输入年份[1900-2100]" << endl;
        cin >> y;
        if (y >= 1900 && y <= 2100) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
    }
    while (1) {
        cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
        cin >> p;
        if (p == 1 || p == 2 || p == 3 || p == 4 || p == 6 || p == 12) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
    }

    int d1[12];//每月第一天的星期数
    int n = 0;
    for (int i = 1900;i < y;i++) {
        if (run(i)) {
            n++;
        }
    }
    d1[0] = (y - 1900) + 1 + n;
    d1[0] %= 7;
    for (int i = 1; i < 12; ++i) {
        d1[i] = (d1[i - 1] + L(y, i - 1)) % 7;
    }
    cout << y << "年的日历:" << endl;
    cout << endl;
    for (int i = 0; i < 12; i += p) {
        output(y, i, p, d1);
    }

    return 0;
}
