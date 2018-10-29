#include <stdio.h>
#include "shuangxianglianbiao.h"

int main(void){
    //初始化双向链表
    line *head = initLine();
    display(head);
    //插入链表
    head = insertLine(head, 4, 2);
    display(head);

    //删除数据
    head = delLine(head, 4);
    display(head);
    return 0;

}

