// 
#include <iostream>
#include <string>
#include <cmath>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;
const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */
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
    int a[12]={0},b=0;

    while (1) {
        cout << "������[0-100��)֮�������:" << endl;
        cin >> d;
        if (cin.good() == 1 && d >= 0 && d < 1e11) {
            break;
        }
        else {
            continue;
        }
    }

    a[0] = int(d / 1e9);
    a[1] = int((d - a[0] * 1e9) / 1e8);
    a[2] = int((d - a[0] * 1e9 - a[1] * 1e8) / 1e7);
    a[3] = int((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7) / 1e6);
    a[4] = int((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6) / 1e5);
    a[5] = int((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5) / 1e4);
    a[6] = int((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5 - a[5] * 1e4) / 1e3);
    a[7] = int((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5 - a[5] * 1e4 - a[6] * 1e3) / 1e2);
    a[8] = int((d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5 - a[5] * 1e4 - a[6] * 1e3 - a[7] * 1e2) / 1e1);
    a[9] = int(d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5 - a[5] * 1e4 - a[6] * 1e3 - a[7] * 1e2 - a[8] * 1e1);

    double f = d - a[0] * 1e9 - a[1] * 1e8 - a[2] * 1e7 - a[3] * 1e6 - a[4] * 1e5 - a[5] * 1e4 - a[6] * 1e3 - a[7] * 1e2 - a[8] * 1e1 - a[9];
    a[10] = int((f + 3.81e-6) * 10);
    a[11] = int(((f + 3.81e-6) * 10 - a[10]) * 10);
 

    if (a[0]) {
        result.append({ chnstr[a[0] * 2],chnstr[a[0] * 2 + 1] });
        result.append("ʰ");
    }
    if (a[1]) {
        result.append({ chnstr[a[1] * 2],chnstr[a[1] * 2 + 1] });
    }
    if (a[0] || a[1]) {
        result.append("��");
    }
    result.append({ chnstr[a[2] * 2],chnstr[a[2] * 2 + 1] });
    if (a[2]) {
        result.append("Ǫ");
    }
    result.append({ chnstr[a[3] * 2],chnstr[a[3] * 2 + 1] });
    if (a[3]) {
        result.append("��");
    }
    result.append({ chnstr[a[4] * 2],chnstr[a[4] * 2 + 1] });
    if (a[4]) {
        result.append("ʰ");
    }
    if (a[5]) {
        result.append({ chnstr[a[5] * 2],chnstr[a[5] * 2 + 1] });
    }
    if (a[2] || a[3] || a[4] || a[5]) {
        result.append("��");
    }
    if ((!a[2] && !a[3]) || (!a[3] && !a[4])) {
        int j = result.find({ chnstr[a[3] * 2],chnstr[a[3] * 2 + 1] });
        if (j != string::npos) {
            result.erase(j, 2);
        }
        if (!a[0] && !a[1] && !a[2] && !a[3]) {
            j = result.find({ chnstr[a[2] * 2],chnstr[a[2] * 2 + 1] });
            if (j != string::npos) {
                result.erase(j, 2);
            }
        }
        if (!a[2] && !a[3] && !a[4]) {
            j = result.find({ chnstr[a[4] * 2],chnstr[a[4] * 2 + 1] });
            if (j != string::npos) {
                result.erase(j, 2);
            }
            if (!a[0] && !a[1]) {
                j = result.find({ chnstr[a[2] * 2],chnstr[a[2] * 2 + 1] });
                if (j != string::npos) {
                    result.erase(j, 2);
                }
            }
        }
    }
    if (!a[4] && !a[5]) {
        int j = result.rfind({ chnstr[a[4] * 2],chnstr[a[4] * 2 + 1] });
        if (j != string::npos) {
            result.erase(j, 2);
        }
    }
    result.append({ chnstr[a[6] * 2],chnstr[a[6] * 2 + 1] });
    if (a[6]) {
        result.append("Ǫ");
    }
    result.append({ chnstr[a[7] * 2],chnstr[a[7] * 2 + 1] });
    if (a[7]) {
        result.append("��");
    }
    result.append({ chnstr[a[8] * 2],chnstr[a[8] * 2 + 1] });
    if (a[8]) {
        result.append("ʰ");
    }
    if (a[9]) {
        result.append({ chnstr[a[9] * 2],chnstr[a[9] * 2 + 1] });
    }
    if (a[0]||a[1]||a[2] || a[3] || a[4] || a[5]|| a[6] || a[7] || a[8] || a[9]) {
        result.append("Բ");
    }
    if ((!a[6] && !a[7]) || (!a[7] && !a[8])) {
        int j = result.rfind({ chnstr[a[7] * 2],chnstr[a[7] * 2 + 1] });
        if (j != string::npos) {
            result.erase(j, 2);
        }
        if (!a[0] && !a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6] && !a[7]) {
            j = result.rfind({ chnstr[a[6] * 2],chnstr[a[6] * 2 + 1] });
            if (j != string::npos) {
                result.erase(j, 2);
            }
        }
        if (!a[6] && !a[7] && !a[8]) {
            j = result.rfind({ chnstr[a[8] * 2],chnstr[a[8] * 2 + 1] });
            if (j != string::npos) {
                result.erase(j, 2);
            }
            if (!a[0] && !a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5]) {
                j = result.find({ chnstr[a[6] * 2],chnstr[a[6] * 2 + 1] });
                if (j != string::npos) {
                    result.erase(j, 2);
                }
            }
        }
    }
    if (d == 0) {
        result.append({ chnstr[a[9] * 2],chnstr[a[9] * 2 + 1] });
        result.append("Բ");
    }
    if (!a[10] && !a[11]) {
        result.append("��");
    }
    else {
        result.append({ chnstr[a[10] * 2],chnstr[a[10] * 2 + 1] });
        if (a[10] && !a[11]) {
            result.append("����");
        }
        else {
            if (a[10]) {
                result.append("��");
            }
            result.append({ chnstr[a[11] * 2],chnstr[a[11] * 2 + 1] });
            result.append("��");
        }
    }
    for (unsigned int i = 0;i < result.length() - 3;i++) {
        if ((result[i] + result[i + 1]) == (result[i + 2] + result[i + 3])) {
            result.erase(i, 2);
        }
    }
    if (d != 0) {
        if ((result[0] + result[1]) == (chnstr[0] + chnstr[1])) {
            result.erase(0, 2);
        }
        for (unsigned int i = 0;i < result.length() - 1;i++) {
            if (result.find("��Բ")) {
                if (result.find("��Բ") != string::npos) {
                    result.erase(result.find("��Բ"), 2);
                }
            }
        }
    }
    cout << "��д�����:" << endl;
    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
