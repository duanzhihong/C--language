//顺序表
#include <stdio.h>
#include <stdlib.h>

//链表结构体
typedef struct Link{
    char elem;//数据域
    struct Link *next;//代表指针，指向后继元素
}link;

//创建一个链表
link *initLink(){
    link *p = (link*)malloc(sizeof(link)); //创建一个头节点
    link * temp  = p; //创建一个指针用来遍历链表
    //生成链表
    for (int i = 1 ; i < 5; i++) {
        link * a = (link*)malloc(sizeof(link)); //开辟一个节点
        a->elem = i;
        a->next = NULL;

        temp->next = a; //指向最新的节点
        temp = temp->next;
    }
    return p;
}

//遍历链表
void display(link *p){
    link * temp = p;//遍历的指针指向开头
    while(temp->next) {
        temp = temp->next;
        printf("%d", temp->elem);
    }
    printf("\n");
}

//查找值为elem的位置
int selectElem(link *p, int elem) {
    link * t = p;
    int i = 1;
    while(t->next) {
        t = t->next;
        if (t->elem == elem){
            return i;
        }
        i++;
    }
    return -1;
}

//将链表中a位置的值修改为newElem
link *amendElem(link *p, int add, int newElem) {
    link *t = p;
    t = t->next;//指向首元节点（并非头节点）
    for (int i =1; i < add; i++) {
        t = t->next;
    }
    t->elem = newElem;
    return p;
}

//向链表中插入数据
link *insertElem(link *p, int add, int newElem) {
    link * t = p;
    for(int i =1; i < add; i++) {
        if (t == NULL) {
            printf("插入的位置无效");
            exit(-1);
        }
        t = t->next;
    }
    //开辟新空间
    link *newP = (link *)malloc(sizeof(link));
    newP->elem = newElem;
    newP->next = t->next;
    t->next = newP; 
    return p;
}

//链表中删除第a个位置的节点
//进行手动得内存释放，防止内存泄漏
link *delElem(link *p, int add) {
    link *t = p;
    for (int i = 1; i < add; i++) {
        if (t == NULL) {
            printf("删除的位置无效\n");
        }
        t = t->next;
    }
    link *delP = t->next; //删除的元素的指针，释放内存使用
    t->next = t->next->next;
    free(delP);
    return p;
}