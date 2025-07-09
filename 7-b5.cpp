// 
#define _CRT_SECURE_NO_WARNINGS
/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�
class stu_list;
/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	bool in_round_1;
	bool in_round_2;
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
	friend class stu_list;
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */
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
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void process_lists();
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */


/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
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
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
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
  �������ƣ�stu_list::process_lists
  ��    �ܣ�������ѡ�������ϲ�������ȥ���ظ���
  �����������
  �� �� ֵ����
  ˵    ����
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
  �������ƣ�stu_list::print
  ��    �ܣ���ӡ���յ�ѡ������
  ���������prompt - ��ӡǰ����ʾ��Ϣ
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int stu_list::print(const char* prompt)
{
	if (prompt) {
		cout << prompt << endl;
	}

	const int SEQ_WIDTH = 4;   
	const int NO_WIDTH = 7;   
	const int ROUND_WIDTH = 6;  

	int max_name_width = strlen("����");
	for (int i = 0; i < list_merge_num; ++i) {
		int current_len = strlen(list_merge[i].stu_name);
		if (current_len > max_name_width) {
			max_name_width = current_len;
		}
	}

	int total_width = 1 + SEQ_WIDTH + 2 + NO_WIDTH + 2 + max_name_width + 2 + ROUND_WIDTH + 2 + ROUND_WIDTH + 1;

	cout << setfill('=') << setw(total_width) << "" << setfill(' ') << endl;

	cout << " " << left
		<< setw(SEQ_WIDTH) << "���" << "  "
		<< setw(NO_WIDTH) << "ѧ��" << "  "
		<< setw(max_name_width) << "����" << "  "
		<< setw(ROUND_WIDTH) << "��һ��" << "  "
		<< setw(ROUND_WIDTH) << "�ڶ���" << " " << endl;

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
			round2_output = "�˿�";
		}
		else{
			round1_output = "/";
			round2_output = "��ѡ";
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
  �������ƣ�main
  ��    �ܣ����������������
  ���������int argc, char** argv
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0) {
		return -1;
	}
	if (list.read(file2, 2) < 0) {
		return -1;
	}

	/* �������� */
	list.process_lists();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

