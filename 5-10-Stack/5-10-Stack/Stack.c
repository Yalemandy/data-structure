#define _CRT_SECURE_NO_WANINGS 1

#include "Stack.h"

// ��ʼ��
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
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	 
	if (ps->_top == ps->_capacity)
	{
		int _newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		SDataType* _new_a = (SDataType*)realloc(ps, _newcapacity * sizeof(SDataType));
		if (_new_a == NULL)
		{
			perror("StackPush()::realloc()");
			exit(-1);
		}
		ps->_a = _new_a;
		ps->_capacity = _newcapacity;
	}
	ps->_a[ps->_top++] = data;
}

// ��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	ps->_top--;
}

// ����ջ����Ч����
void StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

// ��ȡջ��Ԫ��
void StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	return ps->_a[ps->_top - 1];
}

// �п�
void StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0;
}