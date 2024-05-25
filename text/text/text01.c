#define _CRT_SECURE_NO_WANINGS 1

typedef struct ListNode LN;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int StackDataType;

typedef struct stack {
    StackDataType a;
    struct stack* next;
} LN;

struct ListNode* ReverseList(struct ListNode* head) {
    // write code here

    LN* tmp = head;
    LN* cmp = NULL;
    LN* prev = NULL;

    while (tmp != NULL)
    {
        cmp = tmp->next;

        cmp->next = prev;

        prev = tmp;

        tmp = cmp;
    }

    return cmp;
}

LN* dsjadjl(int x)
{
    LN* l1 = (LN*)malloc(sizeof(LN));
    if (l1 == NULL)
    {
        perror("");
        exit(-1);
    }
    l1->a = x;
    l1->next = 0;

    return l1;
}

int main()
{

    LN* l1 = dsjadjl(1);
    LN* l2 = dsjadjl(2);
    LN* l3 = dsjadjl(3);


    struct ListNode* head = l1;
    l1->next = l2;
    l2->next = l3;
    LN* node = ReverseList(head);

    return 0;
}

