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

void EnQueue (SqQueue &Q, char e) {
    if((Q.rear + 1) % l == Q.front) {
        cout << "Full Queue" << endl;
        return;
    }
    Q.base[Q.rear ] = e;
    Q.rear = (Q.rear + 1) % l;
}

void DeQueue(SqQueue &Q) {
    if(Q.front == Q.rear) {
        cout << "Empty Queue" << endl;
        return;
    }
    Q.front = (Q.front + 1 ) % l ;
}

int main() {
    int m;
    cin >> m >> l;
    cout << "L: " <<  l << endl;
    SqQueue Q;
    InitQueue(Q, l);
    string command;
    int number;
    for(int i = 0; i < m; i++) {
        cin >> command;
        // number = 0;
        if(command == "DeQueue") {
            DeQueue(Q);
        }
        if(command == "EnQueue") {
            cin >> number;
            EnQueue(Q, number);
        }
    }
}

































