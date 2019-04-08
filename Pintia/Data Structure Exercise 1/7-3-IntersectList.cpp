#include <bits/stdc++.h>   //万能的头文件，包含C++中所有的头文件 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;   //单链表存储结构定义

bool flag = true; //标志，用于判断是否是交集中的第一个元素进行输出
int n = 0; //全局变量，用于判断交集中的元素个数

void InitList(LinkList &L) {  //初始化单链表L
    L = new LNode;
    L->next = NULL;
}

void CreateList(LinkList &L) { //向单链表L中插入数据 ，使用后插法建立单链表L
    LNode *p, *s, *r;
    r = L;
    int a;
    cin >> a; //读入第一个数据
    while(a != -1) { //判断是否是输入结束，输入结束的标志为-1
        s = new LNode; //创建新结点s并用后插法插入到L中
        s->data = a;
        r->next = s;
        r = s;
        cin >> a;	 //依次读入表中的后续数据
    }
    r->next = NULL; //将L的最后一个结点指针域置空
}

//求单链表L1和L2的交集，并输出求得的交集
void IntersectList(LinkList L1, LinkList L2) {
    LNode *p1, *p2;
    p1 = L1->next;
    p2 = L2->next;
    while(p1 && p2) { //依次判断P1和p2所指结点的大小，做出相应的处理
        if(p1->data == p2->data) {
            if(!flag) { //如果不是交集中的首元素输出（flag==false)，则先输出一个空格
                cout << " " << p1->data;
                n++;  //求得的交集元素数量加1
            } else { //交集中首元素的输出处理，首元素前没有空格
                flag = false;
                cout << p1->data;
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if(p1->data < p2->data)
            p1 = p1->next;
        else
            p2 = p2->next;
    }
    if(n == 0) //若交集元素个数为0，则输出NULL
        cout << "NULL";
}

int main(int argc, char** argv) {
    LinkList L1, L2; //定义单链表L1，L2
    InitList(L1);   //初始化单链表L1，L2
    InitList(L2);
    CreateList(L1);	//向L1和L2中插入元素
    CreateList(L2);
    IntersectList(L1, L2); //求L1与L2的交集并输出
    return 0;
}



