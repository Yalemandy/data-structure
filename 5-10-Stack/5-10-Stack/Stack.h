#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int SDataType;

typedef struct Stack
{
	SDataType* _a;
	int _top;
	int _capacity;
}Stack;

// ��ʼ��ջ
void StackInit(Stack* ps);

// ����ջ
void StackDestroy(Stack* ps);

// ��ջ
void StackPush(Stack* ps, SDataType data);

// ��ջ
void StackPop(Stack* ps);

// ����ջ����Ч����
void StackSize(Stack* ps);

// ��ȡջ��Ԫ��
void StackTop(Stack* ps);

// �п�
void StackEmpty(Stack* ps);