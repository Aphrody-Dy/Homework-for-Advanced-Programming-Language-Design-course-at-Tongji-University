// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
//可按需增加需要的头文件
const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    double d;
    int a[12] = { 0 };
    char sub[3] = { 0,0};//这里需要加尾0吗？

    while (1) {
        printf("请输入[0-100亿)之间的数字:\n");
        scanf("%lf", &d);
        if (scanf && d >= 0 && d < 1e11) {
            break;
        }
        else {
            continue;
        }
    }

    a[0] = (int)(d / 1e9);
    a[1] = (int)((d - a[0] * 1e9) / 1e8);
    a[2] = (int)((d - a[0] * 1e9 - a[1] * 1e8) / 1e7);
    a[3] = (int)((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7) / 1e6);
    a[4] = (int)((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6) / 1e5);
    a[5] = (int)((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5) / 1e4);
    a[6] = (int)((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5 - a[5] * 1e4) / 1e3);
    a[7] = (int)((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5 - a[5] * 1e4 - a[6] * 1e3) / 1e2);
    a[8] = (int)((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5 - a[5] * 1e4 - a[6] * 1e3 - a[7] * 1e2) / 1e1);
    a[9] = (int)(d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5 - a[5] * 1e4 - a[6] * 1e3 - a[7] * 1e2 - a[8] * 1e1);

    double f = d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5 - a[5] * 1e4 - a[6] * 1e3 - a[7] * 1e2 - a[8] * 1e1 - a[9];
    a[10] = (int)((f + 3.81e-6) * 10);
    a[11] = (int)(((f + 3.81e-6) * 10 - a[10]) * 10);

    if (a[0]) {
        sub[0] = chnstr[a[0] * 2];
        sub[1] = chnstr[a[0] * 2 + 1];
        strcat(result,sub);
        strcat(result,"拾");
    }
    if (a[1]) {
        sub[0] = chnstr[a[1] * 2];
        sub[1] = chnstr[a[1] * 2 + 1];
        strcat(result, sub);
    }
    if (a[0] || a[1]) {
        strcat(result,"亿");
    }
    if (a[2]) {
        sub[0] = chnstr[a[2] * 2];
        sub[1] = chnstr[a[2] * 2 + 1];
        strcat(result, sub);
        strcat(result, "仟");
    }
    else {
        if ((!a[0] && !a[1]) || !a[3]);
        else {
            sub[0] = chnstr[a[2] * 2];
            sub[1] = chnstr[a[2] * 2 + 1];
            strcat(result, sub);
        }
    }
    if (a[3]) {
        sub[0] = chnstr[a[3] * 2];
        sub[1] = chnstr[a[3] * 2 + 1];
        strcat(result, sub);
        strcat(result,"佰");
    }
    else {
        if ((!a[0] && !a[1]&&!a[2]) || !a[4]);
        else {
            sub[0] = chnstr[a[3] * 2];
            sub[1] = chnstr[a[3] * 2 + 1];
            strcat(result, sub);
        }
    }
    if (a[4]) {
        sub[0] = chnstr[a[4] * 2];
        sub[1] = chnstr[a[4] * 2 + 1];
        strcat(result, sub);
        strcat(result,"拾");
    }
    else {
        if (!a[0] && !a[1] && !a[2]&&!a[3]);
        else {
            if (a[5]) {
                sub[0] = chnstr[a[4] * 2];
                sub[1] = chnstr[a[4] * 2 + 1];
                strcat(result, sub);
            }
        }
    }
    if (a[5]) {
        sub[0] = chnstr[a[5] * 2];
        sub[1] = chnstr[a[5] * 2 + 1];
        strcat(result, sub);
    }
    if (a[2] || a[3] || a[4] || a[5]) {
        strcat(result,"万");
    }
    if (a[6]) {
        sub[0] = chnstr[a[6] * 2];
        sub[1] = chnstr[a[6] * 2 + 1];
        strcat(result, sub);
        strcat(result,"仟");
    }
    else {
        if ((!a[0] && !a[1] && !a[2] && !a[3] && !a[4] && !a[5]) || !a[7]);
        else {
            sub[0] = chnstr[a[6] * 2];
            sub[1] = chnstr[a[6] * 2 + 1];
            strcat(result, sub);
        }
    }
    if (a[7]) {
        sub[0] = chnstr[a[7] * 2];
        sub[1] = chnstr[a[7] * 2 + 1];
        strcat(result, sub);
        strcat(result,"佰");
    }
    else {
        if ((!a[0] && !a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6]) || !a[8]);
        else {
            sub[0] = chnstr[a[7] * 2];
            sub[1] = chnstr[a[7] * 2 + 1];
            strcat(result, sub);
        }
    }
    if (a[8]) {
        sub[0] = chnstr[a[8] * 2];
        sub[1] = chnstr[a[8] * 2 + 1];
        strcat(result, sub);
        strcat(result,"拾");
    }
    else {
        if (!a[0] && !a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6] && !a[7]);
        else {
            if (a[9]) {
                sub[0] = chnstr[a[8] * 2];
                sub[1] = chnstr[a[8] * 2 + 1];
                strcat(result, sub);
            }
        }
    }
    if (a[9]) {
        sub[0] = chnstr[a[9] * 2];
        sub[1] = chnstr[a[9] * 2 + 1];
        strcat(result, sub);
    }
    if (a[0] || a[1] || a[2] || a[3] || a[4] || a[5] || a[6] || a[7] || a[8] || a[9]) {
        strcat(result,"圆");
    }
    if (d == 0) {
        sub[0] = chnstr[a[9] * 2];
        sub[1] = chnstr[a[9] * 2 + 1];
        strcat(result, sub);
        strcat(result,"圆");
    }
    if (!a[10] && !a[11]) {
        strcat(result,"整");
    }
    else {
        if (!a[0] && !a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6] && !a[7] && !a[8] && !a[9] && !a[10]);
        else {
            sub[0] = chnstr[a[10] * 2];
            sub[1] = chnstr[a[10] * 2 + 1];
            strcat(result, sub);
        }
        if (a[10] && !a[11]) {
            strcat(result, "角整");
        }
        else {
            if (a[10]) {
                strcat(result, "角");
            }
            sub[0] = chnstr[a[11] * 2];
            sub[1] = chnstr[a[11] * 2 + 1];
            strcat(result, sub);
            strcat(result, "分");
        }
    }
    printf("大写结果是:\n");
    printf("%s\n", result); /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
