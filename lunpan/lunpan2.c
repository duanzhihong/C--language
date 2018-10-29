#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//使用循环链表解决
typedef enum{false, true} bool;

typedef struct line{
    int No;
    struct line *next;
}line;

line *initLine(line *head, int n){
    //创建指针
    head = (line*)malloc(sizeof(line));
    (head)->next = NULL;
    (head)->No = 1;
    line *list = head;
    for(int i=1; i<n; i++) {
        line *body = (line*)malloc(sizeof(line));
        body->next = NULL;
        body->No = i+1;

        list->next = body;
        list = list->next;
    }
    list->next = head;
    return head;
}

void display(line *head){
    line *tmp = head;
    printf("链表的顺序为：\n");
    while(tmp->next!=head){
        printf("%d",tmp->No);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->No);
}

int main(void){
    line *head = NULL;
    int n,shootNum,rounds = 1;
    printf("输入赌徒的数量");
    scanf("%d", &n);
    head = initLine(head, n);
    display(head);
    //进行删除
    line *lineNext = head;//记录每轮开始的位置
    while(head->next != head) {
        printf("第%d轮开始，从第%d个人开始",rounds, lineNext->No);
        shootNum = rand()%n+1;
        printf("在第%d次扣动时会退出\n", shootNum);
        line *temp = lineNext;//遍历链表
        for (int i = 1; i < shootNum-1; i++) {
            temp = temp->next; //记录删除之前的节点
        }
        printf("编号为%d的赌徒退出,剩下的为\n", temp->next->No);
        //删除节点
        line *del = temp->next; //记录下来，需要free
        temp->next = temp->next->next;
        if (del == head){
            head = head->next;
        }
        free(del);
        display(head);
        //新的开始
        lineNext = temp->next;
        rounds++;
    }
    printf("获胜的为%d", head->No);
    return 0;
}