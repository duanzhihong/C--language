//顺序表
#include <stdio.h>
#include <stdlib.h>

//存储结构
typedef struct Table{
    int *head; //声明一个动态数组
    int length; //记录当前数组的长度
    int size;   //记录顺序表分配的存储容量
}table;

//建立 空表的大小
table initTable(int Size){
    table t;
    t.head = (int *)malloc(Size * sizeof(int)); //创建一个空的顺序表
    if (!t.head) {
        printf("创建失败");
        exit(0);
    }
    t.length = 0;
    t.size = Size;
    return t;
}

//查找，顺序查找
int selectTable(table t, int elem){
    for(int i = 0; i < t.length; i++) {
        if (t.head[i] == elem){
            return i+1;
        }
    }
    return -1;
}

//顺序表中更改元素 elem为要改的，newElem为新的元素
table amendTable(table t, int elem, int newElem){
    int add = selectTable(t, elem);
    t.head[add-1] = newElem;
    return t;
}

//顺序表中插入元素 elem为新数据，add为添加的位置
table addTable(table t, int elem, int add){
    //判断位置是否正确
    if (add > t.length || add < 1) {
        printf("插入的位置错误");
        return t;
    }
    //判断是否有多余的内存提供给插入的元素,如果没有，需要申请
    if (t.length == t.size) {
        t.head = (int *)realloc(t.head, (t.size+1)*sizeof(int));
        if (!t.head) {
            printf("分配内存失败");
            return t;
        }
        t.size+=1;
    }
    //插入操作，将之后的元素后移
    for (int i = t.length-1; i >= add-1; i--) {
        t.head[i+1] = t.head[i];
    }
    //移动完成后，添加新元素
    t.head[add-1] = elem;
    //长度添加1
    t.length++;
    return t;
}

//顺序表删除 add为删除的位置
table  deleTable(table t, int add){
    if (add > t.length || add<1) {
        printf("被删除的位置错误");
        exit(0);
    }
    //删除，覆盖操作
    for (int i = add; i < t.length; i++) {
        t.head[i-1] = t.head[i];
    }
    t.length--;
    return t;

}

//遍历表
void dispalyTable(table t){
    for (int i =0; i < t.length; i++){
        printf("%d ",t.head[i]);
    }
}