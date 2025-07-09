// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a[10],b[10],c[10],s = 0;
void move(int n, int src, int dst)
{
    switch ((int)(src - 64)) {
        case 1:
            for (int i = 0;i < 10;i++) {
                if (a[i] == n) {
                    a[i] = 0;
                    break;
                }
            }
            break;
        case 2:
            for (int i = 0;i < 10;i++) {
                if (b[i] == n) {
                    b[i] = 0;
                    break;
                }
            }
            break;
        case 3:
            for (int i = 0;i < 10;i++) {
                if (c[i] == n) {
                    c[i] = 0;
                    break;
                }
            }
            break;
    }
    switch ((int)(dst - 64)) {
        case 1:
            for (int i = 0;i < 10;i++) {
                if (a[i] == 0) {
                    a[i] = n;
                    break;
                }
            }
            break;
        case 2:
            for (int i = 0;i < 10;i++) {
                if (b[i] == 0) {
                    b[i] = n;
                    break;
                }
            }
            break;
        case 3:
            for (int i = 0;i < 10;i++) {
                if (c[i] == 0) {
                    c[i] = n;
                    break;
                }
            }
            break;
    }
}
void output()
{
    printf("A:");
    for (int i = 0;i < 10;i++) {
        if (i == 0) {
            if (a[i]) {
                printf("%2d ", a[i]);
            }
            else {
                printf("   ");
            }
        }
        else {
            if (a[i]) {
                printf("%d ", a[i]);
            }
            else {
                printf("  ");
            }
        }
    }
    printf("B:");
    for (int i = 0;i < 10;i++) {
        if (i == 0) {
            if (b[i]) {
                printf("%2d ", b[i]);
            }
            else {
                printf("   ");
            }
        }
        else {
            if (b[i]) {
                printf("%d ", b[i]);
            }
            else {
                printf("  ");
            }
        }
    }
    printf("C:");
    for (int i = 0;i < 10;i++) {
        if (i == 0) {
            if (c[i]) {
                printf("%2d ", c[i]);
            }
            else {
                printf("   ");
            }
        }
        else {
            if (c[i]) {
                printf("%d ", c[i]);
            }
            else {
                printf("  ");
            }
        }
    }
    printf("\n");
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        s++;
        printf("第%4d 步(%2d): %c-->%c ", s, n, src, dst);
        move(n, src, dst);
        output();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        s++;
        printf("第%4d 步(%2d): %c-->%c ", s, n, src, dst);
        move(n, src, dst);
        output();
        hanoi(n - 1, tmp, src, dst);
    }
}
int main()
{
    int n;
    for (int i = 0;i < 10;i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }
    char src, tmp = 0, dst;
    while (1) {
        printf("请输入汉诺塔的层数(1-10)\n");
        scanf("%d", &n);
        scanf("%*[^\n]");
        scanf("%*c");
        if (n >= 1 && n <= 10) {
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
        if (src != 65 && src != 66 && src != 67 && src != 97 && src != 98 && src != 99) {
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
        printf( "请输入目标柱(A-C)\n");
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
    switch ((int)(src - 64)) {
        case 1:
            for (int i = 0;i < n;i++) {
                a[i] = n - i;
            }
            break;
        case 2:
            for (int i = 0;i < n;i++) {
                b[i] = n - i;
            }
            break;
        case 3:
            for (int i = 0;i < n;i++) {
                c[i] = n - i;
            }
            break;
    }
    printf("%-21s","初始:");
    output();
    hanoi(n, src, tmp, dst);
    return 0;
}
