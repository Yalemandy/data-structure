#define _CRT_SECURE_NO_WANINGS 1

#include "LinkList.h"


//打印
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//创建一个新的数据
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* newlist = (SLTNode*)malloc(sizeof(SLTNode));
	if (newlist == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newlist->data = x;
	newlist->next = NULL;
	return newlist;
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newlist = SLTBuyNode(x);
	SLTNode* plist = *pphead;
	if (*pphead == NULL)
	{
		*pphead = newlist;
	}
	else
	{
		while (plist->next)
		{
			plist = plist->next;
		}
		plist->next = newlist;
	}
}

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newlist = SLTBuyNode(x);
	newlist->next = *pphead;
	*pphead = newlist;
}

//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* pcur = *pphead;
		SLTNode* pret = *pphead;
		while (pcur->next)
		{
			pret = pcur;
			pcur = pcur->next;
		}
		free(pcur);
		pcur = NULL;
		pret->next = NULL;
	}
}

//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = (*pphead)->next;
	free(*pphead);
	*pphead = pcur;
}

//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);
	assert(pos);
	SLTNode* newlist = SLTBuyNode(x);
	//头插
	if ((*pphead)->next == NULL)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//prev -> newlist -> pos
		newlist->next = pos;
		prev->next = newlist;
	}
}

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newlist = SLTBuyNode(x);
	//pos -> newlist -> pos->next
	newlist->next = pos->next;
	pos->next = newlist;
}

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);
	//头删
	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//销毁链表
void SListDesTroy(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}