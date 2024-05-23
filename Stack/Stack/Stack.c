#define _CRT_SECURE_NO_WANINGS 1

#include "Stack.h"

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	if (ps->_capacity == ps->_top)
	{
		int _newsize = ps->_capacity == 0 ? 4 : ps->_capacity * 2; // �������¿ռ�
		STDataType* _newdata = (STDataType*)realloc(ps, _newsize * sizeof(STDataType));

		if (_newdata == NULL)
		{
			perror("StackPush()::realloc()");
			return;
		}

		ps->_a = _newdata;
		ps->_capacity = _newsize;
	}

	ps->_a[ps->_top] = data;

}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	ps->_top--;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0;
}