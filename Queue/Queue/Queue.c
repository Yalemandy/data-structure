#define _CRT_SECURE_NO_WANINGS 1

#include "Queue.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);

	q->_phead = q->_ptail = NULL;
	q->_size = 0;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("QueuePush()::malloc()");
		return;
	}
	newnode->_next = NULL;
	newnode->_data = data;

	if (q->_size)
	{
		q->_ptail = q->_phead = newnode;
	}
	else
	{
		q->_ptail->_next = newnode;
		q->_ptail = newnode;
	}

	q->_size++;
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_size > 0);
	
	/*QNode* next = q->_phead->_next;

	free(q->_phead);
	q->_phead = next;

	if (q->_ptail == NULL)
		q->_ptail = NULL;*/

	if (q->_size == 1) // 只有一个节点
	{
		free(q->_phead);
		q->_ptail = q->_phead = NULL;
	}
	else // 多个节点
	{
		QNode* next = q->_phead->_next;
		free(q->_phead);
		q->_phead = next;
	}
	q->_size--;
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_size > 0);

	return q->_phead->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_size > 0);

	return q->_ptail->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);

	return q->_size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_size == 0;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	
	QNode* cur = q->_phead;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_phead = q->_ptail = NULL;
	q->_size = 0;
}