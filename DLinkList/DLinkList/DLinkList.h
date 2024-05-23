#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef int DLDataType;

typedef struct LinkNode
{
	DLDataType data;
	struct LinkNode* next;
	struct LinkNode* prv;
}LTNode;

//初始化
//void LTInit(LTNode** pphead);
LTNode* LTInit();

//销毁链表
void LTDesTroy(LTNode* phead);

//双链表的节点创建
LTNode* LTCreate(DLDataType x);

//链表的打印
void LTPrint(LTNode* phead);

//插入数据之前，链表必须初始化到只有一个头结点的情况
//不改变哨兵位的地址，因此传一级即可
//尾插
void LTPushBack(LTNode* phead, DLDataType x);

//头插
void LTPushFront(LTNode* phead, DLDataType x);

//尾删
void LTPopBack(LTNode* phead);

//头删
void LTPopFront(LTNode* phead);


//在pos位置之后插入数据
void LTInsert(LTNode* pos, DLDataType x);

//删除pos节点
void LTErase(LTNode* pos);

//查找pos节点
LTNode* LTFind(LTNode* phead, DLDataType x);