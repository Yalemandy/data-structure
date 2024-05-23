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

//��ʼ��
//void LTInit(LTNode** pphead);
LTNode* LTInit();

//��������
void LTDesTroy(LTNode* phead);

//˫����Ľڵ㴴��
LTNode* LTCreate(DLDataType x);

//����Ĵ�ӡ
void LTPrint(LTNode* phead);

//��������֮ǰ����������ʼ����ֻ��һ��ͷ�������
//���ı��ڱ�λ�ĵ�ַ����˴�һ������
//β��
void LTPushBack(LTNode* phead, DLDataType x);

//ͷ��
void LTPushFront(LTNode* phead, DLDataType x);

//βɾ
void LTPopBack(LTNode* phead);

//ͷɾ
void LTPopFront(LTNode* phead);


//��posλ��֮���������
void LTInsert(LTNode* pos, DLDataType x);

//ɾ��pos�ڵ�
void LTErase(LTNode* pos);

//����pos�ڵ�
LTNode* LTFind(LTNode* phead, DLDataType x);