#include <stdio.h>
#include <stdlib.h>

//创建结构体
typedef struct line{
    struct line *prior; //指向前驱
    int data;
    struct line *next; //指向后继
} line;

//初始化双向链表
line* initLine(){
    line *head = (line*)malloc(sizeof(line));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    line *list = head; //用来循环创建链表
    for (int i = 2; i < 3; i++) {
        line *body = (line*)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        //改变指向
        list->next = body;
        body->prior = list;
        list = list->next;
    }
    return head;
}
//打印链表
void display(line *head){
    line *tmp = head;
    while(tmp){
        if (tmp->next == NULL) {
            printf("%d\n", tmp->data);
        } else {
            printf("%d->", tmp->data);
        }
        tmp = tmp->next;
    }
    printf("\n");
}

//插入节点
line *insertLine(line *head, int data, int add){
    //新建数据
    line *temp = (line*)malloc(sizeof(line));
    temp->prior = NULL;
    temp->data = data;
    temp->next = NULL;

    //判断插入的位置
    if (add == 1) {
        temp->next = head;
        head->prior = temp;
        head = temp;
    } else {
        line *body = head;
        //找到插入位置的头一个节点
        for (int i = 1; i < add-1; i++) {
            body = body->next;
        }
        //判断是否为链尾
        if (body->next == NULL) {
            body->next = temp;
            temp->prior = body;
        } else {
            body->next->prior = temp;
            temp->next = body->next;
            
            body->next = temp;
            temp->prior = body;
        }
    }
    return head;
}

//删除节点
line* delLine(line* head, int data){
    line *temp = head;
    while(temp) {
        //略首尾判断
        if (temp->data == data) {
            //进行删除
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    printf("没有该元素");
    return head;
}