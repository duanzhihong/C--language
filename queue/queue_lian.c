//使用链表存储实现队列
#include <stdio.h>
#include <stdlib.h>

typedef struct QNode{
    int data;
    struct QNode *next;
}QNode;

//初始化链队列
QNode * inintQueue(){
    QNode *queue = (QNode*)malloc(sizeof(QNode));
    queue->next = NULL;
    return queue;
}

//链队列添加数据
QNode * enQueue(QNode *rear, int data){
    QNode * enElem = (QNode*)malloc(sizeof(QNode));
    enElem->data = data;
    enElem->next = NULL;
    rear->next = enElem;
    rear = enElem;
    return rear;
}

//链队列删除元素
void * DeQueue(QNode *front, QNode *rear){
    //判断队列是否为空
    if (front->next == NULL) {
        printf("队列为空\n");
        return 0;
    }
    QNode *p = front->next;
    printf("%d", p->data);
    front->next = p->next;
    //如果删除的是末尾指针
    if (rear == p) {
        rear = front;//尾指针重新指向
    }
    free(p);
    return 0;
}

int main() {
    QNode *front, *rear;
    front = rear = inintQueue();
    rear = enQueue(rear, 2);
    rear = enQueue(rear, 3);
    rear = enQueue(rear, 6);
    rear = enQueue(rear, 7);
    DeQueue(front, rear);
    DeQueue(front, rear);
    DeQueue(front, rear);
    DeQueue(front, rear);
    return 0;
}