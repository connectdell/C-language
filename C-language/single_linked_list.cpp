#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct LNode
{
	char data;
	struct LNode* next;
} LNode, * LinkList;
Status CreateList_LinkList(LinkList& L, int n)
{
	int i;
	L = new LNode;
	L->next = NULL;
	for (i = 0; i < n; ++i)
	{
		LinkList p = new LNode;
		std::cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
	return 0;
}
Status ListInsert_LinkList(LinkList& L, int i, int e)
{
	LinkList p = L;
	int j = 0;
	while (p && (j < i - 1))
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	LinkList s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete_LinkList(LinkList& L, int i)
{
	LinkList p = L;
	int j = 0;
	while ((p->next) && (j < i - 1))
	{
		p = p->next;
		++j;
	}
	LinkList q;
	q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
Status GetElem_LinkList(LinkList L, int i, char& e)
{
	LinkList p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;
}
Status ListTravel_LinkList(LinkList L)
{
	LNode* p = L->next;
	while (p != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	return 0;
}
Status MergeList_LinkList(LinkList& L1, LinkList& L2, LinkList& L3)
{
	LNode* p = L1->next;
	LNode* q = L2->next;
	L3 = new LNode;
	L3->next = NULL;
	LNode* r = L3;
	while (p && q)
	{
		if (p->data <= q->data)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = q;
			q = q->next;
		}
	}
	r->next = p ? p : q;
	return OK;
}
int main()
{
	int i;
	char n = 0;
	LinkList mylist1, mylist2;
	printf("第一个\n请输入5个字符（不需要空格间隔，回车两次确认）：\n");
	CreateList_LinkList(mylist1, 5);
	while (getchar() != '\n')
		; // 清空缓冲区
	printf("链表内容为 \n");
	ListTravel_LinkList(mylist1);
	printf("\n\n请输入插入的字符: ");
	scanf_s("%c", &n);
	printf("输入插入的位置: ");
	scanf_s("%d", &i);
	ListInsert_LinkList(mylist1, i, n);
	printf("\n插入一个字符%c后，链表的内容为: \n", n);
	ListTravel_LinkList(mylist1);
	printf("\n\n要删除第几个字符?: ");
	scanf_s("%d", &i);
	ListDelete_LinkList(mylist1, i);
	printf("删除第%d个元素后,链表的内容为: \n", i);
	ListTravel_LinkList(mylist1);
	printf("\n\n");
	printf("\n\n要查询第几个字符: ");
	scanf_s("%d", &i);
	GetElem_LinkList(mylist1, i, n);
	printf("单链表的第%d个字符是%c。\n", i, n);
	return 0;
}