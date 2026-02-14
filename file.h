#ifndef FILE_H
#define FILE_H
#include "record.h"
#define DATA_FILE "income_expense.dat"

// 从文件加载数据到数组
void loadData(Record records[], int *count);
// 把数组数据保存到文件
void saveData(Record records[], int count);

#endif
