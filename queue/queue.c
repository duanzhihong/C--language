//顺序存储队列  使用数组中的下标代替指针
#include <stdio.h>

//入队
// int enQueue(int *a, int rear, int data){
//         a[rear] = data;
//         rear++;
//         return rear;
// }

// //出队
// void deQueue(int *a, int font, int rear){
//     while(font != rear) {
//         printf("%d\n", a[font]);
//         font++;
//     }
// }

// int main(void) {
//     int a[100];
//     int font,rear;
//     font = rear = 0;
//     //入队
//     rear = enQueue(a, rear, 1);
//     rear = enQueue(a, rear, 2);
//     rear = enQueue(a, rear, 3);
//     rear = enQueue(a, rear, 4);
//     rear = enQueue(a, rear, 5);
//     //出队
//     deQueue(a, font, rear);
//     return 0;
// }
//缺点，数组中移动下标的时候，并没有释放多余的内存空间。
//解决办法就是使用循环队列
//判断队列是否满的方式，加一个空闲的内存，当(rear+1)%max == font时候为队满，当rear == font 时候，为队空
#include <stdio.h>
#define max 5
//入队
int enQueue(int *a, int front, int rear, int data){
    if ((rear+1)%max == front) {
        printf("队列空间已满");
        return rear;
    }
    a[rear%max] = data;
    rear++;
    return rear;
}
//出队
int deQueue(int *a, int front, int rear) {
    //判断是否为空
    if (front == rear) {
        printf("队列为空\n");
        return front;
    }
    printf("%d\n", a[front]);
    front = (front+1)%max;
    return front;
}

int main(void) {
    int a[max];
    int front,rear;
    front = rear = 0;
    rear = enQueue(a, front, rear, 1);
    rear = enQueue(a, front, rear, 2);
    rear = enQueue(a, front, rear, 3);
    rear = enQueue(a, front, rear, 4);

    front = deQueue(a, front ,rear);
    rear = enQueue(a, front, rear, 6);
    front = deQueue(a, front ,rear);
    front = deQueue(a, front ,rear);
    front = deQueue(a, front ,rear);
    front = deQueue(a, front ,rear);

    return 0;
}