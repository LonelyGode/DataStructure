#include <bits/stdc++.h>

using namespace std;


typedef struct {
    char *base;   //存储空间基址，队列中存储的元素是字符
    int front;    //队头指针
    int rear;   //队尾指针
} SqQueue;      //循环队列结构

typedef struct {
    char *base;   //栈底指针,栈中元素为字符
    char *top;    //栈顶指针
    int stacksize;   //栈可用的最大容量
} SqStack;      //顺序栈结构

void InitQueue(SqQueue &Q) {
    //请同学们在此处把该操作补充完整，并调试
    Q.base = new char[5];
    if(!Q.base) {
        exit(-2);
    }
    Q.front = Q.rear = 0;
}
//初始化顺序栈S
void InitStack(SqStack &S) {
    //请同学们在此处把该操作补充完整，并调试
    S.base = new char[100];
    if(!S.base) {
        exit(-2);
    }
    S.top = S.base;
    S.stacksize = 100;
}

//入队操作，向循环队列Q的队尾插入新元素e，插入成功，返回true,插入失败，返回false
bool EnQueue(SqQueue &Q, char e) {
    //请同学们在此处把该操作补充完整，并调试
    if((Q.rear + 1) % 5 == Q.front) {
        return false;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % 5;
    return true;
}

//出队操作，删除循环队列Q的队头元素，被删元素用参数e返回，删除成功，函数返回true,删除失败，函数返回false
char DeQueue(SqQueue &Q) {
    //请同学们在此处把该操作补充完整，并调试
    if(Q.front == Q.rear) {
        return false;
    }
    return Q.base[Q.front];
    Q.front = (Q.front + 1 ) % 5 ;
}


//入栈操作，向顺序栈S的栈顶处插入新元素e，插入成功，返回true,插入失败，返回false
bool Push(SqStack &S, char e) {
    //请同学们在此处把该操作补充完整，并调试
    if(S.top - S.base == S.stacksize) {
        return false;
    }
    *S.top++ = e;
    return true;
}

//出栈操作，删除顺序栈S的栈顶元素，被删元素用参数e返回，删除成功，函数返回true,删除失败，函数返回false
char Pop(SqStack &S ) {
    //请同学们在此处把该操作补充完整，并调试
    if(S.top == S.base) {
        return false;
    }
    return  *--S.top;
}

SqQueue Q;
SqStack S;

int finding(int n) {
    int m, k;
    m = DeQueue(Q) + n / 2;
    if(m > 3) {
        n = m / 2;
        EnQueue(Q, n);
        if(!m % 2) {
            Push(S, n - 1);
            k = finding(n);
        } else {
            k = finding(n + 3);
        }
    } else {
        return m;
    }
    cout << k << " ";
    return m + k;
}

int Findout(int m, int n) {
    InitQueue(Q);
    InitStack(S);
    EnQueue(Q, m);
    Push(S, n);
    finding(n);
    while(!(S.top == S.base)) {
        m = Pop(S);
        cout << m << " ";
    }
}

int main() {
    Findout(24, 4);
    return 1;
}



























