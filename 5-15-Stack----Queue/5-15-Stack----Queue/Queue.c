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

// 初始化和销毁
void STInit(ST* pst);
void STDestroy(ST* pst);

// 入栈  出栈
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

// 取栈顶数据
STDataType STTop(ST* pst);

// 判空
bool STEmpty(ST* pst);
// 获取数据个数
int STSize(ST* pst);

// 初始化和销毁
void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	// top指向栈顶数据的下一个位置
	pst->top = 0;

	// top指向栈顶数据
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

// 入栈  出栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);

	// 扩容
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

// 20:08继续
// 取栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	return pst->a[pst->top - 1];
}

// 判空
bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

// 获取数据个数
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