#include "exam_system.h"
#include <stdio.h>
//��ʱ����������Ŀ���޹�ϵ��������ѧ����ҵ��
void xuesheng(int c);
int kls(int y);
int total(int x);
int main() {
	//xuesheng(17);
	show exam_system_init{};
	exam_system_init.show_main();
	return 0;
}
void xuesheng(int c) {
	int num;
	printf("������һ��������(�ж��Ƿ�Ϊ������)\n");
	scanf("%d", &num);
	if (num > 0) {
		if (kls(num) == 1) {
			printf("%d�ǿ�����\n", num);
		}
		else {
			printf("%d���ǿ�����\n", num);
		}
	}
	else {
		printf("�������\n������������\n");
	}
}
int total(int x)
{
	int temp1 = 0, temp2 = 0;
	while (x > 0) {
		temp1 = x % 10;
		temp2 = temp2 + temp1 * temp1;
		x = x / 10;
	}
	return temp2;
}
int kls(int y)
{
	int save = y;
	while (y != 1) {
		y = total(y);
		if (y == save) {
			return 0;
		}
	}
	return y == 1;
}