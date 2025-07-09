//
#include <iostream>
#include <iomanip>
using namespace std;
int h[3][10],s=0;
void move(int n, int src, int dst)
{
    for (int i = 0;i < 10;i++) {
        if (h[src - 65][i] == n) {
            h[src - 65][i] = 0;
        }
    }
    for (int i = 0;i < 10;i++) {
        if (h[dst - 65][i] == 0) {
            h[dst - 65][i] = n;
            break;
        }
    }
}
void output()
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
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        s++;
        cout << "第" << setw(4) << right << s << " 步";
        cout << "(" << setw(2) << n << "): "<<src << "-->" << dst<<" ";
        move(n, src, dst);
        output();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        s++;
        cout << "第" << setw(4) << right << s << " 步";
        cout << "(" << setw(2) << n << "): " << src << "-->" << dst<<" ";
        move(n, src, dst);
        output();
        hanoi(n - 1, tmp, src, dst);
    }
}
int main()
{
    int n;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 10;j++) {
            h[i][j] = 0;
        }
    }
    char src, tmp = 0, dst;
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(100000, '\n');
        if (n >= 1 && n <= 10) {
            break;
        }
        else {
            continue;
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        src = getchar();
        while (getchar() != '\n');
        if (src != 'A' && src != 'B' && src != 'C' && src != 'a' && src != 'b' && src != 'c') {
            continue;
        }
        else {
            if (src > 67) {
                src -= 32;
            }
            break;
        }
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        dst = getchar();
        while (getchar() != '\n');
        if ((dst != 'A' && dst != 'B' && dst != 'C' && dst != 'a' && dst != 'b' && dst != 'c')) {
            continue;
        }
        else {
            if (dst > 67) {
                dst -= 32;
            }
            if (dst == src) {
                cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
                continue;
            }
            break;
        }
    }
    for (int i = 65;i < 68; i++) {
        if (i != int(src) && i != int(dst)) {
            tmp = char(i);
        }
    }
    for (int i = 0;i < n;i++) {
        h[int(src - 65)][i] = n - i;
    }
    cout <<setw(21)<<left<< "初始:";
    output();
    hanoi(n, src, tmp, dst);
    return 0;
}
