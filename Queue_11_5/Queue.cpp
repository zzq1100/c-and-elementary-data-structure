#include "Queue.hpp"

#include <iostream>

void QueueInit(Queue &q)
{
    q.phead = q.ptail = nullptr;
    q.size = 0;
}

void QueuePush(Queue &q, QDataType x)
{
    // new 只需要类型名，sizeof 是 malloc 时代的写法，放进去会被当成构造函数参数
    QNode *newnode = new QNode{nullptr, x};   // 按成员声明顺序：next, data

    if (q.phead == nullptr)
    {
        q.phead = q.ptail = newnode;
    }
    else
    {
        q.ptail->next = newnode;
        q.ptail = newnode;
    }
    ++q.size;
}

void QueuePop(Queue &q)
{
    assert(q.phead != nullptr);

    QNode *cur = q.phead->next;
    delete q.phead;
    q.phead = cur;

    // 关键：删掉最后一个结点后队列变空，ptail 必须一起置空，
    // 否则它指向已释放内存，QueueBack 之类的接口会变成悬垂读取
    if (q.phead == nullptr)
        q.ptail = nullptr;

    --q.size;
}

QDataType QueueFront(const Queue &q)
{
    assert(q.phead != nullptr);
    return q.phead->data;
}

QDataType QueueBack(const Queue &q)
{
    assert(q.ptail != nullptr);
    return q.ptail->data;
}

int QueueSize(const Queue &q)
{
    return q.size;
}

bool QueueEmpty(const Queue &q)
{
    return q.size == 0;
}
