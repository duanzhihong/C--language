#include <stdio.h>
#include <stdlib.h>
#include "jingtailianbiao.h"
int main(void) {
    component array[50];
    //初始化
    int body = initArr(array, 10);
    printf("%d|%d\n",array[0].data, array[0].cur);
    displayArr(array, body);
    printf("\n");
    //查找元素
    // printf("查找元素8的位置\n");
    // int location = selectElem(array, body, 8);
    // printf("%d\n", location);

    //修改元素的值
    // printf("修改7的数据为17\n");
    // amendElem(array, body, 7, 17);
    // displayArr(array, body);

    //添加元素i
    // printf("在3位置后面添加18\n"); 
    // insertArr(array, body, 3, 18);
    // printf("%d|%d\n",array[0].data, array[0].cur);
    // displayArr(array, body);

    //删除元素
    printf("删除8数据\n");
    deletArr(array, body, 8);
    displayArr(array, body);
    return 0;
}