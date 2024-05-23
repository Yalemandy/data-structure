#define _CRT_SECURE_NO_WANINGS 1

#include "Heap.h"

// 堆的初始化
void HeapInit(Heap* hp)
{
	assert(hp);

	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);

	free(hp->_a);
	hp->_a = NULL;

	hp->_capacity = hp->_size = 0;
}

void swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

// 向上调整
void AdjustUp(HPDataType* a,int child)
{
	int child_father = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child_father] > a[child])
		{
			swap(&a[child] ,&a[child_father]);
			child = child_father;
			child_father = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	if (hp->_capacity == hp->_size)
	{
		int newnum = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* newheap = (HPDataType*)realloc(hp->_a, newnum * sizeof(HPDataType));
		if (newheap == NULL)
		{
			perror("HeapPush()::malloc() fail!!");
			return;
		}

		hp->_a = newheap;
		hp->_capacity = newnum;
	}
	hp->_a[hp->_size++] = x;

	AdjustUp(hp->_a, hp->_size - 1);
}

// 向下调整
void AdjustDown(HPDataType* a, int n,int head)
{
	int child = head * 2 + 1;
	while (child < n)
	{
		if (a[child] > a[child + 1] && child + 1 < n)
		{
			child += 1;
		}
		if (a[child] < a[head])
		{
			swap(&a[child], &a[head]);
			head = child;
			child = head * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	swap(&hp->_a[hp->_size - 1], &hp->_a[0]);
	
	hp->_size--;

	AdjustDown(hp->_a, hp->_size, 0);

}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);

	return hp->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->_size;
}

// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->_size == 0;
}

