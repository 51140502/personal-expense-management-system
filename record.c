#include <stdio.h>
#include <string.h>
#include "record.h"
#include "file.h"
//1.添加收支记录 
void addRecord(Record records[],int*count){
	//检查记录是否已满 
	if(*count>=MAX_RECORDS){
		printf("记录已满，无法添加!\n");
		return;
	}
	//创建一个临时结构体r，存用户输入的新记录 
	Record r;
	printf("请输入日期(格式：2026-01-31)：");
	scanf("%s",r.date);//输入日期存到r.date 
	printf("请输入类型（收入/支出）：");
    scanf("%s", r.type);
    printf("请输入金额：");
    scanf("%f", &r.amount);
    printf("请输入备注：");
    scanf("%s", r.note);
	records[*count]=r;
	(*count)++;
	printf("添加成功!\n");
	saveData(records,*count);
}
//2.显示所有记录 
void showAllRecords(Record records[], int count){
	//先判断有没有记录
	if(count==0){
		printf("暂无记录!\n");
		return;
	} 
	//打印表头
	printf("=====所有收支记录=====\n");
	printf("日期\t\t类型\t金额\t备注\n");//\t用来对齐
	//循环遍历records数组，打印每条记录
	int i;
	for(i=0;i<count;i++){
		printf("%s\t%s\t%.2f\t%s\n",records[i].date,records[i].type,records[i].amount,records[i].note);
	} 
}
//3.按日期查询 
void queryByDate(Record records[], int count){
	//让用户输入要查询的日期
	char targetDate[20];
	printf("请输入要查询的日期(格式：2026-01-31）:");
	scanf("%s",targetDate);
	//打印查询结果的表头
	printf("=====%s的记录=====\n",targetDate);
	printf("日期\t\t类型\t金额\t备注\n");
	int found=0;//o=没找到；1= 找到；
	//循环遍历数组，对比每条记录
	int i;
	for(i=0;i<count;i++){
		if(strcmp(records[i].date,targetDate)==0){
			printf("%s\t%s\t%.2f\t%s\n",records[i].date,records[i].type,records[i].amount,records[i].note);
			found=1;
		}
	} 
	if(found==0){
		printf("该日期无记录!\n");
	}
}
//4.统计收支 
void calculateTotal(Record records[], int count) {
    float income = 0, expense = 0;
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(records[i].type, "收入") == 0) {
            income += records[i].amount; // 收入累加
        } else {
            expense += records[i].amount; // 支出累加
        }
    printf("===== 收支统计 =====\n");
    printf("总收入：%.2f\n总支出：%.2f\n余额：%.2f\n", income, expense, income - expense);
}
}
//5.修改记录
void modifyRecord(Record records[], int count){
	if(count==0){
		printf("暂无记录可修改！\n");
		return;
	}
	//让用户输入要修改的记录序号
	int index;
	printf("请输入要修改的序号(1-%d)：",count);
	scanf("%d",&index);
	index--;
	if(index<0||index>=count){
		printf("序号错误!\n");
		return;
	}
	printf("请输入新日期：");
	scanf("%s",records[index].date);
	printf("请输入新类型：");
	scanf("%s",records[index].type);
	printf("请输入新金额：");
	scanf("%f",&records[index].amount);
	printf("请输入新备注：");
	scanf("%s",records[index].note);
	printf("修改成功!\n");
	saveData(records,count);
}
//6.删除收支记录
void deleteRecord(Record records[], int *count){
	if(*count==0){
		printf("暂无记录可删除!\n");
		return;
	}
	int index;
	printf("请输入要删除的记录序号(1-%d)：",*count);
	scanf("%d",&index);
	index--;
	if(index<0||index>=*count){
		printf("序号错误!\n");
		return;
	}
	int i;
	for(i=index;i<*count-1;i++){
		records[i]=records[i+1];
	}
	(*count)--;
	printf("删除成功!\n");
	saveData(records,*count);
}
//7.按备注查询
float calculateByNote(Record records[],int count,const char *note){
	float sum=0;
	int i;
	for(i=0;i<count;i++){
		if(records[i].note[0]!='\0'&&strstr(records[i].note,note)!=NULL){
			sum=sum+records[i].amount;
		}
	}
	return sum;
}




























