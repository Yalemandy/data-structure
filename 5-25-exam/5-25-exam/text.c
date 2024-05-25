#define _CRT_SECURE_NO_WANINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>


struct ListNode
{
    int val;
    struct ListNode* next;
};

int runtrun(int n)
{
    int m = n;
    int count = 0;
    while (m)
    {
        m /= 10;
        count++;
    }
    int number = 0;
    while (count)
    {
        number += n % 10 * pow(10, count-1);
        n /= 10;
        count--;
    }
    return number;
}

bool chkPalindrome(struct ListNode* A) {
    struct ListNode* tmp = A;
    int i = 1;
    int sum = 0;
    while (tmp)
    {
        sum += tmp->val * i;
        i *= 10;
        tmp = tmp->next;
    }

    int num = runtrun(sum);
    if (num == sum)
        return true;
    else
        return false;

}


struct ListNode* dsjadjl(int x)
{
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (l1 == NULL)
    {
        perror("");
        exit(-1);
    }
    l1->val = x;
    l1->next = 0;

    return l1;
}

int main()
{

    struct ListNode* l1 = dsjadjl(1);
    struct ListNode* l2 = dsjadjl(2);
    struct ListNode* l3 = dsjadjl(3);


    struct ListNode* head = l1;
    l1->next = l2;
    l2->next = l3;
    if (chkPalindrome(head))
        printf("true");
    else
        printf("false");

    return 0;
}