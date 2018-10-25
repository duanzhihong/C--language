#include <stdio.h>
#include "shunxubiao.h"
#define Size 5
int main(void) {
	//初始化表
	table t1 = initTable(Size);
	//顺序表赋初始值
	for (int i = 1; i <= Size; i++){
		t1.head[i-1] = i;
		t1.length++;
	};
	printf("原顺序表\n");
	dispalyTable(t1);
	printf("\n");

	printf("查找3\n");
	int s = selectTable(t1, 3);
	printf("%d",s);
	
	printf("在4位置增加10\n");
	addTable(t1, 10, 4);
	dispalyTable(t1);

	printf("删除第一个数据\n");
	deleTable(t1,1);
	dispalyTable(t1);
}
