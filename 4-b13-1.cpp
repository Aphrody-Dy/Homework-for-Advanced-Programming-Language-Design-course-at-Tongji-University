// 
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
               3��������һ����̬�ֲ�����
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    char src, tmp = 0, dst;
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
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
        cout << "��������ʼ��(A-C)" << endl;
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
        cout << "������Ŀ����(A-C)" << endl;
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
                cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
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
    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);
    return 0;
}
