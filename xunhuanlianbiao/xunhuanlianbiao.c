#include <stdio.h>
#include "xunhuanlianbiao.h"

int main(void) {
    printf("输入圆桌上的人数n：\n");
    int n;
    scanf("%d",&n);
    //初始化
    person *head = initLink(5);
    printf("从第k人开始报数\n");
    int k;
    scanf("%d", &k);
    printf("数到m的人出列");
    int m;
    scanf("%d", &m);
    findAndKillK(head, k, m);
    return 0;
}