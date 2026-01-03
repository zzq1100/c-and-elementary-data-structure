#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef struct Course
{
    char name[50];      // 课程名称
    char teacher[30];   // 任课教师
    int day;            // 星期几（1-7）
    int timeSlot;       // 第几节课（1-12）
    char classroom[20]; // 教室
}course;

void CourseInit();
void CourseAdd();
void CourseDelete(const char* file);
void CourseShow(const char* file);
void CourseFind(const char* file);
void CourseModify(const char* file);
void CourseDestroy(const char* file);