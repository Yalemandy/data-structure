#define _CRT_SECURE_NO_WANINGS 1

#include "Stack.h"

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	if (ps->_capacity == ps->_top)
	{
		int _newsize = ps->_capacity == 0 ? 4 : ps->_capacity * 2; // 创建的新空间
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

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	ps->_top--;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);

	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0;
}