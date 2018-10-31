//kmp算法（快速模式匹配算法）
//快速模式匹配算法
#include <stdio.h>
#include <string.h>

//创建模式串的next数组
void Next(char *T, int *next){
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i < strlen(T)) {
        //如果next的值为0或者相等，结束比较。否则的话继续比较
        if (j == 0 || T[i-1] == T[j-1]) {
            i++;
            j++;
            next[i] = j; //next值= 之前的值+1
        } else {
            j = next[j]; //继续比较，直到next的值为0
        }
    }  
}

//kmp排序
int KMP(char *S, char *T){
    int next[10];//创建next数组
    Next(T,next);
    int i = 1;
    int j = 1;
    while(i <= strlen(S) && j <= strlen(T)) {
        if (j == 0 || S[i-1]==T[j-1]) {
            //初始指针不相等，或者已经找到一个相当的字符，都需要将指针向后移动
            i++;
            j++;
        } else {
            j = next[j]; //继续next的值
        }
    }
    if (j > strlen(T)) { //如果j从0计数，则条件为 == 
        return i-(int)strlen(T);
    }
    return -1;
}

int main(void){
    int i = KMP("ababcabcacbab", "abcac");
    printf("位置为%d",i);
    return 0;
}