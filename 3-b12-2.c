// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x, n=0;

	while (1) {
		printf("������x��ֵ[0-100] : ");
		ret = scanf("%d", &x); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if (ret == 1 && (x >= 0 && x <= 100))
			break;
		else {
			printf("�����д�[ret=%d x=%d],����������\n", ret, x); //ȷ��һ�£�ret��ֵ����scanf�ķ���ֵ����ʲô����:�ɹ���ȡ�����Ʊ����ġ�������
			if (ret == 0) {
				clearerr(stdin);
				scanf("%*[^\n]");
				scanf("%*c");
				continue;
			}
		}
	}

	printf("ret=%d x=%d\n", ret, x);

	return 0;
}

