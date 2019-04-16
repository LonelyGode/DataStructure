#include <iostream>
#include <string.h>
using namespace std;

#define MAXLEN 1000000
typedef struct {
    char ch[MAXLEN + 1];
    int length;
} SString;

void get_next(SString T, int next[]) {
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i < T.length) {
        if(j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

bool Index_KMP(SString S, SString T, int next[], int pos) {
    int i = pos;
    int j = 0;
    while(i <= S.length && j <= T.length) {
        if(j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if(j > T.length) {
        cout << i - T.length - 1;
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    SString S, T;
    int next[100001], len;
    fgets(S.ch + 1, MAXLEN, stdin);
    len = strlen(S.ch + 1);
    if(S.ch[len] == '\n')
        S.ch[len] = '\0';
    S.length = strlen(S.ch + 1);
    fgets(T.ch + 1, MAXLEN, stdin);
    len = strlen(T.ch + 1);
    if(T.ch[len] == '\n')
        T.ch[len] = '\0';
    T.length = strlen(T.ch + 1);
    memset(next, 0, sizeof(next));
    get_next(T, next);
    if(!Index_KMP(S, T, next, 0)) {
        cout << "-1";
    }
    return 0;
}




