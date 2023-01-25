#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

//初始化
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = malloc(sizeof(STDataType) * 4); //给四个空间
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

//入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	//满了 增容
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

//出栈
void StackPop(ST* ps)
{
	assert(ps);
	//栈空了，调用top,直接中止程序报错
	assert(ps->top > 0);
	//ps->a[ps->top-1]=0; 有可能原来的数据就是0，不科学
	ps->top--;
}

//取栈顶的数据
STDataType StackTop(ST* ps)
{
	assert(ps);
	//栈空了，调用top,直接中止程序报错
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

//栈数据的个数
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

//判断栈是否为空
int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0; 
}