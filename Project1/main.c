#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <assert.h>

#define FILENAME "courses.txt"
#define MAX_NAME 50
#define MAX_TEACHER 30
#define MAX_CLASSROOM 20

typedef struct Course {
    char name[MAX_NAME];       // 课程名称
    char teacher[MAX_TEACHER]; // 任课教师
    int day;                   // 上课星期（1-7）
    int timeSlot;              // 上课节次（1-12）
    char classroom[MAX_CLASSROOM]; // 教室
} Course;

void menu();
void CourseInit();
void CourseAdd();
void CourseDelete();
void CourseShow();
void CourseFind();
void CourseModify();
void CourseDestroy();

int FindCourseByName(const char* name, Course* outCourse);
void SaveAllCourses(Course* courses, int count);

int main() {
    CourseInit();  

    int input = 0;
    do {
        printf("\n");
        menu();
        scanf("%d", &input);
        switch (input) {
        case 1:
            CourseAdd();
            break;
        case 2:
            CourseDelete();
            break;
        case 3:
            CourseModify();
            break;
        case 4:
            CourseFind();
            break;
        case 5:
            CourseShow();
            break;
        case 0:
            printf("退出系统\n");
            break;
        default:
            printf("输入错误，请重新输入：\n");
            break;
        }
    } while (input != 0);

    return 0;
}

void menu() {
    printf("****************************\n");
    printf("*********--课程表--*********\n");
    printf("****** 1.添加  2.删除 ******\n");
    printf("****** 3.修改  4.查找 ******\n");
    printf("****** 5.打印  0.退出 ******\n");
    printf("****************************\n");
    printf("请选择要进行的操作：");
}

void CourseInit() {
    FILE* pf = fopen(FILENAME, "a");
    if (pf == NULL) {
        perror("文件创建失败");
        return;
    }
    fclose(pf);
}

void CourseAdd() {
    Course info;
    printf("请输入要添加的课程名称：\n");
    scanf("%s", info.name);
    printf("请输入任课教师：\n");
    scanf("%s", info.teacher);
    printf("请输入上课星期(1-7)：\n");
    scanf("%d", &info.day);
    printf("请输入在第几节上课(1-12)：\n");
    scanf("%d", &info.timeSlot);
    printf("请输入所在教室：\n");
    scanf("%s", info.classroom);

    FILE* pf = fopen(FILENAME, "a");
    if (pf == NULL) {
        perror("文件打开失败");
        return;
    }

    fprintf(pf, "%-15s %-10s %-4d %-4d %-10s\n",
        info.name,
        info.teacher,
        info.day,
        info.timeSlot,
        info.classroom);

    fclose(pf);
    printf("添加成功！\n");
    Sleep(1000);
    system("cls");
}

int FindCourseByName(const char* name, Course* outCourse) {
    FILE* pf = fopen(FILENAME, "r");
    if (pf == NULL) {
        return 0;  
    }

    Course temp;
    int found = 0;

    while (fscanf(pf, "%s %s %d %d %s",
        temp.name,
        temp.teacher,
        &temp.day,
        &temp.timeSlot,
        temp.classroom) == 5) {
        if (strcmp(temp.name, name) == 0) {
            if (outCourse) {
                *outCourse = temp;
            }
            found = 1;
            break;
        }
    }

    fclose(pf);
    return found;
}

void CourseDelete() {
    char name[MAX_NAME];
    printf("请输入要删除的课程名称：\n");
    scanf("%s", name);

    Course courses[100];
    int count = 0;

    FILE* pf = fopen(FILENAME, "r");
    if (pf == NULL) {
        printf("暂无课程记录！\n");
        Sleep(1000);
        system("cls");
        return;
    }


    while (count < 100 &&
        fscanf(pf, "%s %s %d %d %s",
            courses[count].name,
            courses[count].teacher,
            &courses[count].day,
            &courses[count].timeSlot,
            courses[count].classroom) == 5) {
        count++;
    }
    fclose(pf);

    int foundIndex = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(courses[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("未找到课程：%s\n", name);
        Sleep(1000);
        system("cls");
        return;
    }

    for (int i = foundIndex; i < count - 1; i++) {
        courses[i] = courses[i + 1];
    }
    count--;

    SaveAllCourses(courses, count);

    printf("删除成功！\n");
    Sleep(1000);
    system("cls");
}

void SaveAllCourses(Course* courses, int count) {
    FILE* pf = fopen(FILENAME, "w");
    if (pf == NULL) {
        perror("文件保存失败");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(pf, "%-15s %-10s %-4d %-4d %-10s\n",
            courses[i].name,
            courses[i].teacher,
            courses[i].day,
            courses[i].timeSlot,
            courses[i].classroom);
    }

    fclose(pf);
}

void CourseShow() {
    FILE* pf = fopen(FILENAME, "r");
    if (pf == NULL) {
        printf("暂无课程记录！\n");
        return;
    }

    printf("\n%-15s %-10s %-4s %-4s %-10s\n",
        "课程名称", "教师", "星期", "节次", "教室");
    printf("-------------------------------------------------\n");

    Course temp;
    int hasData = 0;

    while (fscanf(pf, "%s %s %d %d %s",
        temp.name,
        temp.teacher,
        &temp.day,
        &temp.timeSlot,
        temp.classroom) == 5) {
        printf("%-15s %-10s %-4d %-4d %-10s\n",
            temp.name,
            temp.teacher,
            temp.day,
            temp.timeSlot,
            temp.classroom);
        hasData = 1;
    }

    if (!hasData) {
        printf("暂无课程记录！\n");
    }

    fclose(pf);
}

void CourseFind() {
    char name[MAX_NAME];
    printf("请输入要查找的课程名称：\n");
    scanf("%s", name);

    Course found;
    if (FindCourseByName(name, &found)) {
        printf("\n查找结果：\n");
        printf("课程名称：%s\n", found.name);
        printf("任课教师：%s\n", found.teacher);
        printf("上课星期：%d\n", found.day);
        printf("上课节次：%d\n", found.timeSlot);
        printf("所在教室：%s\n", found.classroom);
    }
    else {
        printf("未找到课程：%s\n", name);
    }
}

void CourseModify() {
    char name[MAX_NAME];
    printf("请输入要修改的课程名称：\n");
    scanf("%s", name);

    // 读取所有课程
    Course courses[100];
    int count = 0;

    FILE* pf = fopen(FILENAME, "r");
    if (pf == NULL) {
        printf("暂无课程记录！\n");
        Sleep(1000);
        system("cls");
        return;
    }

    while (count < 100 &&
        fscanf(pf, "%s %s %d %d %s",
            courses[count].name,
            courses[count].teacher,
            &courses[count].day,
            &courses[count].timeSlot,
            courses[count].classroom) == 5) {
        count++;
    }
    fclose(pf);

    int foundIndex = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(courses[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("未找到课程：%s\n", name);
        Sleep(1000);
        system("cls");
        return;
    }

    printf("请输入新的课程名称：\n");
    scanf("%s", courses[foundIndex].name);
    printf("请输入新的任课教师：\n");
    scanf("%s", courses[foundIndex].teacher);
    printf("请输入新的上课星期(1-7)：\n");
    scanf("%d", &courses[foundIndex].day);
    printf("请输入新的上课节次(1-12)：\n");
    scanf("%d", &courses[foundIndex].timeSlot);
    printf("请输入新的教室：\n");
    scanf("%s", courses[foundIndex].classroom);

    SaveAllCourses(courses, count);

    printf("修改成功！\n");
    Sleep(1000);
    system("cls");
}

void CourseDestroy() {
    FILE* pf = fopen(FILENAME, "w");
    if (pf) {
        fclose(pf);
        printf("所有课程已清空！\n");
    }
}