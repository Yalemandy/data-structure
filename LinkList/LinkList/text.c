#define _CRT_SECURE_NO_WANINGS 1

#include "LinkList.h"

//void LinkListtext()
//{
//	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	node1->data = 1;
//
//	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
//	node2->data = 2;
//
//	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	node3->data = 3;
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = NULL;
//
//	SLTNode* plist = node1;
//	SLTPrint(plist);
//}

void LinkListtext01()
{
	SLTNode* Plist = NULL;
	//尾插
	SLTPushBack(&Plist, 3);
	SLTPrint(Plist);
	SLTPushBack(&Plist, 4);
	SLTPrint(Plist);
	SLTPushBack(&Plist, 5);
	SLTPrint(Plist);
	//SLTPushBack(&Plist, 6);
	//SLTPrint(Plist);
	////头插
	//SLTPushFront(&Plist, 2);
	//SLTPrint(Plist);
	//SLTPushFront(&Plist, 1);
	//SLTPrint(Plist);
	////尾删除
	//SLTPopBack(&Plist);
	//SLTPrint(Plist);
	//SLTPopBack(&Plist);
	//SLTPrint(Plist);
	////头删
	//SLTPopFront(&Plist);
	//SLTPrint(Plist);
	//SLTPopFront(&Plist);
	//SLTPrint(Plist);
	//查找
	SLTNode* find = SLTFind(Plist, 3);
	if (find == NULL)
	{
		printf("没找到!\n");
	}
	else
	{
		printf("找到了!\n");
	}
	/*SLTInsert(&Plist, find, 999);
	SLTPrint(Plist);
	SLTInsertAfter(find, 1000);
	SLTPrint(Plist);
	SLTEraseAfter(find);
	SLTPrint(Plist);*/
	/*SLTErase(&Plist,find);
	SLTPrint(Plist);*/
	SListDesTroy(&Plist);
}

int main()
{
	//LinkListtext();
	LinkListtext01();
	return 0;
}