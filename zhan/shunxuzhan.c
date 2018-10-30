#include <stdio.h>
//实现顺序栈

//压栈
int push(char *a, int top, int data) {
    top++;
    a[top] = data;
    return top;
}

//出栈
int pop(char *a, int top) {
    //是否为空
    if (top == -1){
        printf("空栈");
        return -1;
    }
    printf("弹栈元素：%c\n", a[top]);
    top--;
    return top;
}

int main(void) {
    char a[100];
    int top = -1;
    top = push(a, top, 'a');
    top = push(a, top, 'b');
    top = push(a, top, 'c');
    top = push(a, top, 'd');

    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    return 0;
}