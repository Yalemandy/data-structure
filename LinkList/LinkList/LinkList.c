#define _CRT_SECURE_NO_WANINGS 1

#include "LinkList.h"


//��ӡ
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

//����һ���µ�����
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

//β��
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

//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newlist = SLTBuyNode(x);
	newlist->next = *pphead;
	*pphead = newlist;
}

//βɾ
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

//ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = (*pphead)->next;
	free(*pphead);
	*pphead = pcur;
}

//����
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

//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);
	assert(pos);
	SLTNode* newlist = SLTBuyNode(x);
	//ͷ��
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

//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newlist = SLTBuyNode(x);
	//pos -> newlist -> pos->next
	newlist->next = pos->next;
	pos->next = newlist;
}

//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);
	//ͷɾ
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

//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//��������
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