#define _CRT_SECURE_NO_WANINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>


typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

// ��ʼ��������
void STInit(ST* pst);
void STDestroy(ST* pst);

// ��ջ  ��ջ
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

// ȡջ������
STDataType STTop(ST* pst);

// �п�
bool STEmpty(ST* pst);
// ��ȡ���ݸ���
int STSize(ST* pst);

// ��ʼ��������
void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	// topָ��ջ�����ݵ���һ��λ��
	pst->top = 0;

	// topָ��ջ������
	//pst->top = -1;

	pst->capacity = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

// ��ջ  ��ջ
void STPush(ST* pst, STDataType x)
{
	assert(pst);

	// ����
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	pst->top--;
}

// 20:08����
// ȡջ������
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	return pst->a[pst->top - 1];
}

// �п�
bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

// ��ȡ���ݸ���
int STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}

typedef struct {
	ST pushst;
	ST popst;
} MyQueue;

MyQueue* myQueueCreate() {
	MyQueue* pst = (MyQueue*)malloc(sizeof(MyQueue));
	if (pst)
	{
		perror("malloc()::fail");
		return 1;
	}
	STInit(&(pst->pushst));
	STInit(&(pst->popst));

	return pst;
}

void myQueuePush(MyQueue* obj, int x) {
	STPush(&(obj->pushst), x);
}

int myQueuePop(MyQueue* obj) {
	int cmp = myQueuePeek(obj);
	STPop(&(obj->popst));

	return cmp;
}

int myQueuePeek(MyQueue* obj) {
	if (STEmpty(&(obj->popst)))
	{
		while (!STEmpty(&(obj->pushst)))
		{
			int top = STTop(&(obj->pushst));
			STPush(&(obj->popst), top);
			STPop(&(obj->pushst));
		}
	}
	return STTop(&(obj->popst));
}

bool myQueueEmpty(MyQueue* obj) {
	return STEmpty(&(obj->pushst)) && STEmpty(&(obj->popst));
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&(obj->pushst));
	STDestroy(&(obj->popst));

	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/