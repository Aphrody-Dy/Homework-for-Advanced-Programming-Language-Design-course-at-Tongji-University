// 
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环（while、do-while、for、if-goto）
   ---------------------------------------------------------------------
*/

/***************************************************************************
  函数名称：
  功    能：递归方式求1^2+...+n^2
  输入参数：
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
			2、不允许出现任何形式的循环（while、do-while、for、if-goto）
			3、不允许使用cmath中的函数
 ***************************************************************************/
int sum_of_square(int n)
{
	if (n == 1) {
		return n * n;
	}
	else {
		return (n * n + sum_of_square(n - 1));
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数除添加一句cout外，其余不准动
 ***************************************************************************/
int main()
{
	int n;
	cout << "求1^2+2^2+...+n^2，请输入n值[3..1860]" << endl;
	cin >> n; //[3..1860]间的正整数，不考虑输入错误

	/* 此处允许添加一句cout语句 */
	cout << "1^2+2^2+...+"<<n<<"^2="<<sum_of_square(n) << endl;

	return 0;
}


