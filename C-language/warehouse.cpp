#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;
typedef struct
{
	char* base;
	char* top;
	int stacksize;
}SqStack;
Status InitStack(SqStack& S)
{
	S.base = new  char[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, char  e)
{
	if (S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;
}
Status PoP(SqStack& S, int& e)
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
char GetTop(SqStack S)
{
	if (S.top != S.base)
		return *(S.top - 1);
}
Status StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return OK;
	else
		return ERROR;
}
void conversion(int N)
{
	int e;
	SqStack S;
	InitStack(S);
	while (N)
	{
		Push(S, N % 8);
		N = N / 8;
	}
	while (!StackEmpty(S))
	{
		PoP(S, e);
		std::cout << e;
	}
}
int main()
{
	int j, m;
	char* i;
	char n;
	int s;
	SqStack myStack;
	InitStack(myStack);
	printf("请输入您想输入的字符：");
	scanf_s("%c", &n);
	while (n != 10)
	{
		Push(myStack, n);
		scanf_s("%c", &n);
	}
	printf("栈的长度为：%d\n", (myStack.top - myStack.base));
	printf("栈的内容为：\n");
	for (i = myStack.top - 1; i >= myStack.base; i--)
		printf("%c\n", *i);
	printf("\n");
	printf("输入需要出栈元素的个数：\n");
	scanf_s("%d", &j);
	if (j > (myStack.top - myStack.base))
		printf("出栈元素的个数不能大于栈的长度!");
	else
	{
		printf("目前出栈的元素是: \n");
		for (m = 1; m <= j; m++)
		{
			PoP(myStack, s);
			printf("\n%c", s);
		}
		printf("\n");
		printf("栈的长度为：%d\n", (myStack.top - myStack.base));
		printf("栈的内容为: \n");
		for (i = myStack.top - 1; i >= myStack.base; i--)
			printf("%c\n", *i);
	}
	int x;
	printf("请输入一个十进制的数 \n");
	scanf_s("%d", &x);
	printf("十进制数%d的八进制转换结果为", x);
	conversion(x);
}