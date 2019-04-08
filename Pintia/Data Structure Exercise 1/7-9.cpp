#include <bits/stdc++.h>
#define MAXSIZE 100

using namespace std;

typedef struct {
    char *base;
    char *top;
    int stacksize;
} SqStack;

void InitStack(SqStack &S, int m) {
    S.stacksize = m;
    S.base = new char[m];
    S.top = S.base;
}

int Push(SqStack &S) {
    if (S.top - S.base == S.stacksize) {
        return 0;
    }
    S.top++;
    return 1;
}

bool Pop(SqStack &S) {
    if (S.top == S.base)
        return false;
    --S.top;
    return true;
}

bool isRight(char *s, int m) {
    SqStack S;
    InitStack(S, m);
    bool flag = true;
    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] == 'S') {
            if (!Push(S)) {
                flag = false;
                break;
            }
        } else {
            if(!Pop(S)) {
                flag = false;
                break;
            }
        }
    }
    if (S.top != S.base)
        return false;
    if (s[i] != '\0')
        return false;
    return true;
}

int main() {
    int T, m;
    cin >> T;
    cin >> m;
    while (T--) {
        char s[MAXSIZE];
        cin >> s;
        if (isRight(s, m))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

}



