// 
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */
	bool is_leap_year() {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	int get_days_in_month(int m) {
		int days_in_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (m == 2 && is_leap_year()) {
			return 29;
		}
		if (m >= 1 && m <= 12) {
			return days_in_month[m - 1];
		}
		return 0;
	}
public:
	Days(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	int calc_days() {  //计算是当年的第几天
		if (month < 1 || month > 12) {
			return -1;
		}
		if (day < 1 || day > get_days_in_month(month)) {
			return -1;
		}
		int total = 0;
		for (int i = 1; i < month; ++i) {
			total += get_days_in_month(i);
		}
		total += day;
		return total;

		/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */
	}
};

/* --- 此处给出类成员函数的体外实现 --- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2024, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
