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

// 初始化栈
void StackInit(Stack* ps);

// 销毁栈
void StackDestroy(Stack* ps);

// 入栈
void StackPush(Stack* ps, SDataType data);

// 出栈
void StackPop(Stack* ps);

// 计算栈内有效个数
void StackSize(Stack* ps);

// 获取栈顶元素
void StackTop(Stack* ps);

// 判空
void StackEmpty(Stack* ps);