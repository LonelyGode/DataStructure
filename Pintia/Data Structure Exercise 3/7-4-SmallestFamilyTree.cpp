#include <iostream>
#include <algorithm>   //本程序中使用了sort函数，要加入该头文件的引用
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct cnode {     //定义孩子结点
    int data;   //孩子结点的值（此处也是孩子在数组a中的位置）
    cnode *next;   //指向下一个孩子结点的指针
};

struct node {   //数组类型定义，每个数组元素表示树中的一个结点
    int data;   //结点的值
    int level;  //结点的层数
    cnode *fistchild;   //指向孩子链表的头指针
} a[100001];  //数组a存储树中的全部结点

void CountLevel(int root, int le) { //求以root为根的树中各结点的层数
    cnode *p;
    p = a[root].fistchild; //p指向根的第一个孩子结点（即root第一棵子树的根）
    if(p == NULL) //遇到空树，则返回
        return;
    while(p) { //依次求root各孩子结点的层数，其孩子结点的层数为le
        a[p->data].level = le; //将孩子结点的层数赋值为le
        CountLevel(p->data, le + 1); //递归求以p->data为根的子树中各结点的层数
        p = p->next; //p指向下一个孩子，求下一个孩子的层数
    }
}

void Print(int n) { //输出最小辈信息
    int maxlevel = 0, j = 0;
    int temp[100001];   //该数组用于暂存求得的最小辈结点
    for(int i = 1; i <= n; i++) { //求该家族中的最大代数（即最小辈所在的代），用maxlevel表示
        if(a[i].level >= maxlevel) {
            maxlevel = a[i].level;
        }
    }

    for(int i = 1; i <= n; i++) { //将最小辈的结点存入数组temp中
        if(a[i].level == maxlevel) {
            temp[j] = a[i].data;
            j++;
        }
    }

    sort(temp, temp + j); //对temp数组进行排序，需引用头文件algorithm
    cout << maxlevel << endl; //输出最小辈分
    for(int i = 0; i < j; i++) { //输出辈分最小的成员编号
        if(i == j - 1)
            cout << temp[i];
        else
            cout << temp[i] << " ";
    }

}
int main(int argc, char** argv) {
    int n;
    cin >> n;
    int root;   //记录树根的位置
    for(int i = 1; i <= n; i++) { //初始化数组a,每个结点的层数level初始化为1，data值为i,firstchild为空
        a[i].level = 1;
        a[i].data = i;
        a[i].fistchild = NULL;
    }
    for(int i = 1; i <= n; i++) { //创建孩子链表
        int parent;
        cnode *s;
        cin >> parent; //输入第i个结点的双亲，i为孩子，parent表示双亲
        if(parent == -1) //若parent为-1，则该结点为根
            root = i;
        else {
            s = new cnode; //创建孩子结点
            s->data = i; //为孩子结点赋值
            s->next = a[parent].fistchild; //使用头插法将孩子结点s插入到其双亲(在数组a的parent处）对应的单链表中
            a[parent].fistchild = s;
        }
    }
    CountLevel(root, 2); //计算该树中每个结点的层数，从第二层开始计算，因根结点的level已初始化为1
    Print(n); //输出最小辈信息
    return 0;
}


