//括号匹配
#include <stdio.h>
#include <string.h>

int top = -1;
void push(char *a, int elem){
    top++;
    a[top] = elem;
}

void pop(char *a){
    if (top == -1) {
        return;
    }
    top--;
}

char visit(char *a){
    if (top != -1) {
        return a[top];
    } else {
        return ' ';
    }
}

int main(void) {
    char a[30]; //用于存放比较
    char bracket[100]; //输入的数据
    printf("请输入括号序列");
    scanf("%s", bracket);
    getchar();
    int length = (int)strlen(bracket);
    for (int i = 0; i < length; i++) {
        //左括号，入栈
        if (bracket[i] == '(' || bracket[i] == '{') {
            push(a, bracket[i]);
        } else {
            //判断是否匹配
            if (bracket[i] == ')') {
                if (visit(a) == '(') {
                    //匹配
                    pop(a);
                } else {
                    printf("括号不匹配");return 0;
                }
            }

            if (bracket[i] == '}') {
                if (visit(a) == '{') {
                    //匹配
                    pop(a);
                } else {
                    printf("括号不匹配");return 0;
                }
            }

        }
    }
    if (top != -1) {
        printf("括号不匹配");
    } else {
        printf("括号匹配");
    }
    return 0;
}