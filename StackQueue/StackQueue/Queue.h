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

//初始化
void QueueInit(Queue* pq);
//free
void QueueDestory(Queue* pq);
//队尾入
void QueuePush(Queue* pq, QDataType x);
//对头出
void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int	QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);