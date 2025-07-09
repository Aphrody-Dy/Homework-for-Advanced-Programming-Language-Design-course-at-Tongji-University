// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int i = 0;
/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
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
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        i++;
        printf("%5d:  1# %c-->%c\n", i, src, dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        i++;
        printf("%5d:%3d# %c-->%c\n", i, n,src, dst);
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
        printf("请输入汉诺塔的层数(1-16)\n");
        scanf("%d", &n);
        scanf("%*[^\n]");
        scanf("%*c");
        if (n >= 1 && n <= 16) {
            break;
        }
        else {
            continue;
        }
    }
    while (1) {
        printf("请输入起始柱(A-C)\n");
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
        printf("请输入目标柱(A-C)\n");
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
                printf("目标柱(%c)不能与起始柱(%c)相同\n",dst,src);
                continue;
            }
            break;
        }
    }
    for (int i = 65;i < 68; i++) {
        if (i != (int)(src) && i != (int)(dst)) {
            tmp = (char)(i);
        }
    }
    printf("移动步骤为:\n");
    hanoi(n, src, tmp, dst);
    return 0;
}
