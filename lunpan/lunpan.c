// 游戏规则：n 个参加者排成一个环，每次由主持向左轮手枪中装一颗子弹，并随机转动关上转轮，游戏从第一个人开始，轮流拿枪；中枪者退出赌桌，退出者的下一个人作为第一人开始下一轮游戏。直至最后剩余一个人，即为胜者。要求：模拟轮盘赌的游戏规则，找到游戏的最终胜者。

//采用顺序表实现
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct gambler{
    int number;
}gambler;

int main(void){
    int n; //赌徒人数
    int roundes = 1; //次数
    int location = 1; 
    int shootNum;
    int i,j;
    printf("请输入赌徒的人数：");
    scanf("%d", &n);
    printf("将赌徒一次进行编号为1-%d\n", n);
    gambler gamblers[n+1];//存储编号的数组 int a[]
    for (i = 1; i <= n; i++) { //从1开始存放数据
        gamblers[i].number = i;
    }

    //进行赌徒删除
    while(n != 1) {
        printf("第%d轮开始，从第%d的人开始\n", roundes, gamblers[location].number);
        //获取随机
        shootNum = rand()%6+1;
        // shootNum =4;
        printf("第%d枪响会退出\n", shootNum);
        //计算退出的位数B
        i = location+shootNum;
        for (i=location; i<location+shootNum; i++);
        //计算退出的人
        i = i%n;
        if (i == 0 || i == 1) {
            i = i+n; //1与0除以任何数的余数都是1或0
        }
        printf("编号%d的赌徒推出，剩余的编号依次为\n", gamblers[i-1].number);
        //删除元素之后的向前移动
        for (j = i-1 ; j+1<=n; j++){
            gamblers[j] = gamblers[j+1]; 
        }
        n--;
        for (int k=1; k<=n; k++){
            printf("%d", gamblers[k].number);
        }
        printf("\n");
        //下一轮开始的位置
        location = i-1;
        roundes++;
    }
    printf("最终胜利的是%d",gamblers[1].number);
    return 0;
}













