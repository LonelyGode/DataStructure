/*
   本实验主要完成顺序栈基本操作的实现，栈中的元素类型为字符型（char）
   需要实现的基本操作为：
   1、顺序栈的初始化
   2、入栈操作
   3、出栈操作
   4、取栈顶元素
   5、求顺序栈的长度
   6、输出顺序栈中的元素
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
#define MAXSIZE 100    //顺序栈初始化时分配的存储空间长度
#define OVERFLOW -2

typedef struct {
    char *base;   //栈底指针,栈中元素为字符
    char *top;    //栈顶指针
    int stacksize;   //栈可用的最大容量
} SqStack;      //顺序栈结构


//初始化顺序栈S
void InitStack(SqStack &S) {
    //请同学们在此处把该操作补充完整，并调试
    S.base = new char[MAXSIZE];
    if(!S.base) {
        exit(OVERFLOW);
    }
    S.top = S.base;
    S.stacksize = MAXSIZE;
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
bool Pop(SqStack &S, char &e) {
    //请同学们在此处把该操作补充完整，并调试
    if(S.top == S.base) {
        return false;
    }
    e = *--S.top;
    return true;
}

//取顺序栈S的栈顶元素，用参数e返回取得的栈顶元素
bool GetTop(SqStack S, char &e) {
    //请同学们在此处把该操作补充完整，并调试
    if(S.top != S.base) {
        e = *(S.top - 1);
    }
    return true;
}

//求顺序栈S的长度
int StackLength(SqStack S) {
    //请同学们在此处把该操作补充完整，并调试
    int length;
    length = S.top - S.base;
    return length;
}

//输出顺序栈S中的元素（从栈底到栈顶的顺序输出）
void PrintStack(SqStack S) {
    //请同学们在此处把该操作补充完整，并调试
    int l = StackLength(S);
    for(int i = 0; i < l; i++) {
        cout << S.base[i] << " ";
    }
    cout << endl;
}

//操作菜单
void showmenu() {
    cout << "*****************************************************************" << endl;
    cout << "1.Push         2.Pop         3.PrintStack" << endl;
    cout << "4.GetTop       5.EXIT" << endl;
}


int main() {
    SqStack S;       //定义顺序栈变量S
    int k;
    char e;
    bool flag;
    InitStack(S);    //初始化顺序栈S
    cout << "Sequence sqStack S initalized successfully!" << endl;

    //循环显示菜单，完成顺序栈的一系列操作
    do {
        showmenu();
        cout << "Please select the serial number of the operation: " << endl;
        rewind(stdin);
        cin >> k;  //k表示用户选择的操作序号
        switch(k) {
        case 1:    //执行入栈操作
            cout << "Please enter the value inserted into the stack:" << endl;
            cin >> e;    //输入要插入到栈顶处的值
            flag = Push(S, e); //执行入栈操作，,flag表示入栈操作结果，或为true,或为false
            if(flag)       //若入栈操作成功
                cout << "Push operator succeeded!" << endl;
            else
                cout << "Stack is full,Push operator failed!" << endl;
            break;
        case 2:   //执行出栈操作
            flag = Pop(S, e);  //执行出栈操作，被删栈顶元素的值用e返回，flag表示出栈操作结果，或为true,或为false
            if(flag)       //若出栈操作成功
                cout << "Pop operator succeeded! The element that was deleted is:" << e << endl; //输出被删栈顶元素的值
            else
                cout << "The stack is empty and cannot be popped!" << endl;
            break;
        case 3:   //输出顺序栈的长度及栈中的元素
            cout << "Stack length is :" << StackLength(S) << ",Stack element is(From the bottom of the stack to the top of the stack)：" << endl;
            PrintStack(S);      //输出循环队列Q中的元素
            break;

        case 4:    //输出栈顶元素
            if(GetTop(S, e))
                cout << "The top element of the stack is:" << e << endl;
            else
                cout << "The stack is empty, there is no stack top element!" << endl;
            break;

        }//switch

    } while(k < 5);

    return 1;
}
























