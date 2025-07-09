// 
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
               3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int i = 0;
    if (n == 1) {
        i++;
        cout << setw(5) << right << i << ":" << "  1# " << src << "-->" << dst << endl;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        i++;
        cout << setw(5)<<right<<i<<":" << setw(3) << right << n << "# " << src << "-->" << dst << endl;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n;
    char src, tmp = 0, dst;
    while (1) {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(100000, '\n');
        if (n >= 1 && n <= 16) {
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
    cout << "移动步骤为:" << endl;
    hanoi(n, src, tmp, dst);
    return 0;
}
