#include <stdio.h>
#include "file.h"
#include "record.h"

// 数据存到这个文件里（程序会自动创建）
#define DATA_FILE "income_expense.dat"

// 保存数据到文件
void saveData(Record records[], int count) {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp == NULL) {
        printf("保存数据失败！\n");
        return;
    }
    fwrite(records, sizeof(Record), count, fp);
    fclose(fp);
    printf("数据已保存！\n");
}

// 从文件加载数据
void loadData(Record records[], int *count) {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (fp == NULL) {
        *count = 0; // 第一次运行没文件，记录数为0
        return;
    }
    *count = fread(records, sizeof(Record), MAX_RECORDS, fp);
    fclose(fp);
}
