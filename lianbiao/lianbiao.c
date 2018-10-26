
#include <stdio.h>
#include <stdlib.h>
#include "./lianbiao.h"
//顺序表

int main(void){
    //初始化链表,5个元素
    link *p = initLink();
    display(p);
    //查找元素为4的位置
    // int i = selectElem(p, 4);
    // printf("元素为4的位置为%d", i);
    // printf("修改3的位置为6\n");    
    // p = amendElem(p, 3, 6);
    // display(p);
    // printf("在4得位置插入8\n");
    // p = insertElem(p, 4, 8);
    // display(p);
    printf("删除第3个元素\n");
    p = delElem(p, 3);
    display(p);
    return 0;
}