//二叉链表
    //一个数据域，两个指向左右孩子的指针
// typedef struct BitNode{
//     TElemType data;//数据域
//     struct BitNode *lchild, *rchild;
// }BitNode, *BiTree;

//需要频繁访问父节点的时候，可以使用三叉链表
    //一个数据域，三个指针，其中包含了指向父节点的指针
// typedef struct BitNode{
//     TElemType data;
//     struct BitNode *lchild, *rchild, *parent;
// }BitNode, *BiTree;

// 二叉树范例
//         1
//     2
// 3    

#include <stdio.h>
#include <stdlib.h>
#define TElemType int
typedef struct BitNode{
    TElemType data;
    struct BitNode *lchild, *rchild;
}BitNode, *BiTree;

void CreateBiTree(BiTree *T){
    *T = (BitNode*)malloc(sizeof(BitNode));

    (*T)->data = 1;
    (*T)->lchild = (BitNode*)malloc(sizeof(BitNode));
    (*T)->rchild = NULL;

    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BitNode*)malloc(sizeof(BitNode));
    (*T)->lchild->rchild = NULL;

    (*T)->lchild->lchild = 3;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;

}

int main(void) {
    BiTree Tree; //是一个指针
    CreateBiTree(&Tree);
    printf("%d", Tree->lchild->lchild->data);
    return 0;
}