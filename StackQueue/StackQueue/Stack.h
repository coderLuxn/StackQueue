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

//��ʼ��
void StackInit(ST* ps);
//free
void StackDestory(ST* ps);
//��ջ
void StackPush(ST* ps, STDataType x);
//��ջ
void StackPop(ST* ps);
//ȡջ��������
STDataType StackTop(ST* ps);
//ջ���ݵĸ���
int StackSize(ST* ps);
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(ST* ps);