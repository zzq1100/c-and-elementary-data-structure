#include "course.h"

// 初始化：确保文件存在
void CoursetInit(const char* file) 
{
    FILE* fp = fopen(file, "ab");
    if (fp) 
    {
        fclose(fp);
    }
}

// 添加课程
void CoursetAdd(const char* file)
{
    Course course;
    printf("请输入要添加的课程名称：\n");
    scanf("%s", course.name);
    printf("请输入任课教师：\n");
    scanf("%s", course.teacher);
    printf("请输入上课星期：\n");
    scanf("%d", &course.day);
    printf("请输入在第几节上课：\n");
    scanf("%d", &course.timeSlot);
    printf("请输入所在教室：\n");
    scanf("%s", course.classroom);

    FILE* fp = fopen(file, "ab");
    if (fp == NULL) 
    {
        perror("文件打开失败");
        return;
    }
    fwrite(&course, sizeof(Course), 1, fp);
    fclose(fp);
    printf("添加成功！\n");
    Sleep(1000);
    system("cls");
}

// 查找课程（内部使用）
static int findCourseByName(const char* filename, const char* name, Course* out) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) return -1;

    Course temp;
    int index = 0;
    while (fread(&temp, sizeof(Course), 1, fp)) {
        if (strcmp(temp.name, name) == 0) {
            if (out) *out = temp;
            fclose(fp);
            return index;
        }
        index++;
    }
    fclose(fp);
    return -1;
}

// 删除课程
void ContactDelete(const char* filename) {
    char name[MAX_NAME];
    printf("请输入要删除的课程名称：\n");
    scanf("%s", name);

    // 打开临时文件
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("文件不存在或无课程！\n");
        Sleep(1000);
        system("cls");
        return;
    }

    FILE* temp = fopen("temp.dat", "wb");
    if (!temp) {
        fclose(fp);
        perror("创建临时文件失败");
        return;
    }

    Course c;
    int found = 0;
    while (fread(&c, sizeof(Course), 1, fp)) {
        if (strcmp(c.name, name) == 0) {
            found = 1;
            continue; // 跳过要删除的
        }
        fwrite(&c, sizeof(Course), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove(filename);
        rename("temp.dat", filename);
        printf("删除成功！\n");
    }
    else {
        remove("temp.dat");
        printf("该课程不存在！\n");
    }
    Sleep(1000);
    system("cls");
}

// 查找并显示课程
void ContactFind(const char* filename) {
    char name[MAX_NAME];
    printf("请输入要查看的课程名称：\n");
    scanf("%s", name);

    Course c;
    int index = findCourseByName(filename, name, &c);
    if (index < 0) {
        printf("该课程不存在！\n");
        Sleep(1000);
        system("cls");
        return;
    }

    printf("\n");
    printf("课程     教师     星期     节数     教室\n");
    printf("%-7s  %-7s  %-7d  %-7d  %-7s\n",
        c.name,
        c.teacher,
        c.day,
        c.timeSlot,
        c.classroom);
}

// 修改课程
void ContactModify(const char* filename) {
    char name[MAX_NAME];
    printf("请输入要修改的课程名称：\n");
    scanf("%s", name);

    FILE* fp = fopen(filename, "rb+");
    if (!fp) {
        printf("文件打开失败！\n");
        Sleep(1000);
        system("cls");
        return;
    }

    Course c;
    int found = 0;
    long pos = 0;
    while (fread(&c, sizeof(Course), 1, fp)) {
        if (strcmp(c.name, name) == 0) {
            found = 1;
            break;
        }
        pos = ftell(fp);
    }

    if (!found) {
        printf("该课程不存在！\n");
        fclose(fp);
        Sleep(1000);
        system("cls");
        return;
    }

    printf("请输入新的课程名称：\n");
    scanf("%s", c.name);
    printf("请输入任课教师：\n");
    scanf("%s", c.teacher);
    printf("请输入上课星期：\n");
    scanf("%d", &c.day);
    printf("请输入在第几节上课：\n");
    scanf("%d", &c.timeSlot);
    printf("请输入所在教室：\n");
    scanf("%s", c.classroom);

    // 写回文件
    fseek(fp, pos, SEEK_SET);
    fwrite(&c, sizeof(Course), 1, fp);
    fclose(fp);

    printf("修改成功！\n");
    Sleep(1000);
    system("cls");
}

// 显示所有课程
void ContactShow(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("暂无课程记录！\n");
        return;
    }

    printf("\n");
    printf("课程     教师     星期     节数     教室\n");
    Course c;
    int count = 0;
    while (fread(&c, sizeof(Course), 1, fp)) {
        printf("%-7s  %-7s  %-7d  %-7d  %-7s\n",
            c.name,
            c.teacher,
            c.day,
            c.timeSlot,
            c.classroom);
        count++;
    }

    if (count == 0) {
        printf("暂无课程记录！\n");
    }

    fclose(fp);
}

// 清空文件（可选）
void ContactDestroy(const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp) fclose(fp);
}
