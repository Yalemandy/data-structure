#define _CRT_SECURE_NO_WANINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef char StackDataType;

typedef struct stack {
    StackDataType* a;
    int size;
    int capacity;
} Stack;

void checkCapacity(Stack* pst) {
    assert(pst);
    if (pst->capacity == pst->size) {
        int newnode = pst->capacity == 0 ? 4 : pst->capacity * 2;
        StackDataType* newa = (StackDataType*)realloc(pst, sizeof(StackDataType) * newnode);
        if (newa == NULL) {
            perror("realloc fail!");
            return;
        }
        pst->a = newa;
        pst->capacity = newnode;
    }
}

void stackInit(Stack* pst) {
    pst->a = NULL;
    pst->capacity = 0;
    pst->size = 0;
}

void stackDestroy(Stack* pst) {
    assert(pst);
    free(pst->a);
    pst->capacity = pst->size = 0;
}

int stackIsEmpty(Stack* pst) {
    assert(pst);

    return pst->size == 0;
}

void stackPush(Stack* pst, StackDataType x) {
    assert(pst);

    checkCapacity(pst);

    pst->a[pst->size++] = x;
}

void stackPop(Stack* pst) {
    assert(pst);
    assert(pst->size > 0);

    pst->size--;

}

StackDataType stackTop(Stack* pst) {
    assert(pst);
    assert(pst->size > 0);


    return pst->a[pst->size - 1];
}

int stackSize(Stack* pst) {
    assert(pst);

    return pst->size;
}

bool isValid(char* s) {
    // write code here

    Stack st;
    stackInit(&st);
    while (*s != '\0')
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            stackPush(&st, *s);
        }
        else
        {
            StackDataType x = stackTop(&st);
            if (x == '(' && *s != ')' ||
                x == '[' && *s != ']' ||
                x == '{' && *s != '}')
                return false;
        }
        s++;
    }
    if (stackIsEmpty(&st))
        return true;
    else
        return false;
}


int main()
{
    char s[] = { '[','[','[','{','(','(',')',')' ,'}',']',']' ,']' };
    if (isValid(s))
        printf("true");
    else
        printf("false");
    return 0;
}