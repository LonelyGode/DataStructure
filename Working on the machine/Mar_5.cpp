#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100    //顺序表初始化时分配的存储空间长度
#define OVERFLOW -2

using namespace std;

typedef struct {
    int *elem;
    int length;
} Sqlist;      //顺序表结构


//初始化顺序表L
void InitList(Sqlist &L) {
    //请同学们在此处把该操作补充完整，并调试
    L.elem = new int[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
}


//向顺序表L中填充数据，本例中使用[1,100]内的随机整数填充顺序表L,参数n表示要向表中填充几个数据
void CreateList(Sqlist &L, int n) {
    int i;
    srand(time(0));   //设置随机数种子
    for(i = 0; i < n; i++) { //向顺序表L中填充n个[1,100]内的随机整数
        L.elem[i] = rand() % 100 + 1;
    }
    L.length = n;   //修改顺序表L的长度
}


//输出顺序表L 中的元素
void PrintList(Sqlist L) {
    int i;
    for(i = 0; i < L.length ; i++) {
        cout << L.elem[i] << "  ";
    }
    cout << endl;
}


//在顺序表L 中查找元素e的位置，查找成功，返回e在L中的位序，否则返回0
int LocateElem(Sqlist L, int e) {
    //请同学们在此处把该操作补充完整，并调试
    for(int i = 0; i < L.length - 1; i++) {
        if(L.elem[i] == e)
            return i + 1;
    }
    return 0;
}


//在顺序表L的第i个元素前插入一个新元素e，插入成功，返回true,插入失败，返回false
bool ListInsert(Sqlist &L, int i, int e) {
    //请同学们在此处把该操作补充完整，并调试
    if((i < 1) || (i > L.length + 1)) return false;
    if(L.length == MAXSIZE) return false;
    for(int j = L.length - 1; j > i - 1; j--) {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    ++L.length;
    return true;
}

//删除顺序表L中第i 个位置处的元素，被删元素用参数e返回，删除成功，函数返回true,删除失败，函数返回false
bool ListDelete(Sqlist &L, int i, int &e) {
    //请同学们在此处把该操作补充完整，并调试
    if((i < 1) || (i > L.length))
        return false;
    e = L.elem[i - 1];
    for(int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];
    --L.length;
    return true;
}

int main() {
    Sqlist L;       //定义顺序表变量L
    int n, e, pos, flag;
    InitList(L);    //初始化顺序表L
    cout << "顺序表L初始化成功" << endl;
    cout << "请输入要创建的顺序表的长度" << endl;
    cin >> n;      //变量n表示要输入到顺序表中的元素个数
    CreateList(L, n);  //向L中填充n个随机整数
    cout << "顺序表L创建成功，表中元素为：" << endl;
    PrintList(L);      //输出顺序表L中的元素
    cout << "请输入要查找的元素的值" << endl;
    cin >> e;         //变量e表示要查找的元素
    pos = LocateElem(L, e); //在L中查找元素e的位置，pos表示查找结果，或为0，或为非零值
    cout << "元素" << e << "在表中的位序为" << pos << endl;
    cout << "请输入插入位置及插入的值" << endl;
    cin >> pos >> e;  //输入向L中插入元素的位置及值
    flag = ListInsert(L, pos, e); //在顺序表L的第pos个位置插入值e,flag表示插入操作结果，或为true,或为false
    if(flag) {     //判断插入操作是否成功
        cout << "插入操作成功，表中元素为：" << endl;
        PrintList(L);     //输出插入操作成功后，L中的值
    } else
        cout << "插入失败！" << endl;

    cout << "请输入删除元素的位置" << endl;
    cin >> pos;     //输入删除位置
    flag = ListDelete(L, pos, e); //删除顺序表L中第pos个元素，被删元素的值用e返回，flag表示删除操作结果，或为true,或为false
    if(flag) {     //判断删除操作是否成功
        cout << "删除操作成功，被删元素为：" << e << "表中元素为：" << endl; //输出被删元素的值
        PrintList(L);   //输出删除操作成功后，L中的值
    } else
        cout << "删除位置错误，操作失败！" << endl;

    return 1;
}
























