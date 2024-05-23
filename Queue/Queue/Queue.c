#define _CRT_SECURE_NO_WANINGS 1

#include "Queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);

	q->_phead = q->_ptail = NULL;
	q->_size = 0;
}

// ��β����� 
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

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_size > 0);
	
	/*QNode* next = q->_phead->_next;

	free(q->_phead);
	q->_phead = next;

	if (q->_ptail == NULL)
		q->_ptail = NULL;*/

	if (q->_size == 1) // ֻ��һ���ڵ�
	{
		free(q->_phead);
		q->_ptail = q->_phead = NULL;
	}
	else // ����ڵ�
	{
		QNode* next = q->_phead->_next;
		free(q->_phead);
		q->_phead = next;
	}
	q->_size--;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_size > 0);

	return q->_phead->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_size > 0);

	return q->_ptail->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);

	return q->_size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_size == 0;
}

// ���ٶ��� 
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