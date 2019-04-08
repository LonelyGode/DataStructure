#include <bits/stdc++.h>
#define MAXSIZE 100

using namespace std;

bool flag = true;

typedef struct {
    char *base;
    char *top;
    int stacksize;
} SqStack;

void InitStack(SqStack &S, int l) {
    S.base = new char[l];
    S.top = S.base;
    S.stacksize = l;
}

void Push(SqStack &S, char e) {
    if(S.top - S.base == S.stacksize) {
        flag = false;
    } else {
        *S.top++ = e;
        flag = true;
    }
}

void Pop(SqStack &S) {
    if(S.top == S.base) {
        flag = false;
    } else {
        *--S.top;
        flag = true;
    }
}

bool IsEmpty(SqStack S) {
    if(S.top == S.base) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char** argv) {
    int n, l, k, j;
    cin >> n >> l;
    SqStack S;
    InitStack(S, l);
    char ch[MAXSIZE];
    for(int i = 0; i < n; i++) {
        cin >> ch;
        k = strlen(ch);
        if(k > 100) {
            cout << "NO" << endl;
        }
        for(j = 0; j < k; j++) {
            if(ch[j] == 'S') {
                Push(S, 'S');
            } else {
                Pop(S);
            }
        }
        if(ch[j] != '\0') {
            flag = false;
        }
        if(IsEmpty(S) && flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

























