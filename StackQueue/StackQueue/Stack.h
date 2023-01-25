#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//初始化
void StackInit(ST* ps);
//free
void StackDestory(ST* ps);
//入栈
void StackPush(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);
//取栈顶的数据
STDataType StackTop(ST* ps);
//栈数据的个数
int StackSize(ST* ps);
//判断栈是否为空
int StackEmpty(ST* ps);