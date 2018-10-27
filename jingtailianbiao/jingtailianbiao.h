#include <stdio.h>
#include <stdlib.h>

//定义结构体
typedef struct {
    int data; //数据域
    int cur; //游标
}component;

//创建备用链表
void reserverArr(component *array, int maxSize){
    for (int i = 0; i < maxSize; i++) {
        array[i].cur = i+1; //每一个下标指向下一个元素
    }
    // //最后一个指向0
    array[maxSize].cur = 0; 
}

//提取分配空间,备用链表中的第一个
int mallocArr(component *array){
    //若链表不为空，则返回分配的节点下标
    int i = array[0].cur;
    if (i) {
        array[0].cur = array[i].cur;
    }
    return i;
}

//释放数据，存放到备用链表中
void freeArr(component * array, int del) {
    array[del].cur = array[0].cur;
    array[0].cur = del;
}



//初始化静态链表
int initArr(component *array, int maxSize){
    reserverArr(array, maxSize); //创建备用链表
    int body = mallocArr(array); // 从备用链表中取出空闲分量, 返回可用的空闲分量的下标
    int tempBody = body; //创建一个变量，起到指针的作用
    //存放5条数据
    for (int i = 0; i < 5; i++) {
        int j = mallocArr(array); //取出可用的空闲分量
        array[tempBody].cur = j; //最后一个节点指向新的数据
        array[j].data = 10-i; //向空闲分量赋值
        tempBody = j;
    }
    array[tempBody].cur = 0;
    return body;
}

//遍历静态链表
void displayArr(component *array,int body) {
    int tempBody = body;
    while(array[tempBody].cur) {
        printf("%d | %d\n",array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf(" %d| %d\n",array[tempBody].data, array[tempBody].cur);
}

//静态链表中查找数据
int selectElem(component * array, int body, int elem) {
    int tempBody = body;
    while (array[tempBody].cur != 0){
        if (array[tempBody].data == elem) {
            return tempBody;
        }
        tempBody = array[tempBody].cur;
    }
    return -1;
}

//静态链表中进行更改（查找到位置，然后进行替换）
void amendElem(component * array, int body, int oldElem, int newElem) {
    int location = selectElem(array, body, oldElem);
    if (location == 01) {
        printf("没有修改的元素");
        exit(-1);
    }
    array[location].data = newElem;
}

//静态链表中插入元素（原理其实就是指向下标的更换）
//在add的位置插入newElem
void insertArr(component * array, int body, int add ,int newElem){
    int tempBody = body;
    //查找上一个元素的位置，下标,找到这里基本的替换就可以了
    for (int i = 1; i < add; i++) {
        tempBody = array[tempBody].cur;
    }
    //申请新的空间
    int insert = mallocArr(array);
    array[insert].data = newElem; 
    array[insert].cur = array[tempBody].cur;
    array[tempBody].cur = insert;
 }

 //删除静态链表
 void deletArr(component * array, int body, int elem) {
     int tempBody = body;
     while(array[tempBody].data != elem){
         tempBody = array[tempBody].cur;
         if (tempBody == 0) {
             printf("没有此数据\n");
             exit(-1);
         }
     }
    int del = tempBody;
    tempBody = body;
    //上一个节点赋值
    while(array[tempBody].cur != del) {
        tempBody = array[tempBody].cur;
    }
    array[tempBody].cur = array[del].cur;

    freeArr(array, del); //将del的节点存放到备用链表中
 }

