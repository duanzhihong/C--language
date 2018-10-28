//关于约瑟夫环的问题
#include <stdio.h>
#include <stdlib.h>

// //创建结构体
typedef struct node{
    int number;
    struct node *next;
}person;

//初始化链表
person *initLink(int n) {
    //创建头节点
    person *head = (person*)malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;
    person *cyclic = head; //创建两个指针，一个指向头，一个负责循环创建
    //循环创建
    for (int i = 2; i <= n; i++) {
        person *body = (person*)malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        cyclic->next = body;//指向新的节点
        cyclic = body; //指向目前的节点
    }
    cyclic->next = head;//指向头节点
    return head;
}

//进行查找和删除操作
void findAndKillK(person *head, int k, int m) {
    person *tail = head; //记录节点的上一个节点，方便删除
    while(tail->next != head) {
        tail = tail->next;
    }
    person *p =head;//用来循环
    //从k开始
    while(p->number != k) {
        tail = p;
        p = p->next;
    }
    //循环指向
    while(p->next != p) {
        for (int i = 1; i <m; i++) { //此处i<m，假如删除m，记录m-1的指针
            tail = p;
            p = p->next;
        }
        //删除
        tail->next = p->next;
        printf("出队编号为:%d\n",p->number);
        free(p);
        p = tail->next;
    }
    printf("最后出队编号为:%d\n",p->number);
    free(p);
}
