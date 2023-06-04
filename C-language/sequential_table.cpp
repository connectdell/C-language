#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSIZE 100
typedef struct
{
	int* elem;
	int length;
} SqList;
Status InitList_SqList(SqList& L)
{
	L.elem = new int[MAXSIZE];
	if (!L.elem)
		return (OVERFLOW);
	L.length = 0;
	return OK;
}
Status ListInsert_SqList(SqList& L, int i, int e)
{
	int j;
	if ((i < 1) || (i > L.length + 1))
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}
Status ListDelete_SqList(SqList& L, int i)
{
	int j;
	if ((i < 1) || (i > L.length + 1))
		return ERROR;
	for (j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return OK;
}
Status ListGetElem_SqList(SqList L, int i, int* e)
{
	if ((i < 1) || (i > L.length))
		return ERROR;
	*e = L.elem[i - 1];
	return OK;
}
Status LocateElem_SqList(SqList L, int e)
{
	int i;
	for (i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;
	return 0;
}
void MergeList_SqList(SqList L1, SqList L2, SqList& L3)
{
	int* p1, * p2, * p3, * p1_last, * p2_last;
	L3.length = L1.length + L2.length;
	L3.elem = new int[L3.length];
	p3 = L3.elem;
	p1 = L1.elem;
	p2 = L2.elem;
	p1_last = L1.elem + L1.length - 1;
	p2_last = L2.elem + L2.length - 1;
	while ((p1 <= p1_last) && (p2 <= p2_last))
	{
		if (*p1 <= *p2)
			*p3++ = *p1++;
		else
			*p3++ = *p2++;
	}
	while (p1 <= p1_last)
		*p3++ = *p1++;
	while (p2 <= p2_last)
		*p3++ = *p2++;
}
int main()
{
	int n, x, i, j, e;
	printf("第一个顺序表:\n");
	SqList mylist1;
	InitList_SqList(mylist1);
	printf("准备输入多少个数据?:");
	scanf_s("%d", &n);
	printf("开始输入%d个数据:\n", n);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &x);
		ListInsert_SqList(mylist1, i, x);
	}
	printf("\n顺序表的长度为:%d \n", mylist1.length);
	printf("顺序表内容为: \n");
	for (j = 0; j < mylist1.length; j++)
		printf("%d \n", mylist1.elem[j]);
	printf("\n准备插入新元素，请输入新元素的值: ");
	scanf_s("%d", &x);
	printf("输入插入的位置: ");
	scanf_s("%d", &i);
	ListInsert_SqList(mylist1, i, x);
	printf("\n插入完成后，顺序表的长度为:%d \n", mylist1.length);
	printf("顺序表内容为: \n");
	for (j = 0; j < mylist1.length; j++)
		printf("%d \n", mylist1.elem[j]);
	printf("\n即将删除1个元素，请输入元素的序列号: ");
	scanf_s("%d", &i);
	ListDelete_SqList(mylist1, i);
	printf("\n删除完成后，序列表的长度为:%d \n ", mylist1.length);
	printf("顺序表内容为:\n");
	for (j = 0; j < mylist1.length; j++)
		printf("%d \n", mylist1.elem[j]);
	printf("输入要查询的顺序: ");
	scanf_s("%d", &i);
	if (ListGetElem_SqList(mylist1, i, &e) == OK)
		printf("第%d个元素为:%d\n", i, e);
	else
		printf("输入顺序有误\n");
	printf("输入要查询的元素: ");
	scanf_s("%d", &x);
	i = LocateElem_SqList(mylist1, x);
	if (i)
		printf("元素%d的位置为:%d\n", x, i);
	else
		printf("未找到元素%d\n", x);
	return 0;
}