// 
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */
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
	int calc_days() {  //�����ǵ���ĵڼ���
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

		/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */
	}
};

/* --- �˴��������Ա����������ʵ�� --- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2024, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}
