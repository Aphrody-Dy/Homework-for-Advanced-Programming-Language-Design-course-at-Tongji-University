// 
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS��Ϊunsafe�ĺ���
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>	//Dev/CB��strlen��Ҫ

struct tj_time {
	int tj_year;	//��ʾ���
	int tj_month;	//��ʾ��(1-12)
	int tj_day;		//��ʾ��(1-28/29/30/31)
	int tj_hour;	//��ʾСʱ(0-23)
	int tj_minute;	//��ʾ��(0-59)
	int tj_second;	//��ʾ��(0-59)
};

/* �����ڴ˶���������Ҫ�ĺ��� */


/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʾ���ȴ��س���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	printf("\n���س�������");
	while (_getch() != '\r')
		;
	printf("\n\n");
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ϵͳ��ת��������������ֵת��Ϊ�뱾�����ƵĽṹ�岢���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t�ı�����64λ�޷�������
{
	struct tm* tt;	//struct tm Ϊϵͳ����Ľṹ��

	tt = localtime(&input_time);	//localtimeΪϵͳ����

	/* tm_*** Ϊstruct tm�еĳ�Ա���ͱ����struct tj_time��������ݲ���ȫ���ϣ����庬���Լ������������ */
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tt->tm_year + 1900, tt->tm_mon + 1, tt->tm_mday, tt->tm_hour, tt->tm_min, tt->tm_sec);

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* ʵ���Զ���ṹ������������ʽ��system_time_output��ͬ */
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tp->tj_year, tp->tj_month, tp->tj_day, tp->tj_hour, tp->tj_minute, tp->tj_second);
}
/***************************************************************************
  �������ƣ�run
  ��    �ܣ��ж��Ƿ�Ϊ����
  ���������int y Ҫ�жϵ����
  �� �� ֵ��1�������꣩/0�������꣩
  ˵    ����
***************************************************************************/
int run(int y)
{
	if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
		return 0;
	}
	else {
		return 1;
	}
}
/***************************************************************************
  �������ƣ�month
  ��    �ܣ�����ȷ����ݵĻ�����ȷ���·ݢڴ���hour��λʱ�ж��·��Ƿ���Ҫ��λ
  ���������int *t ���������۳���ݺ�ʣ�������ĵ�ַ
			int y ����������
			int m Ŀǰ���·�
			int d Ŀǰ������
  �� �� ֵ���ټ�������·ݢڴ������·�
  ˵    ����
***************************************************************************/
int month(int *t, int y,int m,int *d)
{
	const int msec31 = 60 * 60 * 24 * 31;
	const int msec30 = 60 * 60 * 24 * 30;
	const int msec29 = 60 * 60 * 24 * 29;
	const int msec28 = 60 * 60 * 24 * 28;
	int msec[12] = { msec31,(run(y) ? msec29 : msec28) ,msec31,msec30,msec31,msec30,msec31,msec31,msec30,msec31,msec30,msec31 };
	if (m && *d) {
		if (*d > (msec[m - 1] / (60 * 60 * 24))) {
			*d -= (msec[m - 1] / (60 * 60 * 24));
			return m + 1;
		}
		return m;
	}
	for (int i = 0;i < 12;i++) {
		if (*t <= msec[i]) {
			return i + 1;
		}
		else {
			*t -= msec[i];
		}
	}
	
	return 0;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
struct tj_time* tj_time_convert(int input_time)
{
	static struct tj_time result;	//���徲̬�ֲ���������׼��

	/* ʵ�ֹ��̿�ʼ�������������Ӧ�Ķ��弰ִ����伴�� */
	const int  ysec = 60 * 60 * 24 * 365;
	const int rysec = 60 * 60 * 24 * 366;
	const int dsec = 60 * 60 * 24;
	const int hsec = 60 * 60;
	int i = 0;
	int b = 1;
	if (!input_time) {
		b = 0;
	}
	for (;input_time>=(run(1970+i)?rysec:ysec);i++) {
		if (run(1970 + i)) {
			input_time -= rysec;
		}
		else {
			input_time -= ysec;
		}
	}
	result.tj_year = 1970+i;
	result.tj_month=month(&input_time, 1970+i,0,0);
	if (b) {
		if (input_time == dsec) {
			result.tj_day = 2;
		}
		else {
			result.tj_day = (input_time / dsec) + (input_time % dsec ? 1 : 0);
		}
	}
	else {
		result.tj_day = 1;
	}
	input_time %= dsec;
	result.tj_hour = (input_time / hsec)+8;
	if (result.tj_hour >= 24) {
		result.tj_hour -= 24;
		result.tj_day += 1;
		result.tj_month = month(&input_time, i, result.tj_month, &result.tj_day);
		if (result.tj_month > 12) {
			result.tj_month -= 12;
			result.tj_year += 1;
		}
	}
	input_time %= hsec;
	result.tj_minute = input_time / 60;
	input_time %= 60;
	result.tj_second = input_time;
	/* ʵ�ֹ��̽��� */

	return &result;	//ע�⣬���ص��Ǿ�̬�ֲ������ĵ�ַ������䲻׼��
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int read_time;
	struct tj_time* tp;

	for (;;) {
		int ret = scanf("%d", &read_time); //��Ϊ���������ض��򣬴˴������κ���ʾ

		/* ��������<0���˳�ѭ�� */
		if (ret != 1)
			break;

		printf("����             : %d\n", read_time);
		printf("ϵͳת���Ľ��   : ");
		system_time_output(read_time);

		printf("�Զ���ת���Ľ�� : ");
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//ϵͳ������ȡ��ǰϵͳʱ�䣨��1970-01-01 00:00:00��ʼ��������

		printf("��ǰϵͳʱ��     : %d\n", t);
		printf("ϵͳת���Ľ��   : ");
		system_time_output(t);

		printf("�Զ���ת���Ľ�� : ");
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}
