#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

////��̬˳���
//struct SList
//{
//	SLTDataType arr[100];
//	int size;  //��Ч�����ݸ���
//};

//��̬˳���
typedef struct SList
{
	SLTDataType* arr;
	int size;  //��Ч�����ݸ���
	int capacity;//��ǰ�ռ��С
}SList;

//˳���ĳ�ʼ��
void SLInit(SList* ps);

//˳��������
void SLDestroy(SList* ps);

//˳���Ĵ�ӡ
void SLPrint(SList ps);

//˳��������
void SLCheck(SList* ps);

//˳����ͷ��
void SLPushFront(SList* ps, SLTDataType x);

//˳����β��
void SLPushBack(SList* ps, SLTDataType x);

//˳����ͷɾ
void SLDelFront(SList* ps);

//˳����βɾ
void SLDelBack(SList* ps);

//˳���ָ��λ��֮ǰ��������
void SLInsert(SList* ps, int pos, SLTDataType x);

//˳���ָ��λ��֮ǰɾ������
void SLErase(SList* ps, int pos);

//˳���Ĳ���
int SLFind(SList* ps, SLTDataType x);