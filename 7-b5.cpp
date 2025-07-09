// 
#define _CRT_SECURE_NO_WARNINGS
/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//定义文件名的最大长度
class stu_list;
/* stu_metge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
	int  stu_no;					//学号
	char stu_name[MAX_NAME_LEN];  //姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	bool in_round_1;
	bool in_round_2;
public:
	//本类不允许定义任何的公有数据成员及成员函数
	friend class stu_list;
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//第一轮选课的学生名单（不排序、不去重）
	int list_num_1;						//第一轮选课的学生人数

	student list_round_2[MAX_STU_NUM];	//第二轮选课的学生名单（不排序、不去重）
	int list_num_2;						//第二轮选课的学生人数

	stu_merge list_merge[MAX_STU_NUM];	//合并后的学生名单（去重，按升序排列）
	int list_merge_num;					//合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

	/* 允许按需加入private数据成员和成员函数
	   注意，不允许加入array / set / map / vector等STL容器 */
	void swap_stu(stu_merge& a, stu_merge& b) {
		stu_merge t = a;
		a = b;
		b = t;
	}
	void sort_list() {
		for (int i = 0; i < list_merge_num - 1; ++i) {
			for (int j = 0; j < list_merge_num - 1 - i; ++j) {
				if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
					swap_stu(list_merge[j], list_merge[j + 1]);
				}
			}
		}
	}
public:
	stu_list();										//构造函数，按需完成初始化功能，如果不需要，保留空函数即可
	int read(const char* filename, const int round);	//从文件中读入选课信息，round为1/2，表示选课轮次
	int print(const char* prompt = NULL);				//打印最终的选课名单

	/* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
	   不允许定义公有的数据成员
	   不允许在成员函数中使用array / set / map / vector等STL容器 */
	void process_lists();
};

/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */


/***************************************************************************
  函数名称：
  功    能：从文件中读入选课信息，round为1/2，表示选课轮次
  输入参数：
  返 回 值：
  说    明：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
***************************************************************************/
stu_list::stu_list()
{
	list_num_1 = 0;
	list_num_2 = 0;
	list_merge_num = 0;
	
	memset(list_round_1, 0, sizeof(list_round_1));
	memset(list_round_2, 0, sizeof(list_round_2));
	memset(list_merge, 0, sizeof(list_merge));
}

/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* 读取第1/2轮的选课名单并打印 */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}

/***************************************************************************
  函数名称：stu_list::process_lists
  功    能：将两轮选课名单合并、排序并去除重复项
  输入参数：无
  返 回 值：无
  说    明：
***************************************************************************/
void stu_list::process_lists()
{
	
	list_merge_num = 0;

	for (int i = 0; i < list_num_1; ++i) {
		list_merge[list_merge_num].stu_no = list_round_1[i].no;
		strcpy(list_merge[list_merge_num].stu_name, list_round_1[i].name);
		list_merge[list_merge_num].in_round_1 = true;
		list_merge[list_merge_num].in_round_2 = false;
		list_merge_num++;
	}
	
	for (int i = 0; i < list_num_2; ++i) {
		list_merge[list_merge_num].stu_no = list_round_2[i].no;
		strcpy(list_merge[list_merge_num].stu_name, list_round_2[i].name);
		list_merge[list_merge_num].in_round_1 = false;
		list_merge[list_merge_num].in_round_2 = true;
		list_merge_num++;
	}

	if (list_merge_num == 0) {
		return;
	}
	sort_list();
	int idx = 0;
	for (int i = 1; i < list_merge_num; ++i) {
		if (list_merge[i].stu_no == list_merge[idx].stu_no) {
			list_merge[idx].in_round_1 |= list_merge[i].in_round_1;
			list_merge[idx].in_round_2 |= list_merge[i].in_round_2;
		}
		else {
			idx++;
			if (i != idx) {
				list_merge[idx] = list_merge[i];
			}
		}
	}
	list_merge_num = idx + 1;
}

/***************************************************************************
  函数名称：stu_list::print
  功    能：打印最终的选课名单
  输入参数：prompt - 打印前的提示信息
  返 回 值：0
  说    明：
***************************************************************************/
int stu_list::print(const char* prompt)
{
	if (prompt) {
		cout << prompt << endl;
	}

	const int SEQ_WIDTH = 4;   
	const int NO_WIDTH = 7;   
	const int ROUND_WIDTH = 6;  

	int max_name_width = strlen("姓名");
	for (int i = 0; i < list_merge_num; ++i) {
		int current_len = strlen(list_merge[i].stu_name);
		if (current_len > max_name_width) {
			max_name_width = current_len;
		}
	}

	int total_width = 1 + SEQ_WIDTH + 2 + NO_WIDTH + 2 + max_name_width + 2 + ROUND_WIDTH + 2 + ROUND_WIDTH + 1;

	cout << setfill('=') << setw(total_width) << "" << setfill(' ') << endl;

	cout << " " << left
		<< setw(SEQ_WIDTH) << "序号" << "  "
		<< setw(NO_WIDTH) << "学号" << "  "
		<< setw(max_name_width) << "姓名" << "  "
		<< setw(ROUND_WIDTH) << "第一轮" << "  "
		<< setw(ROUND_WIDTH) << "第二轮" << " " << endl;

	cout << setfill('=') << setw(total_width) << "" << setfill(' ') << endl;

	for (int i = 0; i < list_merge_num; ++i) {
		const char* round1_output;
		const char* round2_output;

		bool r1_selected = list_merge[i].in_round_1;
		bool r2_selected = list_merge[i].in_round_2;

		if (r1_selected && r2_selected) {
			round1_output = "Y";
			round2_output = "Y";
		}
		else if (r1_selected && !r2_selected) {
			round1_output = "Y";
			round2_output = "退课";
		}
		else{
			round1_output = "/";
			round2_output = "补选";
		}

		cout << " " << left
			<< setw(SEQ_WIDTH) << i + 1 << "  "
			<< setw(NO_WIDTH) << list_merge[i].stu_no << "  "
			<< setw(max_name_width) << list_merge[i].stu_name << "  "
			<< setw(ROUND_WIDTH) << round1_output << "  "
			<< setw(ROUND_WIDTH) << round2_output << " " << endl;
	}

	cout << setfill('=') << setw(total_width) << "" << setfill(' ') << endl;

	return 0;
}

/***************************************************************************
  函数名称：main
  功    能：主函数，程序入口
  输入参数：int argc, char** argv
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1); //cin不能读有空格的文件

	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	/* 读入数据 */
	if (list.read(file1, 1) < 0) {
		return -1;
	}
	if (list.read(file2, 2) < 0) {
		return -1;
	}

	/* 处理数据 */
	list.process_lists();

	/* 打印 */
	list.print("最终选课名单");

	return 0;
}

