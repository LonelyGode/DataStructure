#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000001
typedef int ElementType;
struct LNode {
    ElementType Data[MAXSIZE];
    int Length;
};
typedef struct LNode *List;

//初始化顺序表
List initSeqList() {
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Length = 0;

    return L;
}

//传值
void getValue(List L, int n) {
    List p = L;
    int  i;

    for(i = 0; i < n; i++)
        scanf("%d", &(p->Data[i]));
    p->Length = n;
}

//寻找最长连续递增子序列
void getMaxLength(List L, int n) {
    List p = L;
    int i, j = 0, lengths = 1;  //lengths为1, 表示长度只有头部
    int lengthHead = 0;         //lengthHead为该连续子列与下一个比较的前者（简称：比较头）
    int lengthTail = 1;         //lengthTail为该连续子列比较的后者（简称：比较尾）
    int oldHead = 0;            //每段连续子列的原头部下标
    int maxLength;              //最大长度的连续子列
    int position;               //最大长度的头点下标

    for(i = 0; i < n; i++) {
        if(p->Data[lengthHead] < p->Data[lengthTail]) {     //满足连续子列的条件
            lengthHead++;       //比较头 后移一位
            lengthTail++;       //比较尾 后移一位
            lengths++;          //该段长度+1
        } else if(p->Data[lengthHead] >= p->Data[lengthTail]) {  //不满足连续子列的条件
            if(j == 0) {                //第一次传值
                maxLength = lengths;        //将该连续子列的长度赋值给length
                position = oldHead;          //将该连续子列的原头下标赋值给head
                j++;
            }
            if(j == 1) {                //第二次及以上传值
                if(maxLength < lengths) {
                    maxLength = lengths;
                    position = oldHead;
                }
            }
            lengthHead = lengthTail;    //比较头变比较尾
            oldHead = lengthTail;       //原头变比较尾
            lengthTail++;               //比较尾向后移一位
            lengths = 1;                //长度重新赋值为1
        }
    }

    for(i = 0; i < maxLength; i++) {    //输出最长子列
        if(i == 0 )
            printf("%d", p->Data[position]);
        else
            printf(" %d", p->Data[position]);
        position++;
    }
}

int main() {
    List L;
    int n;

    L = initSeqList();
    scanf("%d", &n);

    getValue(L, n);

    getMaxLength(L, n);

    return 0;
}
---------------------
作者：GYT0313
来源：CSDN
原文：https://blog.csdn.net/qq_38038143/article/details/69788154
版权声明：本文为博主原创文章，转载请附上博文链接！


