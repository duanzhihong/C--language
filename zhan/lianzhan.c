#include <stdio.h>
#include <stdlib.h>
//链栈直接修改指针的指向来实现栈

//创建数据域和指针
typedef struct lineStack{
    char data;
    struct lineStack *next;
}lineStack;

//入栈
lineStack* push(lineStack * stack, char a){
    lineStack *new = (lineStack*)malloc(sizeof(lineStack));
    new->data = a;
    new->next = stack;

    stack = new;
    return stack;
}

//出栈
lineStack* pop(lineStack * stack){
    if (stack) {
        lineStack * p = stack;
        printf("当前出栈的元素为%c\n", p->data);
        stack = stack->next;
        if (stack) {
            printf("栈顶元素%c\n", stack->data);
        } else {
            printf("栈空");
        }
        free(p);
    } else {
        printf("栈内没有元素");
        return stack;
    }
    return stack;
}

int main(void){
    lineStack * stack = NULL;
    stack = push(stack, 'a');
    stack = push(stack, 'b');
    stack = push(stack, 'c');
    stack = push(stack, 'd');

    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);

    return 0;
}