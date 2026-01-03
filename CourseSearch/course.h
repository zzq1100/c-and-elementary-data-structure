#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <windows.h>

#define MAX_NAME 50
#define MAX_TEACHER 30
#define MAX_CLASSROOM 20

typedef struct Course 
{
    char name[MAX_NAME];       // 课程名称
    char teacher[MAX_TEACHER]; // 任课教师
    int day;                   // 上课星期（1-7）
    int timeSlot;              // 上课节次（1-12）
    char classroom[MAX_CLASSROOM]; // 教室
} Course;


void CoursetInit(const char* file);
void CoursetAdd(const char* file);
void CourseDelete(const char* file);
void CourseShow(const char* file);
void CourseFind(const char* file);
void CourseModify(const char* file);
void CourseDestroy(const char* file); 