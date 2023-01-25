#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

//free
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

//队尾入
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode* )malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

//对头出
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	//如果只有一节点，next就指向野指针
	//一个和多个节点
	if (pq->head->next==NULL)
	{
		free(pq -> head);
		pq->head =pq->tail= NULL;
	}
	else
	{
		Queue* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head ->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}

int	QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}