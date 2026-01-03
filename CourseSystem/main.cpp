#include"course.h"

void menu()
{
	printf("****************************\n");
	printf("*********--课程表--*********\n");
	printf("****** 1.添加  2.删除 ******\n");
	printf("****** 3.修改  4.查找 ******\n");
	printf("****** 5.打印  0.退出 ******\n");
	printf("****************************\n");
	printf("请选择要进行的操作：");
}
void contact()
{
	int input = 0;
	CourseInit();
	do
	{
		printf("\n");
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			CourseAdd();
			break;
		case 2:
			//CourseDelete("data.txt");
			break;
		case 3:
			//CourseModify("data.txt");
			break;
		case 4:
			//CourseFind("data.txt");
			break;
		case 5:
			//CourseShow("data.txt");
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
	} while (input);
}
int main()
{
	contact();
	return 0;
}