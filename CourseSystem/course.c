#include"course.h"

void CourseInit()
{
	FILE* pf = fopen("data.txt", "a");
	if (pf == NULL)
	{
		perror("fopen fail");
	}
	/*char ch1[10] = "课程";
	fprintf(pf, "%-5s", ch1);
	char ch2[10] = "教师";
	fprintf(pf, "%-5s", ch2);
	char ch3[10] = "星期";
	fprintf(pf, "%-5s", ch3);
	char ch4[10] = "节数";
	fprintf(pf, "%-5s", ch4);
	char ch5[10] = "教室";
	fprintf(pf, "%-5s", ch5);*/
	fclose(pf);
	pf = NULL;
}

void CourseAdd()
{
	FILE* pf = fopen(file, "a");
	if (pf == NULL)
	{
		perror("fopen fail");
	}
	course infomation;
	printf("请输入要添加的课程名称：\n");
	scanf("%s", infomation.name);
	printf("请输入任课教师：\n");
	scanf("%s", infomation.teacher);
	printf("请输入上课星期(输入数字)：\n");
	scanf("%d", &infomation.day);
	printf("请输入在第几节上课(输入数字)：\n");
	scanf("%d", &infomation.timeSlot);
	printf("请输入所在教室：\n");
	scanf("%s", infomation.classroom);
	printf("添加成功！\n");
	fprintf(pf, "%-7s  %-7s  %-7d  %-7d  %-7s\n",
		infomation.name,
		infomation.teacher,
		infomation.day,
		infomation.timeSlot,
		infomation.classroom);
	fclose(pf);
	pf = NULL;
}