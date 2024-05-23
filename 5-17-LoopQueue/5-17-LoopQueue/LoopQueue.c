#define _CRT_SECURE_NO_WANINGS 1


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int* _a;
    int head;
    int tail;
    int k;
} MyCircularQueue;


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->head == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail + 1) % (obj->k + 1) == obj->head;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* pst = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (pst == NULL) {
        perror("pst malloc fail!");
        exit(-1);
    }
    pst->_a = (int*)malloc(sizeof(int) * (k + 1));
    if (pst->_a == NULL) {
        perror("pst->_a malloc fail!");
        exit(-1);
    }
    pst->head = 0;
    pst->tail = 0;

    pst->k = k;
    return pst;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    obj->_a[obj->tail] = value;
    obj->tail++;
    obj->tail %= (obj->k + 1);

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;

    ++obj->head;
    obj->head %= (obj->k + 1);

    return true;

    // if(myCircularQueueIsEmpty(obj))
    // {
    //     return false;
    // }
    // else
    // {
    //     obj->tail = (obj->tail - obj->K) % (obj->k+1);
    // }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    else {
        return obj->_a[obj->head];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    else {
        return obj->_a[(obj->tail + obj->k) % (obj->k + 1)];
    }
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:

 * MyCircularQueue* obj = myCircularQueueCreate(k);

 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/