#include <string.h>
#include <stdio.h>
#include "record.h"
#include "file.h"

//声明功能函数
void addRecord(Record records[],int*count);//添加记录
void showAllRecords(Record records[], int count); // 显示所有记录
void queryByDate(Record records[], int count);  // 按日期查询
void calculateTotal(Record records[], int count); // 统计收支
void modifyRecord(Record records[], int count); // 修改记录
void deleteRecord(Record records[], int *count); // 删除记录
float calculateByNote(Record records[],int count,const char *note);//按备注查询 

int main(){
	Record records[500];
	int count =0;
	int choice;
	//启动时从文件加载记录
	loadData(records,&count); 
	
	while(1){
		printf("\n=====个人收支管理系统=====\n");
		printf("1.添加记录\n");
		printf("2.显示所有记录\n");
		printf("3.按日期查询\n");
		printf("4.统计收支\n");
		printf("5.修改记录\n");
		printf("6.删除记录\n");
		printf("7.按备注统计消费\n");
		printf("0.退出系统\n");
		scanf("%d",&choice); 
		
		//功能分支
		switch(choice){
			case 1:addRecord(records,&count);break;
			case 2:showAllRecords(records,count);break;
			case 3:queryByDate(records,count);break;
			case 4:calculateTotal(records,count);break;
			case 5:modifyRecord(records,count);break;
			case 6:deleteRecord(records,&count);break;
			case 7:{
				char note[50];
				printf("请输入你要的备注关键词(如：吃饭，交通，游玩)");
				scanf("%49s",note);
				float total=calculateByNote(records,count,note);
				printf("%s的总消费为：%.2f元\n",note,total);
				break;
			}
			case 0:saveData(records,count);
			printf("感谢使用,再见!\n");
			return 0;
			default:printf("输入错误,请重新选择!\n");
		} 
	}
	return 0;
} 
