#define _CRT_SECURE_NO_WANINGS 1

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

//双链表的节点创建
LTNode* LTCreate(DLDataType x)
{
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));

	if (newNode == NULL)
	{
		perror("LTInit()::malloc()");
		exit(-1);
	}

	newNode->next = newNode;
	newNode->prv = newNode;
	newNode->data = x;
	return newNode;
}

//初始化
//void LTInit(LTNode** pphead)
//{
//	LTNode* newhead = LTFound(-1);
//}

LTNode* LTInit()
{
	LTNode* newhead = LTCreate(-1);

	return newhead;
}

//销毁链表
void LTDesTroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;

	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
}

//链表的打印
void LTPrint(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//查找pos节点
LTNode* LTFind(LTNode* phead, DLDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//插入数据之前，链表必须初始化到只有一个头结点的情况
//不改变哨兵位的地址，因此传一级即可
//尾插
void LTPushBack(LTNode* phead, DLDataType x)
{
	assert(phead);

	LTNode* cmp = LTCreate(x);

	// phead phead->prv cmp
	cmp->next = phead;
	cmp->prv = phead->prv;

	phead->prv->next = cmp;
	phead->prv = cmp;
}

//头插
void LTPushFront(LTNode* phead, DLDataType x)
{
	assert(phead);

	LTNode* tmp = LTCreate(x);

	// phead tmp phead->next

	tmp->next = phead->next;
	tmp->prv = phead;

	phead->next = tmp;
	phead->next->prv = tmp;
}


//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead && phead->next != phead);

	LTNode* cur = phead->prv;

	// phead cur->prv cur
	phead->prv = cur->prv;
	cur->prv->next = phead;

	free(cur);
	cur = NULL;
}

//头删
void LTPopFront(LTNode* phead)
{
	assert(phead && phead->next != phead);

	LTNode* cur = phead->next;
	// phead  cur cur->next

	phead->next = cur->next;
	cur->next = phead;

	free(cur);
	cur = NULL;
}

//在pos位置之后插入数据
void LTInsert(LTNode* pos, DLDataType x)
{
	assert(pos);

	LTNode* cur = LTCreate(x);

	// pos cur pos->next
	cur->next = pos->next;
	cur->prv = pos;

	pos->next = cur;
	pos->next->prv = cur;

}

//删除pos节点
void LTErase(LTNode* pos)
{
	assert(pos);

	// pos->prv pos pos->next

	pos->prv->next = pos->next;
	pos->next->prv = pos->prv;

	free(pos);
	pos = NULL;
}


void DLinkListText()
{
	LTNode* phead = LTInit();

	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPrint(phead);

	LTPushFront(phead, 0);
	LTPushFront(phead, 999);
	LTPrint(phead);

	// LTPopFront(phead);
	// LTPrint(phead);

	LTPopBack(phead);
	LTPrint(phead);

	LTDesTroy(phead);
}
	



int main()
{
	DLinkListText();
	return 0;
}