#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int l;

typedef struct {
    int *base;
    int front;
    int rear;
} SqQueue;

void InitQueue(SqQueue &Q, int  l) {
    Q.base = new int[l];
    if(!Q.base) {
        exit(-2);
    }
    Q.front = Q.rear = 0;
}

void EnQueue (SqQueue &Q, int  e) {
    if(Q.rear == l) {
        cout << "Full Queue" << endl;
        return;
    }
    Q.base[Q.rear] = e;
    Q.rear++;
}

void DeQueue(SqQueue &Q) {
    if(Q.front == Q.rear) {
        cout << "Empty Queue" << endl;
    } else {
        cout << Q.base[0] << endl;
        for(int i = 0; i < Q.rear; i++) {
            Q.base[i] = Q.base[i + 1];
        }
        Q.rear--;
    }
}

void DeleteMid(SqQueue &Q) {
    if(Q.front == Q.rear) {
        cout << "Empty Queue" << endl;
        return;
    }
    int mid;
    if(Q.rear % 2) {
        mid = (Q.rear + 1) / 2;
    } else {
        mid = Q.rear / 2;
    }
    mid--;
    cout << Q.base[mid] << endl;
    for(int i = mid; i < Q.rear; i++) {
        Q.base[i] = Q.base[i + 1];
    }
    Q.rear--;
}

void PrintQueue(SqQueue Q) {
    bool flag = true;
    for(int i = 0; i < Q.rear ; i++) {
        if(flag) {
            cout << Q.base[i];
            flag = false;
        } else {
            cout << " " << Q.base[i];
        }
    }
}

int main() {
    int m;
    cin >> m >> l;
    if(m < 1000000 && l < 1000000) {

        SqQueue Q;
        InitQueue(Q, l);
        string command;
        int number;
        for(int i = 0; i < m; i++) {
            cin >> command;
            if(command == "DeQueue") {
                DeQueue(Q);
            }
            if(command == "EnQueue") {
                cin >> number;
                EnQueue(Q, number);
            }
            if(command == "DeleteMid") {
                DeleteMid(Q);
            }
        }
        PrintQueue(Q);
    }
}


