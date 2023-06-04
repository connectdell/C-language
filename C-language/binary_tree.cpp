#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct BiTNode
{
    char data;
    struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;
void CreateBiTree(BiTree& T)
{
    char ch;
    std::cin >> ch;
    if (ch == '#') {
        T = NULL;
        return;
    }
    else
    {
        T = new BiTNode;
        if (T == NULL) return;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        std::cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void InOrderTraverse(BiTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        std::cout << T->data;
        InOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        std::cout << T->data;
    }
}
int NodeCount(BiTree T)
{
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
int LeafCount(BiTree T) {
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    return LeafCount(T->lchild) + LeafCount(T->rchild);
}
int main()
{
    BiTree root = NULL;
    printf("准备以先序方式创建二叉树...，\n请输入各节点数据（如果没有左、右孩子，输入#）:\n");
    CreateBiTree(root);
    printf("\n先序遍历的结果: ");
    PreOrderTraverse(root);
    printf("\n中序遍历的结果: ");
    InOrderTraverse(root);
    printf("\n后续遍历的结果: ");
    PostOrderTraverse(root);
    printf("\n");
    printf("\n该树共有%d个结点。\n", NodeCount(root));
    printf("\n该树共有%d个叶子。\n", LeafCount(root));
    return 0;
}
