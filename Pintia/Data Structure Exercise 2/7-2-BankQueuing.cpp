#include <bits/stdc++.h>

using namespace std;
#define MAXSIZE 1000

typedef struct {
    int *base;
    int front;
    int rear;
} Queue;

void EnQueue(Queue &Q, int e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front) {
        cout << "This Queue is full!" << endl;
        return;
    }
    Q.rear  = (Q.rear + 1) % MAXSIZE;
    Q.base[Q.rear] = e;
}

int isEmpty(Queue &Q) {
    return Q.front == Q.rear;
}

int DeQueue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "This Queue is empty!" << endl;
        return -1;
    }
    Q.front = (Q.front + 1) % MAXSIZE;
    return Q.base[Q.front];
}

void initQueue(Queue &Q) {
    Q.base = new int[MAXSIZE];
    if(!Q.base) {
        exit(-2);
    }
    Q.front = Q.rear = 0;
}

int main() {
    int N, i, number, flag;
    Queue A, B;
    initQueue(A);
    initQueue(B);
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> number;
        if (number % 2)
            EnQueue(A, number);
        else
            EnQueue(B, number);
    }
    flag = 0;
    while (!isEmpty(A) && !isEmpty(B)) {
        if (!flag) {
            cout << DeQueue(A);
            flag = 1;
        } else {
            cout << " " << DeQueue(A);
        }
        if (!isEmpty(A)) {
            cout << " " << DeQueue(A);
        }
        cout << " " <<  DeQueue(B);
    }
    while (!isEmpty(A)) {
        if (!flag) {
            cout << DeQueue(A);
            flag = 1;
        } else {
            cout << " " << DeQueue(A);
        }
    }
    while (!isEmpty(B)) {
        if (!flag) {
            cout << DeQueue(B);
            flag = 1;
        } else {
            cout << " " << DeQueue(B);
        }
    }
    cout << endl;
}
























