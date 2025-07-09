// 

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：tj_strlen
  功    能：求字符串str的长度
  输入参数：const char* str
  返 回 值：字符串长度
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strcat
  功    能：将字符串s2追加到字符串s1后面，含\0
  输入参数：char* s1, const char* s2
  返 回 值：新的s1
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strncat
  功    能：将s2的前len个字符追加到s1后面并添加\0
  输入参数：char* s1,const char* s2,const int len
  返 回 值：新的s1
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strcpy
  功    能：将字符串s2复制到s1中，覆盖原内容，复制时包含\0
  输入参数：char* s1,const char*s2
  返 回 值：新的s1
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strncpy
  功    能：将s2的前len个字符复制到s1中，复制时不含\0
  输入参数：char* s1,const char* s2,const int len
  返 回 值：新的s1
  说    明：
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
  函数名称：tj_strcmp
  功    能：比较字符串s1和s2的大小，英文字母要区分大小写
  输入参数：const char* s1,const char* s2
  返 回 值：相等为0，不相等则为第一个不相等字符的ASCII码的差值
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strcasecmp
  功    能：比较字符串s1和s2的大小，英文字母不区分大小写（统一转换为小写）
  输入参数：const char* s1,const char* s2
  返 回 值：相等为0，不相等返回第一个不相等字符的ASCII码差值（字母统一小写）
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strncmp
  功    能：比较s1和s2前len个字符的大小，英文字母不区分大小写
  输入参数：const char* s1,const char* s2,const int len
  返 回 值：相等为0，不相等返回第一个不相等字符的ASCII码差值
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strcasencmp
  功    能：比较s1和s2前len个字符的大小，英文字母要区分大小写（转换为小写）
  输入参数：
  返 回 值：相等为0，不相等返回第一个不相等字符的ASCII码差值（字母统一小写）
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strupr
  功    能：将str中所有小写字母转换为大写
  输入参数：char* str
  返 回 值：转换后的串
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strlwr
  功    能：将字符串中的大写字母转换成小写字母
  输入参数：char* str
  返 回 值：转换后的串
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strchr
  功    能：在str中从左到右找ch第一次出现的位置
  输入参数：const char* str, const char ch
  返 回 值：1-n(位置从1开始),未找到则返回0
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strstr
  功    能：在str中从左到右找substr第一次出现的位置
  输入参数：const char* str, const char* substr
  返 回 值：返回1-n(位置从1开始)，未找到则返回0
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strrchr
  功    能：从右到左找str中ch第一次出现的位置
  输入参数：const char* str, const char ch
  返 回 值：1-n（位置从1开始），未找到则返回0
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strrstr
  功    能：在str中从右到左找substr第一次出现的位置
  输入参数：const char* str, const char* substr
  返 回 值：1-n（位置从1开始），未找到则返回0
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strrev
  功    能：将str反转
  输入参数：char* str
  返 回 值：反转后的串
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* c0 = str;
    for (int i=0;i<tj_strlen(str);str++,i++) {
        char c1 = *(str + tj_strlen(str) - 1 - i);
        *(str + tj_strlen(str) - 1 - i) = *str;
        *str = c1;
    }
    return c0;
}
