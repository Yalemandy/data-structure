#define _CRT_SECURE_NO_WANINGS 1



#include "Stack.h"

// ÅÐ¶ÏÊÇ·ñÐèÒªÀ©ÈÝ
void checkCapacity(Stack* pst)
{
	assert(pst);
	if (pst->capacity == pst->size)
	{
		int newnode = pst->capacity == 0 ? 4 : pst->capacity * 2;
		StackDataType* newa = (StackDataType*)realloc(pst, newnode * sizeof(StackDataType));
		if (newa == NULL)
		{
			perror("realloc fail!");
			return;
		}
		pst->a = newa;
		pst->capacity = newnode;
	}
}

void stackInit(Stack* pst)
{
	StackDataType* node = (StackDataType*)malloc(sizeof(StackDataType));
	if (node == NULL)
	{
		perror("malloc fail");
		return;
	}
	pst->a = node;
	pst->capacity = 0;
	pst->size = 0;
}

void stackDestroy(Stack* pst)
{
	assert(pst);
	free(pst);

	pst->capacity = 0;
	pst->size = 0;
}

int stackIsEmpty(Stack* pst)
{
	assert(pst);

	return pst->size == 0;
}

void stackPush(Stack* pst, StackDataType x)
{
	assert(pst);

	checkCapacity(pst);

	pst->a[pst->size++] = x;
}

void stackPop(Stack* pst)
{
	assert(pst);
	assert(pst->size > 0);

	pst->size--;

}

StackDataType stackTop(Stack* pst)
{
	assert(pst);
	assert(pst->size > 0);


	return pst->a[pst->size - 1];
}

int stackSize(Stack* pst)
{
	assert(pst);

	return pst->size;
}