#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct QueueNode QNode;
 
 struct QueueNode 
{
	QNode* next;
	QDataType data;
};

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//free
void QueueDestory(Queue* pq);
//��β��
void QueuePush(Queue* pq, QDataType x);
//��ͷ��
void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int	QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);