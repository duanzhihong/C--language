//根据关键字的查找概率不同，创建静态最优查找树（带权路径长度之和）
//一般都使用接近于最优查找树的二叉树：次查找树
//思路：根据关键字和权值计算出p，取最小的作为根节点，然后依次创建
typedef int KeyType; //定义关键字类型
typedef struct {
    KeyType key;
}ElemType; //定义元素类型

typedef struct  BitNode{
    ElemType data;
    struct BitNode *lchild, *rchild
}BitNode, *BiTree;

//定义变量
int i;
int min;
int dw;

//创建次优查找树，r为查找树,sw数组为存储的各个关键字的概率
void SecondOptimal(BiTree T, ElemType R[], float sw[], int low, int high){
    //由有序表R[low...high]及其累计权值表sw（其中sw[0]==0）递归构造次优查找树
    i = low;
    min = abs(sw[high] - sw[low]);
    dw = sw[high] + sw[low - 1];
    //选择最小的△Pi值
    for (int j = low+1; j <=high; j++){
        if (abs(dw-sw[j]-sw[j-1])<min){
            i = j;
            min = abs(dw - sw[j] - sw[j - 1]);
        }
    }
   
    T = (BiTree)malloc(sizeof(BiTNode));
    T->data = R[i];//生成结点（第一次生成根）
    if (i == low) T->lchild = NULL;//左子树空
    else SecondOptimal(T->lchild, R, sw, low, i - 1);//构造左子树
    if (i == high) T->rchild = NULL;//右子树空
    else SecondOptimal(T->rchild, R, sw, i + 1, high);//构造右子树
   
}