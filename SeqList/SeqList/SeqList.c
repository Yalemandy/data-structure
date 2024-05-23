#define _CRT_SECURE_NO_WANINGS 1

#include"SeqList.h"

//˳���ĳ�ʼ��
void SLInit(SList* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}


//˳��������
void SLDestroy(SList* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

//˳���Ĵ�ӡ
void SLPrint(SList ps)
{
	for (int i = 0; i < ps.size; i++)
	{
		printf("%d ", ps.arr[i]);
	}
	printf("\n");
}

//˳��������
void SLCheck(SList* ps)
{
	if (ps->capacity == ps->size) // ��ͬ��Ҫ���ݣ����Զ�������ʽ������
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

//˳����ͷ��
void SLPushFront(SList* ps, SLTDataType x)
{
	SLCheck(ps);
	assert(ps->arr);
	//ͷ����Ҫ���ڴ��е��������ݶ������ƶ�һλ
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//˳����β��
void SLPushBack(SList* ps, SLTDataType x)
{
	SLCheck(ps);
	assert(ps->arr);
	ps->arr[ps->size++] = x;
}

//˳����ͷɾ
void SLDelFront(SList* ps)
{
	assert(ps && ps->size);
	//ֱ�ӰѺ��������������ǰ�ƶ�һλ������Ӱ�����ݵ���ɾ�Ĳ�
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//˳����βɾ
void SLDelBack(SList* ps)
{
	//ֱ�Ӱ���Ч����һ,����Ӱ�����ݵ���ɾ�Ĳ�
	assert(ps && ps->size);
	ps->size--;
}


//˳���ָ��λ��֮ǰ��������
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

//˳���ָ��ɾ������
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


//˳���Ĳ���
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