// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
//�ɰ���������Ҫ��ͷ�ļ�
const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    double d;
    int a[12] = { 0 };
    char sub[3] = { 0,0};//������Ҫ��β0��

    while (1) {
        printf("������[0-100��)֮�������:\n");
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
        strcat(result,"ʰ");
    }
    if (a[1]) {
        sub[0] = chnstr[a[1] * 2];
        sub[1] = chnstr[a[1] * 2 + 1];
        strcat(result, sub);
    }
    if (a[0] || a[1]) {
        strcat(result,"��");
    }
    if (a[2]) {
        sub[0] = chnstr[a[2] * 2];
        sub[1] = chnstr[a[2] * 2 + 1];
        strcat(result, sub);
        strcat(result, "Ǫ");
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
        strcat(result,"��");
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
        strcat(result,"ʰ");
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
        strcat(result,"��");
    }
    if (a[6]) {
        sub[0] = chnstr[a[6] * 2];
        sub[1] = chnstr[a[6] * 2 + 1];
        strcat(result, sub);
        strcat(result,"Ǫ");
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
        strcat(result,"��");
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
        strcat(result,"ʰ");
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
        strcat(result,"Բ");
    }
    if (d == 0) {
        sub[0] = chnstr[a[9] * 2];
        sub[1] = chnstr[a[9] * 2 + 1];
        strcat(result, sub);
        strcat(result,"Բ");
    }
    if (!a[10] && !a[11]) {
        strcat(result,"��");
    }
    else {
        if (!a[0] && !a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6] && !a[7] && !a[8] && !a[9] && !a[10]);
        else {
            sub[0] = chnstr[a[10] * 2];
            sub[1] = chnstr[a[10] * 2 + 1];
            strcat(result, sub);
        }
        if (a[10] && !a[11]) {
            strcat(result, "����");
        }
        else {
            if (a[10]) {
                strcat(result, "��");
            }
            sub[0] = chnstr[a[11] * 2];
            sub[1] = chnstr[a[11] * 2 + 1];
            strcat(result, sub);
            strcat(result, "��");
        }
    }
    printf("��д�����:\n");
    printf("%s\n", result); /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
