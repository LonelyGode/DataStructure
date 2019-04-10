/*
   本实验主要完成循环队列基本操作的实现，循环队列中的元素类型为字符型（char）
   需要实现的基本操作为：
   1、循环队列的初始化
   2、入队操作
   3、出队操作
   4、取队头元素
   5、取队尾元素
   6、求循环队列的长度
   7、输出循环队列中的元素
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
#define MAXSIZE 5    //循环队列初始化时分配的存储空间长度
#define OVERFLOW -2

typedef struct {
    char *base;   //存储空间基址，队列中存储的元素是字符
    int front;    //队头指针
    int rear;   //队尾指针
} SqQueue;      //循环队列结构

//初始化循环队列Q
void InitQueue(SqQueue &Q) {
    //请同学们在此处把该操作补充完整，并调试
    Q.base = new char[MAXSIZE];
    if(!Q.base) {
        exit(OVERFLOW);
    }
    Q.front = Q.rear = 0;
}

//入队操作，向循环队列Q的队尾插入新元素e，插入成功，返回true,插入失败，返回false
bool EnQueue(SqQueue &Q, char e) {
    //请同学们在此处把该操作补充完整，并调试
    if((Q.rear + 1) % MAXSIZE == Q.front) {
        return false;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

//出队操作，删除循环队列Q的队头元素，被删元素用参数e返回，删除成功，函数返回true,删除失败，函数返回false
bool DeQueue(SqQueue &Q, char &e) {
    //请同学们在此处把该操作补充完整，并调试
    if(Q.front == Q.rear) {
        return false;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1 ) % MAXSIZE ;
    return true;
}

//取循环队列Q的队头元素，用参数e返回取得的队头元素
bool GetHead(SqQueue Q, char &e) {
    //请同学们在此处把该操作补充完整，并调试
    if(Q.front != Q.rear) {
        e = Q.base[Q.front];
        return true;
    } else {
        return false;
    }
}

//取循环队列Q的队尾元素，用参数e返回取得的队尾元素
bool GetTail(SqQueue Q, char &e) {
    //请同学们在此处把该操作补充完整，并调试
    if(Q.front != Q.rear) {
        e = Q.base[(Q.rear + MAXSIZE) % MAXSIZE - 1];
        return true;
    } else {
        return false;
    }
}

//求循环队列Q的长度
int QueueLength(SqQueue Q) {
    //请同学们在此处把该操作补充完整，并调试
    int length;
    length = (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
    return length;
}

//输出循环队列Q中的元素（从队头到队尾的顺序输出）
void PrintQueue(SqQueue Q) {
    //请同学们在此处把该操作补充完整，并调试
    int l = QueueLength(Q);
    for(int i = 0; i < l; i++) {
        cout << Q.base[(Q.front + i) % MAXSIZE] << " ";
    }
    cout << endl;
}


//操作菜单
void showmenu() {
    cout << "*****************************************************************" << endl;
    cout << "1.EnQueue      2.DeQueue       3.PrintQueue" << endl;
    cout << "4.GetHead      5.GetTail       6.EXIT" << endl;
}

int main() {
    SqQueue Q;       //定义循环队列Q
    int k;
    char e;
    bool flag;
    InitQueue(Q);    //初始化循环队列Q
    cout << "Cycliec queue Q initialized successfully!" << endl;

    //循环显示菜单，完成循环队列的一系列操作
    do {
        showmenu();
        cout << "Please select the serial number of the operation:" << endl;
        rewind(stdin);
        cin >> k;  //k表示用户选择的操作序号
        switch(k) {
        case 1:    //执行入队操作
            cout << "Please enter the value of the queue:" << endl;
            cin >> e;    //输入要插入到队尾处的值
            flag = EnQueue(Q, e); //执行入队操作，,flag表示入栈操作结果，或为true,或为false
            if(flag)       //若入队操作成功
                cout << "EnQueue operator succeeded!" << endl;
            else
                cout << "Queue is full, EnQueue operator failed!" << endl;
            break;
        case 2:   //执行出队操作
            flag = DeQueue(Q, e);  //执行出队操作，被删队头元素的值用e返回，flag表示出栈操作结果，或为true,或为false
            if(flag)       //若出队操作成功
                cout << "DeQueue operator succeeded! The element that was deleted is:" << e << endl; //输出被删队头元素的值
            else
                cout << "The Queue is empty and cannot be DeQueue!" << endl;
            break;
        case 3:   //输出队列的长度及队列中的元素
            cout << "Queue length is:" << QueueLength(Q) << ",Queue element is(From the bottom of the queue to the top of the queue ):" << endl;
            PrintQueue(Q);      //输出循环队列Q中的元素
            break;

        case 4:    //输出队头元素
            if(GetHead(Q, e))
                cout << "The head of queue is:" << e << endl;
            else
                cout << "The queue is empty , don't have head!" << endl;
            break;
        case 5:   //输出队尾元素
            if(GetTail(Q, e))
                cout << "The tail of queue is:" << e << endl;
            else
                cout << "The queue is empty, don't have tail!" << endl;
            break;
        }//switch

    } while(k < 6);
    return 1;
}











































