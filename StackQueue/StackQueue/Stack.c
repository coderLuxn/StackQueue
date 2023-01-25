#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

//��ʼ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = malloc(sizeof(STDataType) * 4); //���ĸ��ռ�
	if (ps->a == NULL)
	{
		printf("realloc fail\n");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = 4;
}

//free
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

//��ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	//���� ����
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//��ջ
void StackPop(ST* ps)
{
	assert(ps);
	//ջ���ˣ�����top,ֱ����ֹ���򱨴�
	assert(ps->top > 0);
	//ps->a[ps->top-1]=0; �п���ԭ�������ݾ���0������ѧ
	ps->top--;
}

//ȡջ��������
STDataType StackTop(ST* ps)
{
	assert(ps);
	//ջ���ˣ�����top,ֱ����ֹ���򱨴�
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

//ջ���ݵĸ���
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0; 
}