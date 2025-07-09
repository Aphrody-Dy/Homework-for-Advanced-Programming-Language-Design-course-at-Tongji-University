// 
#pragma once
#include <cmath>
/* ���������Ҫ��ͷ�ļ�������ռ� */

/* point��Ķ��弰ʵ�֣��Ѹ����������ݣ���Ҫ�󲹳���� */
class point {
private:
	int x;
	int y;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	int getx() const //�����������const����ʾ�������ڱ��������޸����ݳ�Ա��ֵ 
	{
		return x;
	}
	int gety() const //�����������const����ʾ�������ڱ��������޸����ݳ�Ա��ֵ
	{
		return y;
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
	void set(int x_val, int y_val) {
		x = x_val;
		y = y_val;
	}
	double distance_to(const point& other) const {
		int dx = x - other.x;
		int dy = y - other.y;
		return sqrt(dx * dx + dy * dy);
	}
};

/* triangle��Ķ��弰ʵ�֣��Ѹ����������ݣ���Ҫ�󲹳���� */
class triangle {
private:
	point p1;
	point p2;
	point p3;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	double area()
	{
		int x1 = p1.getx(), y1 = p1.gety();
		int x2 = p2.getx(), y2 = p2.gety();
		int x3 = p3.getx(), y3 = p3.gety();

		int cross = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
		double area = 0.5 * abs(cross);

		if (area == 0.0) {
			return -1;
		}
		else {
			return area;
		}
	}
	/* ���캯������ʵ�֣���׼���� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */

};
