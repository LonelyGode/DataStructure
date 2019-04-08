/*
   ��ʵ����Ҫ���˳��ջ����������ʵ�֣�ջ�е�Ԫ������Ϊ�ַ��ͣ�char��
   ��Ҫʵ�ֵĻ�������Ϊ��
   1��˳��ջ�ĳ�ʼ��
   2����ջ����
   3����ջ����
   4��ȡջ��Ԫ��
   5����˳��ջ�ĳ���
   6�����˳��ջ�е�Ԫ��
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
#define MAXSIZE 100    //˳��ջ��ʼ��ʱ����Ĵ洢�ռ䳤��
#define OVERFLOW -2

typedef struct {
    char *base;   //ջ��ָ��,ջ��Ԫ��Ϊ�ַ�
    char *top;    //ջ��ָ��
    int stacksize;   //ջ���õ��������
} SqStack;      //˳��ջ�ṹ


//��ʼ��˳��ջS
void InitStack(SqStack &S) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    S.base = new char[MAXSIZE];
    if(!S.base) {
        exit(OVERFLOW);
    }
    S.top = S.base;
    S.stacksize = MAXSIZE;
}


//��ջ��������˳��ջS��ջ����������Ԫ��e������ɹ�������true,����ʧ�ܣ�����false
bool Push(SqStack &S, char e) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    if(S.top - S.base == S.stacksize) {
        return false;
    }
    *S.top++ = e;
    return true;
}

//��ջ������ɾ��˳��ջS��ջ��Ԫ�أ���ɾԪ���ò���e���أ�ɾ���ɹ�����������true,ɾ��ʧ�ܣ���������false
bool Pop(SqStack &S, char &e) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    if(S.top == S.base) {
        return false;
    }
    e = *--S.top;
    return true;
}

//ȡ˳��ջS��ջ��Ԫ�أ��ò���e����ȡ�õ�ջ��Ԫ��
bool GetTop(SqStack S, char &e) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    if(S.top != S.base) {
        e = *(S.top - 1);
    }
    return true;
}

//��˳��ջS�ĳ���
int StackLength(SqStack S) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    int length;
    length = S.top - S.base;
    return length;
}

//���˳��ջS�е�Ԫ�أ���ջ�׵�ջ����˳�������
void PrintStack(SqStack S) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    int l = StackLength(S);
    for(int i = 0; i < l; i++) {
        cout << S.base[i] << " ";
    }
    cout << endl;
}

//�����˵�
void showmenu() {
    cout << "*****************************************************************" << endl;
    cout << "1.Push         2.Pop         3.PrintStack" << endl;
    cout << "4.GetTop       5.EXIT" << endl;
}


int main() {
    SqStack S;       //����˳��ջ����S
    int k;
    char e;
    bool flag;
    InitStack(S);    //��ʼ��˳��ջS
    cout << "Sequence sqStack S initalized successfully!" << endl;

    //ѭ����ʾ�˵������˳��ջ��һϵ�в���
    do {
        showmenu();
        cout << "Please select the serial number of the operation: " << endl;
        rewind(stdin);
        cin >> k;  //k��ʾ�û�ѡ��Ĳ������
        switch(k) {
        case 1:    //ִ����ջ����
            cout << "Please enter the value inserted into the stack:" << endl;
            cin >> e;    //����Ҫ���뵽ջ������ֵ
            flag = Push(S, e); //ִ����ջ������,flag��ʾ��ջ�����������Ϊtrue,��Ϊfalse
            if(flag)       //����ջ�����ɹ�
                cout << "Push operator succeeded!" << endl;
            else
                cout << "Stack is full,Push operator failed!" << endl;
            break;
        case 2:   //ִ�г�ջ����
            flag = Pop(S, e);  //ִ�г�ջ��������ɾջ��Ԫ�ص�ֵ��e���أ�flag��ʾ��ջ�����������Ϊtrue,��Ϊfalse
            if(flag)       //����ջ�����ɹ�
                cout << "Pop operator succeeded! The element that was deleted is:" << e << endl; //�����ɾջ��Ԫ�ص�ֵ
            else
                cout << "The stack is empty and cannot be popped!" << endl;
            break;
        case 3:   //���˳��ջ�ĳ��ȼ�ջ�е�Ԫ��
            cout << "Stack length is :" << StackLength(S) << ",Stack element is(From the bottom of the stack to the top of the stack)��" << endl;
            PrintStack(S);      //���ѭ������Q�е�Ԫ��
            break;

        case 4:    //���ջ��Ԫ��
            if(GetTop(S, e))
                cout << "The top element of the stack is:" << e << endl;
            else
                cout << "The stack is empty, there is no stack top element!" << endl;
            break;

        }//switch

    } while(k < 5);

    return 1;
}
























