// 
#define _CRT_SECURE_NO_WARNINGS		//使用了VS认为unsafe的函数
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>	//Dev/CB的strlen需要

struct tj_time {
	int tj_year;	//表示年份
	int tj_month;	//表示月(1-12)
	int tj_day;		//表示日(1-28/29/30/31)
	int tj_hour;	//表示小时(0-23)
	int tj_minute;	//表示分(0-59)
	int tj_second;	//表示秒(0-59)
};

/* 可以在此定义其它需要的函数 */


/***************************************************************************
  函数名称：
  功    能：给出提示并等待回车键
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	printf("\n按回车键继续");
	while (_getch() != '\r')
		;
	printf("\n\n");
}

/***************************************************************************
  函数名称：
  功    能：调用系统的转换函数将整型秒值转换为与本题相似的结构体并输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t的本质是64位无符号整数
{
	struct tm* tt;	//struct tm 为系统定义的结构体

	tt = localtime(&input_time);	//localtime为系统函数

	/* tm_*** 为struct tm中的成员，和本题的struct tj_time具体的内容不完全符合，具体含义自己查找相关资料 */
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tt->tm_year + 1900, tt->tm_mon + 1, tt->tm_mday, tt->tm_hour, tt->tm_min, tt->tm_sec);

	return;
}

/***************************************************************************
  函数名称：
  功    能：自定义转换结果输出函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* 实现自定义结构的输出，输出形式与system_time_output相同 */
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tp->tj_year, tp->tj_month, tp->tj_day, tp->tj_hour, tp->tj_minute, tp->tj_second);
}
/***************************************************************************
  函数名称：run
  功    能：判断是否为闰年
  输入参数：int y 要判断的年份
  返 回 值：1（是闰年）/0（非闰年）
  说    明：
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
  函数名称：month
  功    能：①在确定年份的基础上确定月份②处理hour进位时判断月份是否需要进位
  输入参数：int *t 输入秒数扣除年份后剩余秒数的地址
			int y 计算出的年份
			int m 目前的月份
			int d 目前的天数
  返 回 值：①计算出的月份②处理后的月份
  说    明：
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
  函数名称：
  功    能：自定义转换函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
struct tj_time* tj_time_convert(int input_time)
{
	static struct tj_time result;	//定义静态局部变量，不准动

	/* 实现过程开始，在下面添加相应的定义及执行语句即可 */
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
	/* 实现过程结束 */

	return &result;	//注意，返回的是静态局部变量的地址，本语句不准动
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int read_time;
	struct tj_time* tp;

	for (;;) {
		int ret = scanf("%d", &read_time); //因为采用输入重定向，此处不加任何提示

		/* 输入错误或<0则退出循环 */
		if (ret != 1)
			break;

		printf("秒数             : %d\n", read_time);
		printf("系统转换的结果   : ");
		system_time_output(read_time);

		printf("自定义转换的结果 : ");
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//系统函数，取当前系统时间（从1970-01-01 00:00:00开始的秒数）

		printf("当前系统时间     : %d\n", t);
		printf("系统转换的结果   : ");
		system_time_output(t);

		printf("自定义转换的结果 : ");
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}
