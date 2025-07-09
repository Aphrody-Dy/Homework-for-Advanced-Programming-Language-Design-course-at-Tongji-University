// 
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu() {
	while (1) {
		cout << "1.��I��J��K��L��������������(��Сд���ɣ������ͷ��겻�������ƣ��߽�ֹͣ)" << endl;
		cout << "2.��I��J��K��L��������������(��Сд���ɣ������ͷ��겻�������ƣ��߽����)" << endl;
		cout << "3.�ü�ͷ�������������ң�����дHPKM�������ƶ���꣬�߽�ֹͣ��" << endl;
		cout << "4.�ü�ͷ�������������ң�����дHPKM�������ƶ���꣬�߽���ƣ�" << endl;
		cout << "0.�˳�" << endl;
		cout << "��ѡ��[0-4]";
		int m = _getche() - 48;
		if (m >= 0 && m <= 4) {
			return m;
		}
		else {
			const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
			cls(hout);
			continue;
		}
	}
}

void move_by(const int m) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int c0, X = 35, Y = 9;
	while (1) {
		char n = 0, s = 0, w = 0, e = 0;
		c0 = _getch();
		if(m==1||m==2){
			switch (c0) {
				case 73:
				case 105:
					n = 1;
					break;
				case 74:
				case 106:
					w = 1;
					break;
				case 75:
				case 107:
					s = 1;
					break;
				case 76:
				case 108:
					e = 1;
					break;
			}
		}
		if (m == 3 || m == 4) {
			if (c0 == 224) {
				c0 = _getch();
				switch (c0) {
					case 72:
						n = 1;
						break;
					case 75:
						w = 1;
						break;
					case 80:
						s = 1;
						break;
					case 77:
						e = 1;
						break;
				}
			}
			else {
				n = s = w = e = 0;
			}
			
		}
		COORD coord;
		coord.X = X;
		coord.Y = Y;
		if (n) {
			if (Y == 1) {
				switch (m) {
					case 1:
					case 3:
						break;
					case 2:
					case 4:
						Y += 16;
						gotoxy(hout, X, Y);
						break;
				}
			}
			else {
				Y--;
				gotoxy(hout, X, Y);
			}
			continue;
		}
		if (s) {
			if (Y == 17) {
				switch (m) {
					case 1:
					case 3:
						break;
					case 2:
					case 4:
						Y -= 16;
						gotoxy(hout, X, Y);
						break;
				}
			}
			else {
				Y++;
				gotoxy(hout, X, Y);
			}
			continue;
		}
		if (w) {
			if (X == 1) {
				switch (m) {
					case 1:
					case 3:
						break;
					case 2:
					case 4:
						X += 68;
						gotoxy(hout, X, Y);
				}
			}
			else {
				X--;
				gotoxy(hout, X, Y);
			}
			continue;
		}
		if (e) {
			if (X == 69) {
				switch (m) {
					case 1:
					case 3:
						break;
					case 2:
					case 4:
						X -= 68;
						gotoxy(hout, X, Y);
				}
			}
			else {
				gotoxy(hout, X + 1, Y);
				X++;
			}
			continue;
		}
		if (c0 == 32) {
			showch(hout, X, Y, ' ');
			gotoxy(hout, X, Y);
		}
		if (c0 == 224) {
			c0 = _getch();
			while (c0 != ' ') {
				c0 = ' ';
				continue;
			}
			continue;
		}
		if (c0 == 113||c0==81) {
			break;
		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{	
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	srand((unsigned int)(time(0)));		//����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ���

	while (1) {
		cls(hout);		//�˾�������ǵ���ϵͳ��cls��������
		int m = menu();
		if (m == 0) {
			return 0;
		}
		cls(hout);
		init_border(hout);		//��ʾ��ʼ�ı߿����е�����ַ�
		gotoxy(hout, 35, 9);
		move_by(m);

		gotoxy(hout, 0, 23);
		cout << "��Ϸ���������س������ز˵�." ;
		//(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
		while (1) {
			int o = _getch();
			if (o == 13) {
				break;
			}
			else {
				continue;
			}
		}
		continue;
	}
}
