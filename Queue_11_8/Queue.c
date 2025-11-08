#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* pcur = pq->phead;
	while (pcur)
	{
		QNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(newnode, sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc failed!");
		exit(1);
	}
	newnode->next = NULL;
	newnode->val = x;
	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	pq->ptail->next = newnode;
	pq->ptail = newnode;
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size > 0);
	if (pq->ptail->next == NULL)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	QNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->size > 0);
	return pq->phead->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->size > 0);
	return pq->ptail->val;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}