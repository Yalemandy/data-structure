#define _CRT_SECURE_NO_WANINGS 1

#include"SeqList.h"

//顺序表的初始化
void SLInit(SList* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}


//顺序表的销毁
void SLDestroy(SList* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

//顺序表的打印
void SLPrint(SList ps)
{
	for (int i = 0; i < ps.size; i++)
	{
		printf("%d ", ps.arr[i]);
	}
	printf("\n");
}

//顺序表的扩容
void SLCheck(SList* ps)
{
	if (ps->capacity == ps->size) // 相同需要扩容，且以二倍的形式来扩容
	{
		int newSListnode = ps->capacity == 0 ? 4 : (ps->capacity) * 2;
		SLTDataType* cmp = (SLTDataType*)realloc(ps->arr, newSListnode * sizeof(SLTDataType));
		if (cmp == NULL)
		{
			perror("SLCheck()::realloc()");
			return;
		}
		ps->arr = cmp;
		ps->capacity = newSListnode;
	}
}

//顺序表的头插
void SLPushFront(SList* ps, SLTDataType x)
{
	SLCheck(ps);
	assert(ps->arr);
	//头插需要把内存中的所有数据都往后移动一位
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//顺序表的尾插
void SLPushBack(SList* ps, SLTDataType x)
{
	SLCheck(ps);
	assert(ps->arr);
	ps->arr[ps->size++] = x;
}

//顺序表的头删
void SLDelFront(SList* ps)
{
	assert(ps && ps->size);
	//直接把后面的所有数都往前移动一位，不会影响数据的增删改查
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//顺序表的尾删
void SLDelBack(SList* ps)
{
	//直接把有效数减一,不会影响数据的增删改查
	assert(ps && ps->size);
	ps->size--;
}


//顺序表指定位置之前插入数据
void SLInsert(SList* ps, int pos, SLTDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	SLCheck(ps);

	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

//顺序表指定删除数据
void SLErase(SList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}


//顺序表的查找
int SLFind(SList* ps, SLTDataType pos)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (pos == ps->arr[i])
		{
			return i;
		}
	}
	return -1;
}