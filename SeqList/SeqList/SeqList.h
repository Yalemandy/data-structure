#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

////静态顺序表
//struct SList
//{
//	SLTDataType arr[100];
//	int size;  //有效的数据个数
//};

//动态顺序表
typedef struct SList
{
	SLTDataType* arr;
	int size;  //有效的数据个数
	int capacity;//当前空间大小
}SList;

//顺序表的初始化
void SLInit(SList* ps);

//顺序表的销毁
void SLDestroy(SList* ps);

//顺序表的打印
void SLPrint(SList ps);

//顺序表的扩容
void SLCheck(SList* ps);

//顺序表的头插
void SLPushFront(SList* ps, SLTDataType x);

//顺序表的尾插
void SLPushBack(SList* ps, SLTDataType x);

//顺序表的头删
void SLDelFront(SList* ps);

//顺序表的尾删
void SLDelBack(SList* ps);

//顺序表指定位置之前插入数据
void SLInsert(SList* ps, int pos, SLTDataType x);

//顺序表指定位置之前删除数据
void SLErase(SList* ps, int pos);

//顺序表的查找
int SLFind(SList* ps, SLTDataType x);