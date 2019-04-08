#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

char temp;

typedef struct {
    char *base;
    char *top;
    int stacksize;
} SqStack;

void InitStack(SqStack &S) {
    S.base = new char[MAXSIZE];
    S.top = S.base;
    S.stacksize = MAXSIZE;
}

void Push(SqStack &S, char &e) {
    *S.top++ = e;
}

bool Pop(SqStack &S) {
    if(S.top == S.base) {
        return false;
    }
    *--S.top;
    return true;
}

char GetTop(SqStack S) {
    if (S.top != S.base)
        return *(S.top - 1);
}

bool IsEmpty(SqStack &S) {
    if(S.top == S.base) {
        return false;
    }
    return true;
}

bool SymbolPairing(SqStack &S) {
    char ch[MAXSIZE];
    bool flag = true;
    while(cin >> ch) {
        if(ch[0] == '.' && ch[1] == '\0') {
            break;
        }
        for(int i = 0; ch[i] != '\0'; i++) {
            if(ch[i] == '/' && ch[i + 1] == '*') {
                Push(S, ch[i]);
                Push(S, ch[i + 1]);
                i++;
            } else if(ch[i] == '(' || ch[i] == '[' || ch[i] == '{') {
                Push(S, ch[i]);
            } else if(ch[i] == '*' && ch[i + 1] == '/') {
                if(IsEmpty(S) && GetTop(S) == '*') {
                    Pop(S);
                    if(IsEmpty(S) && GetTop(S) == '/') {
                        Pop(S);
                    } else {
                        flag = false;
                        temp = ch[i];
                        break;
                    }
                } else {
                    flag = false;
                    temp = ch[i];
                    break;
                }
            } else if(ch[i] == ')') {
                if(IsEmpty(S) && GetTop(S) == '(') {
                    Pop(S);
                } else {
                    flag = false;
                    temp = ch[i];
                    break;
                }
            } else if(ch[i] == ']') {
                if(IsEmpty(S) && GetTop(S) == '[') {
                    Pop(S);
                } else {
                    flag = false;
                    temp = ch[i];
                    break;
                }
            } else if(ch[i] == '}') {
                if(IsEmpty(S) && GetTop(S) == '{') {
                    Pop(S);
                } else {
                    flag = false;
                    temp = ch[i];
                    break;
                }
            }
        }
    }
    if(!IsEmpty(S) && flag) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char** argv) {
    SqStack S;
    InitStack(S);
    if(SymbolPairing(S)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        if(IsEmpty(S)) {
            switch(GetTop(S)) {
            case '(':
                cout << "(";
                break;
            case '{':
                cout << "{";
                break;
            case '[':
                cout << "[";
                break;
            case '*':
                cout << "/*";
            }
            cout << "-?" << endl;
        } else {
            cout << "?-";
            switch(temp) {
            case ')':
                cout << ")";
                break;
            case ']':
                cout << "]";
                break;
            case '}':
                cout << "}";
            case '*':
                cout << "*/";
            }
            cout << endl;
        }
    }
    return 0;
}











