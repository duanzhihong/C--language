//采用递归实现对二叉树的遍历
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TElemType int
//       1
//   2       3
// 4   5   6   7 

//构造节点
typedef struct BiTNode{
    TElemType data;//数据域
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree *T);
void displayElem(BiTNode *elem);
void PreOrderTraverse(BiTree T);
void INOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
int main(void) {
    BiTree  tree;
    //创建树
    CreateBiTree(&tree);
    PreOrderTraverse(tree);
    printf("\n");
    INOrderTraverse(tree);
    printf("\n");
    PostOrderTraverse(tree);
    printf("\n");
    return 0;
}

//创建树
void CreateBiTree(BiTree *T) {
    //创建根节点
    (*T) = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = 1;

    (*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;

    (*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->data = 3;

    (*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;

    (*T)->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;

    (*T)->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;


    (*T)->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;   
    (*T)->rchild->rchild->lchild = NULL;   
    (*T)->rchild->rchild->rchild = NULL;   

}

//打印节点值
void displayElem(BiTNode *elem){
    printf("%d", elem->data);
}

//先序
void PreOrderTraverse(BiTree T){
    if (T) {
       displayElem(T);
       PreOrderTraverse(T->lchild);
       PreOrderTraverse(T->rchild);
    }
    return ;
}


//中序

void INOrderTraverse(BiTree T){
    if (T) {
        INOrderTraverse(T->lchild);
        displayElem(T);
        INOrderTraverse(T->rchild);   
    }
    return ;
}

//后序
void PostOrderTraverse(BiTree T) {
    if (T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);   
        displayElem(T);
    }
    return ;
}