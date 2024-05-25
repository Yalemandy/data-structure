#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef int StackDataType;

typedef struct stack
{
	StackDataType* a;
	int size;
	int capacity;
}Stack;

void stackInit(Stack* pst);	
void stackDestroy(Stack* pst);
// ≈–∂œ «∑Ò–Ë“™¿©»›
void checkCapacity(Stack* pst);
int stackIsEmpty(Stack* pst);
void stackPush(Stack* pst, StackDataType x);
void stackPop(Stack* pst);
StackDataType stackTop(Stack* pst);
int stackSize(Stack* pst);