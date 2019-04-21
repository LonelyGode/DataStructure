/*
    本实验主要完成单链表基本操作的实现，包括单链表的初始化操作，前（后）插法建表，取值，单链表的查找，单链表的插入与删除操作
    本实验约定单链表中存储的是整型数据
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;     //单链表表结构


//初始化单链表L
void InitList(LinkList &L) {
    //请同学们在此处把该操作补充完整
    L = new LNode;
    L->next = NULL;
}

//前插法建表，要求使用[1,100]内的随机整数填充单链表L,参数n表示要向表中填充几个数据
//提示：生成[1,100]内的随机整数公式为： rand()%100+1 ,在使用rand()函数前要先使用srand(time(0))设置随机数种子
void CreateListF(LinkList &L, int n) {
    //请同学们在此处把该操作补充完整，然后再main里面调用并调试
    L = new LNode;
    L->next = NULL;
    srand(time(0));
    for(int i = 0; i < n; i++) {
        LNode *p = new LNode;
        p->data = rand() % 100 + 1;
        p->next = L->next;
        L->next = p;
    }
}

//后插法建表，要求使用[1,100]内的随机整数填充单链表L,参数n表示要向表中填充几个数据
void CreateListR(LinkList &L, int n) {
    //请同学们在此处把该操作补充完整，然后再main里面调用并调试
    L = new LNode;
    L->next = NULL;
    LNode *r;
    r = L;
    srand(time(0));
    for(int i = 0; i < n; i++) {
        LNode *p = new LNode;
        p->data = rand() % 100 + 1;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//选做
//创建一个值递增有序的单链表，请同学们补充此操作
void CreateList(LinkList &L, int n) {
    //请同学们在此处把该操作补充完整，然后再main里面调用并调试
    L = new LNode;
    L->next = NULL;
    srand(time(0));
    LinkList q = L;
    for(int i = 0; i < n; i++) {
        LNode *p = new LNode;
        p->data = rand() % 100 + 1;
        while(q->next && p->data > q->next->data) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        q = L;
    }
}
void PrintList(LinkList L) {
    //请同学们在此处把该操作补充完整，并调试
    LinkList p = L->next;
    while(p) {
        cout << p->data << endl;
        p = p->next;
    }
}

//求单链表L的长度
int ListLength(LinkList L) {
    //请同学们在此处把该操作补充完整，并调试
    LinkList p = L->next;
    int i = 0;
    while(p) {
        i++;
        p = p->next;
    }
    return i;  //补充完该操作后，请删除该行代码
}


//在单链表L 中查找元素e的位置，查找成功，返回指向e的指针
LNode *LocateElem(LinkList L, int e) {
    //请同学们在此处把该操作补充完整，并调试
    LinkList p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}


//在单链表L的第i个结点前插入一个新元素e，插入成功，返回true,插入失败，返回false
bool ListInsert(LinkList &L, int i, int e) {
    //请同学们在此处把该操作补充完整，并调试
    LinkList p = L;
    int j = 0;
    while(p && (j < i - 1)) {
        p = p->next;
        j++;
    }
    if(!p || j > i - 1)
        return false;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//删除单链表L中第i 个结点，被删元素用参数e返回，删除成功，函数返回true,删除失败，函数返回false
bool ListDelete(LinkList &L, int i, int &e) {
    //请同学们在此处把该操作补充完整，并调试
    LinkList p = L;
    int j = 0;
    while((p->next) && (j < i - 1)) {
        p = p->next;
        j++;
    }
    if(!(p->next) || (j > i + 1))
        return false;
    LinkList q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
    return true;
}

int main() {
    LinkList L;       //定义单链表的头指针L
    int n, e, pos, flag;
    LNode *p;
    InitList(L);    //初始化单链表L
    cout << "Single list L initialized successfully!" << endl;
    cout << "Please enter the length of the list you want to create:";
    cin >> n;      //变量n表示要输入到单链表中的元素个数
    CreateList(L, n);  //向L中填充n个随机整数
    cout << "Single-linked list L was created successfully, and the elements in the table are:" << endl;
    PrintList(L);      //输出顺序表L中的元素
    cout << "The length of single-linked list L is:" << ListLength(L) << endl;
    cout << "Enter the value of the element you are looking for:";
    cin >> e;         //变量e表示要查找的元素
    p = LocateElem(L, e); //在L中查找元素e的位置，p表示查找结果，或为NULL，或为非NULL
    if(p) cout << "Find success!" << endl;
    else cout << "There is no value for" << e << "'s node." << endl;

    cout << "Please enter the insertion position and the inserted value:";
    cin >> pos >> e;  //输入向L中插入元素的位置及值
    flag = ListInsert(L, pos, e); //在单链表L的第pos个位置插入值e,flag表示插入操作结果，或为true,或为false
    if(flag) {     //判断插入操作是否成功
        cout << "The insert operation was successful, and the elements in the table are:" << endl;
        PrintList(L);     //输出插入操作成功后，L中的值
    } else
        cout << "Insert failed!" << endl;

    cout << "Enter the location of the deleted element:";
    cin >> pos;     //输入删除位置
    flag = ListDelete(L, pos, e); //删除单链表L中第pos个元素，被删元素的值用e返回，flag表示删除操作结果，或为true,或为false
    if(flag) {     //判断删除操作是否成功
        cout << "The deletion operation was successful, and the deleted element was:" << e << endl;
        cout << "The elements in the table are:" << endl; //输出被删元素的值
        PrintList(L);   //输出删除操作成功后，L中的值
    } else
        cout << "Error deleting location, operation failed!" << endl;

    return 1;
}




































































