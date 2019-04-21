/*
   ��ʵ����Ҫ���ѭ�����л���������ʵ�֣�ѭ�������е�Ԫ������Ϊ�ַ��ͣ�char��
   ��Ҫʵ�ֵĻ�������Ϊ��
   1��ѭ�����еĳ�ʼ��
   2����Ӳ���
   3�����Ӳ���
   4��ȡ��ͷԪ��
   5��ȡ��βԪ��
   6����ѭ�����еĳ���
   7�����ѭ�������е�Ԫ��
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
#define MAXSIZE 5    //ѭ�����г�ʼ��ʱ����Ĵ洢�ռ䳤��
#define OVERFLOW -2

typedef struct {
    char *base;   //�洢�ռ��ַ�������д洢��Ԫ�����ַ�
    int front;    //��ͷָ��
    int rear;   //��βָ��
} SqQueue;      //ѭ�����нṹ

//��ʼ��ѭ������Q
void InitQueue(SqQueue &Q) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    Q.base = new char[MAXSIZE];
    if(!Q.base) {
        exit(OVERFLOW);
    }
    Q.front = Q.rear = 0;
}

//��Ӳ�������ѭ������Q�Ķ�β������Ԫ��e������ɹ�������true,����ʧ�ܣ�����false
bool EnQueue(SqQueue &Q, char e) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    if((Q.rear + 1) % MAXSIZE == Q.front) {
        return false;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

//���Ӳ�����ɾ��ѭ������Q�Ķ�ͷԪ�أ���ɾԪ���ò���e���أ�ɾ���ɹ�����������true,ɾ��ʧ�ܣ���������false
bool DeQueue(SqQueue &Q, char &e) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    if(Q.front == Q.rear) {
        return false;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1 ) % MAXSIZE ;
    return true;
}

//ȡѭ������Q�Ķ�ͷԪ�أ��ò���e����ȡ�õĶ�ͷԪ��
bool GetHead(SqQueue Q, char &e) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    if(Q.front != Q.rear) {
        e = Q.base[Q.front];
        return true;
    } else {
        return false;
    }
}

//ȡѭ������Q�Ķ�βԪ�أ��ò���e����ȡ�õĶ�βԪ��
bool GetTail(SqQueue Q, char &e) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    if(Q.front != Q.rear) {
        e = Q.base[(Q.rear + MAXSIZE) % MAXSIZE - 1];
        return true;
    } else {
        return false;
    }
}

//��ѭ������Q�ĳ���
int QueueLength(SqQueue Q) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    int length;
    length = (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
    return length;
}

//���ѭ������Q�е�Ԫ�أ��Ӷ�ͷ����β��˳�������
void PrintQueue(SqQueue Q) {
    //��ͬѧ���ڴ˴��Ѹò�������������������
    int l = QueueLength(Q);
    for(int i = 0; i < l; i++) {
        cout << Q.base[(Q.front + i) % MAXSIZE] << " ";
    }
    cout << endl;
}


//�����˵�
void showmenu() {
    cout << "*****************************************************************" << endl;
    cout << "1.EnQueue      2.DeQueue       3.PrintQueue" << endl;
    cout << "4.GetHead      5.GetTail       6.EXIT" << endl;
}

int main() {
    SqQueue Q;       //����ѭ������Q
    int k;
    char e;
    bool flag;
    InitQueue(Q);    //��ʼ��ѭ������Q
    cout << "Cycliec queue Q initialized successfully!" << endl;

    //ѭ����ʾ�˵������ѭ�����е�һϵ�в���
    do {
        showmenu();
        cout << "Please select the serial number of the operation:" << endl;
        rewind(stdin);
        cin >> k;  //k��ʾ�û�ѡ��Ĳ������
        switch(k) {
        case 1:    //ִ����Ӳ���
            cout << "Please enter the value of the queue:" << endl;
            cin >> e;    //����Ҫ���뵽��β����ֵ
            flag = EnQueue(Q, e); //ִ����Ӳ�����,flag��ʾ��ջ�����������Ϊtrue,��Ϊfalse
            if(flag)       //����Ӳ����ɹ�
                cout << "EnQueue operator succeeded!" << endl;
            else
                cout << "Queue is full, EnQueue operator failed!" << endl;
            break;
        case 2:   //ִ�г��Ӳ���
            flag = DeQueue(Q, e);  //ִ�г��Ӳ�������ɾ��ͷԪ�ص�ֵ��e���أ�flag��ʾ��ջ�����������Ϊtrue,��Ϊfalse
            if(flag)       //�����Ӳ����ɹ�
                cout << "DeQueue operator succeeded! The element that was deleted is:" << e << endl; //�����ɾ��ͷԪ�ص�ֵ
            else
                cout << "The Queue is empty and cannot be DeQueue!" << endl;
            break;
        case 3:   //������еĳ��ȼ������е�Ԫ��
            cout << "Queue length is:" << QueueLength(Q) << ",Queue element is(From the bottom of the queue to the top of the queue ):" << endl;
            PrintQueue(Q);      //���ѭ������Q�е�Ԫ��
            break;

        case 4:    //�����ͷԪ��
            if(GetHead(Q, e))
                cout << "The head of queue is:" << e << endl;
            else
                cout << "The queue is empty , don't have head!" << endl;
            break;
        case 5:   //�����βԪ��
            if(GetTail(Q, e))
                cout << "The tail of queue is:" << e << endl;
            else
                cout << "The queue is empty, don't have tail!" << endl;
            break;
        }//switch

    } while(k < 6);
    return 1;
}











































