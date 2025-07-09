//
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */

//number of equal signs
int noe(char end_ch) {
	int n, e;
	e = int(end_ch);
	n = (e - 65) * 2 + 1;
	return n;
}

//print equal signs
char pes(int n) {
	if (n == 1) {
		return '=';
	}
	else {
		cout << '=';
		return(pes(n - 1));
	}
}

//print characters in order
void pco(char end_ch) {
	if (end_ch == 'A') {
		cout<< 'A';
	}
	else {
		cout << end_ch;
		pco(char(end_ch - 1));
	}
}

//print characters in reversal order
void pcr(int n, char end_ch) {
	int e = int(end_ch) - 64;
	if (n - e == 1) {
		cout<< end_ch;
	}
	else {
		cout << char(end_ch + 1 - n + e);
		pcr(n - 1, end_ch);
	}
}



/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡ��ĸ��
  ���������
  �� �� ֵ��
  ˵    �����βΰ�������
			��ʾ����һ������order��ָ������/����
***************************************************************************/
void print_tower(char end_ch,int order)
{
	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */
	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */
	static char c = end_ch;
	int w0 = c - end_ch + 1;
	int w1 = end_ch - 64;    // (c-64)-(c-end_ch)
	switch (order) {
		case 0: 
			if (end_ch == 'A') {
				cout << setfill(' ') << setw(w0) << end_ch << endl;
			}
			else {
				cout << setfill(' ') << setw(w0);
				pco(end_ch);
				pcr(noe(end_ch), end_ch);
				cout << endl;
				print_tower(end_ch - 1, order);
			}
			break;
		case 1: 
			if (c == 'A') {
				cout << 'A' << endl;
				break;
			}
			if (end_ch - 'A' == 0) {
				pco(c);
				pcr(noe(c), c);
				cout << endl;
			}
			else {
				cout << setfill(' ') << setw(w1);
				pco(char(c - end_ch + 65));
				if (c - end_ch != 0) {
					pcr(noe(char(c - end_ch + 65)), char(c - end_ch + 65));
				}
				cout << endl;
				print_tower(end_ch - 1, order);
			}
			break;
	}
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << pes(noe(end_ch)) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << pes(noe(end_ch)) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch,1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	cout << pes(noe(end_ch)) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << pes(noe(end_ch)) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch,0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	cout << pes(noe(end_ch)) << endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << pes(noe(end_ch)) << endl;/* ����ĸ����������= */
	print_tower(end_ch,1);   //��ӡ A~�����ַ��������� 
	if (end_ch != 'A') {
		print_tower(end_ch - 1, 0);   //��ӡ A~�����ַ�-1�ĵ����� 
	}
	cout << endl;

	return 0;
}
