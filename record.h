#ifndef RECORD_H
#define RECORD_H
#define MAX_RECORDS 500
typedef struct {
	char date[20];//日期格式：2026-01-31
	char type[10];//类型：收入/支出
	float amount;//金额
	char note[50];//吃饭，交通，游玩 
}Record;
void addRecord(Record records[],int*count);//添加记录
void showAllRecords(Record records[], int count); // 显示所有记录
void queryByDate(Record records[], int count);  // 按日期查询
void calculateTotal(Record records[], int count); // 统计收支
void modifyRecord(Record records[], int count); // 修改记录
void deleteRecord(Record records[], int *count); // 删除记录
float calculateByNote(Record records[],int count,const char *note);//按备注查询 
#endif
