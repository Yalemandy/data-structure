#define _CRT_SECURE_NO_WANINGS 1

//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//typedef int StackDataType;
//
//typedef struct stack {
//    StackDataType a;
//    struct stack* next;
//} LN;
//
//LN* ReverseList(LN* head) {
//    // write code here
//
//    LN* tmp = head;
//    LN* cmp = NULL;
//    LN* prev = NULL;
//
//    while (tmp != NULL)
//    {
//        cmp = tmp->next;
//        prev = tmp;
//        cmp->next = prev;
//        tmp = cmp;
//    }
//
//    return cmp;
//}
//
//LN* dsjadjl(int x)
//{
//    LN* l1 = (LN*)malloc(sizeof(LN));
//    if (l1 == NULL)
//    {
//        perror("");
//        exit(-1);
//    }
//    l1->a = x;
//    l1->next = 0;
//
//    return l1;
//}
//
//int main()
//{
//
//    LN* l1 = dsjadjl(1);
//    LN* l2 = dsjadjl(2);
//    LN* l3 = dsjadjl(3);
//
//
//    LN* head = l1;
//    l1->next = l2;
//    l2->next = l3;
//    LN* node = ReverseList(head);
//
//    return 0;
//}
//




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
        int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
        StackDataType* newa = (StackDataType*)realloc(pst->a,sizeof(StackDataType) * newcapacity);
        if (newa == NULL) {
            perror("realloc fail!");
            return;
        }
        pst->a = newa;
        pst->capacity = newcapacity;
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

    pst->a[pst->size] = x;
    pst->size++;
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
    while (*s != '\0') {
        if (*s == '(' || *s == '[' || *s == '{') {
            stackPush(&st, *s);
        }
        else {
			if (stackIsEmpty(&st))
				return false;

            StackDataType x = stackTop(&st);
			stackPop(pst);
            if ((x == '(' && *s != ')') ||
                (x == '[' && *s != ']') ||
                (x == '{' && *s != '}'))
                return false;
        }
        s++;
    }
    if (stackIsEmpty(&st))
        return true;
    else
        return false;
}
