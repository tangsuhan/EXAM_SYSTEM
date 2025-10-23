#include "exam_system.h"
#include <stdio.h>
//临时函数，和项目毫无关系，用来改学生作业的
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
	printf("请输入一个正整数(判断是否为快乐数)\n");
	scanf("%d", &num);
	if (num > 0) {
		if (kls(num) == 1) {
			printf("%d是快乐数\n", num);
		}
		else {
			printf("%d不是快乐数\n", num);
		}
	}
	else {
		printf("输入错误\n请输入正整数\n");
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