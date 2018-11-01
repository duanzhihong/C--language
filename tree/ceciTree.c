//采用递归实现对二叉树的遍历
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TElemType int
//队列的队头和队尾
int front = 0, rear = 0;
//       1
//   2       3
// 4   5   6   7 

//利用队列，1先入队，然后1出队，将2.3入队，然后2出队，45入队，3出队，67入队，循环直到结束
//构造节点
typedef struct BiTNode{
    TElemType data;//数据域
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
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

void EnQueue(BiTree * a, BiTree ndoe) {
    a[rear++] = ndoe;
}

BiTNode* DeQueue(BiTNode **a) {
    //**a 指向指针的指针
    return a[front++];
}

void displayNode(BiTree node){
    printf("%d", node->data);
}

int main(void) {
    BiTree tree;
    CreateBiTree(&tree);
    BiTNode * p;
    BiTree a[20]; //存放指针的数组
    EnQueue(a, tree);
    while(front < rear) {
        p = DeQueue(a);
        displayNode(p);
        if (p->lchild != NULL) {
            EnQueue(a, p->lchild);
        }
        if (p->rchild != NULL) {
            EnQueue(a, p->rchild);
        }
    }
    return 0;
}