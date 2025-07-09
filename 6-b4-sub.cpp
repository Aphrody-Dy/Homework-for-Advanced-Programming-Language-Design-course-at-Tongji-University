// 

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�tj_strlen
  ��    �ܣ����ַ���str�ĳ���
  ���������const char* str
  �� �� ֵ���ַ�������
  ˵    ����
***************************************************************************/
int tj_strlen(const char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return 0;
    }
    int L=0;
    for (;*str != '\0';str++) {
        L++;
    }
    return L;
}

/***************************************************************************
  �������ƣ�tj_strcat
  ��    �ܣ����ַ���s2׷�ӵ��ַ���s1���棬��\0
  ���������char* s1, const char* s2
  �� �� ֵ���µ�s1
  ˵    ����
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL || s2 == NULL) {
        if (s1 == NULL) {
            return NULL;
        }
        if (s2 == NULL) {
            return s1;
        }
    }
    char* c = s1;
    s1 += tj_strlen(s1);
    for (;*s2 != '\0';s1++, s2++) {
        *s1 = *s2;
    }
    *s1 = '\0';
    return c;
}

/***************************************************************************
  �������ƣ�tj_strncat
  ��    �ܣ���s2��ǰlen���ַ�׷�ӵ�s1���沢���\0
  ���������char* s1,const char* s2,const int len
  �� �� ֵ���µ�s1
  ˵    ����
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL || s2 == NULL) {
        if (s1 == NULL) {
            return NULL;
        }
        if (s2 == NULL) {
            return s1;
        }
    }
    char* c = s1;
    s1 += tj_strlen(s1);
    for (int i = 0;i < len;i++, s1++, s2++) {
        *s1 = *s2;
        if (*s2 == '\0') {
            break;
        }
    }
    *s1 = '\0';
    return c;
}

/***************************************************************************
  �������ƣ�tj_strcpy
  ��    �ܣ����ַ���s2���Ƶ�s1�У�����ԭ���ݣ�����ʱ����\0
  ���������char* s1,const char*s2
  �� �� ֵ���µ�s1
  ˵    ����
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL || s2 == NULL) {
        if (s1 == NULL) {
            return NULL;
        }
        if (s2 == NULL) {
            *s1 = '\0';
            return s1;
        }
    }
    char* c = s1;
    *s1 = '\0';
    s1 = c;
    for (;*s2 != '\0';s1++, s2++) {
        *s1 = *s2;
    }
    *s1 = '\0';
    return c;
}

/***************************************************************************
  �������ƣ�tj_strncpy
  ��    �ܣ���s2��ǰlen���ַ����Ƶ�s1�У�����ʱ����\0
  ���������char* s1,const char* s2,const int len
  �� �� ֵ���µ�s1
  ˵    ����
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    if (s1 == NULL || s2 == NULL) {
        if (s1 == NULL) {
            return NULL;
        }
        if (s2 == NULL) {
            return s1;
        }
    }
    char* c = s1;
    if (*s2 != '\0') {
        for (int i = 0;i < len;i++, s1++, s2++) {
            if (*s2 == '\0') {
                break;
            }
            *s1 = *s2;
        }
    }
    return c;
}

/***************************************************************************
  �������ƣ�tj_strcmp
  ��    �ܣ��Ƚ��ַ���s1��s2�Ĵ�С��Ӣ����ĸҪ���ִ�Сд
  ���������const char* s1,const char* s2
  �� �� ֵ�����Ϊ0���������Ϊ��һ��������ַ���ASCII��Ĳ�ֵ
  ˵    ����
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    if (s1 == NULL) {
        return -1;
    }
    if (s2 == NULL) {
        return 1;
    }
    for (;*s1 != '\0' || *s2 != '\0';s1++, s2++) {
        if (*s1 == *s2) {
            continue;
        }
        else {
            return *s1 - *s2;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strcasecmp
  ��    �ܣ��Ƚ��ַ���s1��s2�Ĵ�С��Ӣ����ĸ�����ִ�Сд��ͳһת��ΪСд��
  ���������const char* s1,const char* s2
  �� �� ֵ�����Ϊ0������ȷ��ص�һ��������ַ���ASCII���ֵ����ĸͳһСд��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    if (s1 == NULL) {
        return -1;
    }
    if (s2 == NULL) {
        return 1;
    }
    for (;*s1 != '\0' || *s2 != '\0';s1++, s2++) {

        if (*s1 == *s2) {
            continue;
        }
        else {
            if ((int(*s1) >= int('A') && int(*s1) <= int('Z')) || (int(*s2) >= int('A') && int(*s2) <= int('Z'))) {
                if ((int(*s1) >= int('A') && int(*s1) <= int('Z')) && (int(*s2) >= int('A') && int(*s2) <= int('Z'))) {
                    return *s1 - *s2;
                }
                if ((int(*s1) >= int('A') && int(*s1) <= int('Z'))) {
                    if (int(*s1) + 32 == int(*s2)) {
                        continue;
                    }
                    return *s1 + 32 - *s2;
                }
                if ((int(*s2) >= int('A') && int(*s2) <= int('Z'))) {
                    if (int(*s2) + 32 == int(*s1)) {
                        continue;
                    }
                    return *s1 - *s2 - 32;
                }
            }
            return *s1 - *s2;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strncmp
  ��    �ܣ��Ƚ�s1��s2ǰlen���ַ��Ĵ�С��Ӣ����ĸ�����ִ�Сд
  ���������const char* s1,const char* s2,const int len
  �� �� ֵ�����Ϊ0������ȷ��ص�һ��������ַ���ASCII���ֵ
  ˵    ����
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    if (s1 == NULL) {
        return -1;
    }
    if (s2 == NULL) {
        return 1;
    }
    for (int i=0;i<len&&(*s1!='\0'||*s2!='\0');s1++, s2++, i++) {
        if (*s1 == *s2) {
            if (*s2 == '\0') {
                break;
            }
            continue;
        }
        else {
            return *s1 - *s2;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strcasencmp
  ��    �ܣ��Ƚ�s1��s2ǰlen���ַ��Ĵ�С��Ӣ����ĸҪ���ִ�Сд��ת��ΪСд��
  ���������
  �� �� ֵ�����Ϊ0������ȷ��ص�һ��������ַ���ASCII���ֵ����ĸͳһСд��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    if (s1 == NULL) {
        return -1;
    }
    if (s2 == NULL) {
        return 1;
    }
    for (int i = 0;i<len&&(*s1 != '\0' || *s2 != '\0');s1++, s2++,i++) {

        if (*s1 == *s2) {
            if (*s2 == '\0') {
                break;
            }
            continue;
        }
        else {
            if ((int(*s1) >= int('A') && int(*s1) <= int('Z')) || (int(*s2) >= int('A') && int(*s2) <= int('Z'))) {
                if ((int(*s1) >= int('A') && int(*s1) <= int('Z')) && (int(*s2) >= int('A') && int(*s2) <= int('Z'))) {
                    return *s1 - *s2;
                }
                if ((int(*s1) >= int('A') && int(*s1) <= int('Z'))) {
                    if (int(*s1) + 32 == int(*s2)) {
                        if (*s2 == '\0') {
                            break;
                        }
                        continue;
                    }
                    return *s1 + 32 - *s2;
                }
                if ((int(*s2) >= int('A') && int(*s2) <= int('Z'))) {
                    if (int(*s2) + 32 == int(*s1)) {
                        if (*s2 == '\0') {
                            break;
                        }
                        continue;
                    }
                    return *s1 - *s2 - 32;
                }
            }
            return *s1 - *s2;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strupr
  ��    �ܣ���str������Сд��ĸת��Ϊ��д
  ���������char* str
  �� �� ֵ��ת����Ĵ�
  ˵    ����
***************************************************************************/
char* tj_strupr(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return NULL;
    }
    char* c = str;
    for (;*str != '\0';str++) {
        if (int(*str) >= int('a') && int(*str) <= int('z')) {
            *str = int(*str - 32);
        }
    }
    return c;
}

/***************************************************************************
  �������ƣ�tj_strlwr
  ��    �ܣ����ַ����еĴ�д��ĸת����Сд��ĸ
  ���������char* str
  �� �� ֵ��ת����Ĵ�
  ˵    ����
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return NULL;
    }
    char* c = str;
    for (;*str != '\0';str++) {
        if (int(*str) >= int('A') && int(*str) <= int('Z')) {
            *str = int(*str + 32);
        }
    }
    return c;
}

/***************************************************************************
  �������ƣ�tj_strchr
  ��    �ܣ���str�д�������ch��һ�γ��ֵ�λ��
  ���������const char* str, const char ch
  �� �� ֵ��1-n(λ�ô�1��ʼ),δ�ҵ��򷵻�0
  ˵    ����
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return 0;
    }
    for (int i=1;*str != '\0';str++,i++) {
        if (*str == ch) {
            return i;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strstr
  ��    �ܣ���str�д�������substr��һ�γ��ֵ�λ��
  ���������const char* str, const char* substr
  �� �� ֵ������1-n(λ�ô�1��ʼ)��δ�ҵ��򷵻�0
  ˵    ����
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    bool b = 1;
    if (str == NULL||substr==NULL) {
        return 0;
    }
    for (int i = 1;*str != '\0';str++, i++) {
        if (*str == *substr) {
            const char* c1 = str;
            const char* c2 = substr;
            for (int j = i;*substr != '\0';str++, substr++, j++) {
                if (*str == *substr) {
                    b = 1;
                    continue;
                }
                else {
                    b = 0;
                    str = c1;
                    substr = c2;
                    break;
                }
            }
            if (b) {
                return i;
            }
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strrchr
  ��    �ܣ����ҵ�����str��ch��һ�γ��ֵ�λ��
  ���������const char* str, const char ch
  �� �� ֵ��1-n��λ�ô�1��ʼ����δ�ҵ��򷵻�0
  ˵    ����
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return 0;
    }
    int L = tj_strlen(str);
    str += L - 1;
    for (int i = 1;i<=L;str--, i++) {
        if (*str == ch) {
            return L-i+1;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strrstr
  ��    �ܣ���str�д��ҵ�����substr��һ�γ��ֵ�λ��
  ���������const char* str, const char* substr
  �� �� ֵ��1-n��λ�ô�1��ʼ����δ�ҵ��򷵻�0
  ˵    ����
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    bool b = 1;
    if (str == NULL || substr == NULL) {
        return 0;
    }
    int L1 = tj_strlen(str);
    int L2 = tj_strlen(substr);
    str = str + L1 - 1;
    substr = substr + L2 - 1;
    for (int i = 1;i<=L1;str--, i++) {
        if (*str == *substr) {
            const char* c1 = str;
            const char* c2 = substr;
            int j = 0;
            for (j = i;*substr != '\0';str--, substr--, j++) {
                if (*str == *substr) {
                    b = 1;
                    continue;
                }
                else {
                    b = 0;
                    str = c1;
                    substr = c2;
                    break;
                }
            }
            if (b) {
                return L1-j+2;
            }
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�tj_strrev
  ��    �ܣ���str��ת
  ���������char* str
  �� �� ֵ����ת��Ĵ�
  ˵    ����
***************************************************************************/
char* tj_strrev(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* c0 = str;
    for (int i=0;i<tj_strlen(str);str++,i++) {
        char c1 = *(str + tj_strlen(str) - 1 - i);
        *(str + tj_strlen(str) - 1 - i) = *str;
        *str = c1;
    }
    return c0;
}
