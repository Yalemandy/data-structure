#define _CRT_SECURE_NO_WANINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

// 队尾插入
void QueuePush(Queue* pq, QDataType x);
// 队头删除
void QueuePop(Queue* pq);

// 取队头和队尾的数据
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);

		cur = next;
	}

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

// 队尾插入
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}

	newnode->next = NULL;
	newnode->val = x;

	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}

	pq->size++;
}

// 队头删除
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size != 0);

	/*QNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;

	if (pq->phead == NULL)
		pq->ptail = NULL;*/

		// 一个节点
	if (pq->phead->next == NULL)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else // 多个节点
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}

	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	return pq->phead->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);

	return pq->ptail->val;
}


int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->size == 0;
}

typedef struct {
	Queue p1;
	Queue p2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* cur = (MyStack*)malloc(sizeof(MyStack));
	if (cur == NULL)
	{
		perror("malloc()::fail");
		exit(-1);
	}
	QueueInit(&(cur->p1));
	QueueInit(&(cur->p2));
	return cur;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&(obj->p1)))
	{
		QueuePush(&(obj->p1), x);
	}
	else
	{
		QueuePush(&(obj->p2), x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* empty = &(obj->p1);
	Queue* noempty = &(obj->p2);
	if (!QueueEmpty(&(obj->p1)))
	{
		noempty = &(obj->p1);
		empty = &(obj->p2);
	}

	while (QueueSize(noempty) > 1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}

	int top = QueueFront(noempty);
	QueuePop(noempty);

	return top;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&(obj->p1)))
	{
		return QueueBack(&(obj->p1));
	}
	else
	{
		return QueueBack(&(obj->p2));
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&(obj->p1)) && QueueEmpty(&(obj->p2));
}

void myStackFree(MyStack* obj) {

	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/