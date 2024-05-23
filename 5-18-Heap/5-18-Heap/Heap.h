#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

// �ѵĳ�ʼ��
void HeapInit(Heap* hp);

// �ѵ�����
void HeapDestory(Heap* hp);

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
int HeapEmpty(Heap* hp);

// ��������ж�����
void HeapSort(int* a, int n);

void swap(HPDataType* x, HPDataType* y);

// ���ϵ���
void AdjustUp(HPDataType* a, int child);

// ���µ���
void AdjustDown(HPDataType* a, int n, int head);