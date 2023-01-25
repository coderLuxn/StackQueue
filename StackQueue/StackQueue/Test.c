#define _CRT_SECURE_NO_WARNINGS

//#include "Stack.h"
//int main()
//{
//	ST st;
//	StackInit(&st);
//	
//	StackPush(&st, 1);
//	printf("%d ", StackSize(&st));
//	StackPush(&st, 2);
//	printf("%d ", StackTop(&st));
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	
//	StackPush(&st, 5);
//	
//	while (!StackEmpty(&st))
//	{
//		printf("%d ", StackTop(&st));
//		StackPop(&st);
//	}
//	
//	StackDestory(&st);
//	return 0;
//}


#include "Queue.h"


void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);
}

int main()
{
	TestQueue();
	return 0;
}