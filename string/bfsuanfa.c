//bf算法，普通匹配模式
//拿一个串，每次进行比较，不对应的时候移动一位继续比较
#include <stdio.h>
#include <string.h>
int sel(char *S, char *T) {
    int i = 0; //循环s字符串
    int j = 0; //循环t字符串
    int sLength = strlen(S);
    int tLength = strlen(T);
    while(i < sLength && j < tLength) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            i = i-j+1; //i向后移动一位
            j = 0;
        }
    }
    //模式串匹配成功说明 j == tLength
    if (j == tLength) {
        return i-j+1;
    }
    return 0;
}
int main(void) {
    int location = sel("abcdef", "de");
    printf("匹配的位置为%d", location);
    return 0;
}

//分析时间复杂度
// 取决于主串m和副串n，最坏情况下，m和n不断进行遍历，最后才得知失败
// O(m*n)