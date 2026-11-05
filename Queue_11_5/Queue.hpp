#pragma once
#include <cassert>

typedef int QDataType;

struct QNode
{
    QNode *next;
    QDataType data;
};

struct Queue
{
    QNode *phead;
    QNode *ptail;
    int size;
};

void QueueInit(Queue &q);

void QueuePush(Queue &q, QDataType x);

void QueuePop(Queue &q);

QDataType QueueFront(const Queue &q);

QDataType QueueBack(const Queue &q);

int QueueSize(const Queue &q);

bool QueueEmpty(const Queue &q);