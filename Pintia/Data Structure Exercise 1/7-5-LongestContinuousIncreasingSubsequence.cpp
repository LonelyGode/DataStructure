#include <bits/stdc++.h>

using namespace std;

bool flag = true;

typedef struct {
    int *elem;
    int length;
} Sqlist;


void InitList(Sqlist &L) {
    L.elem = new int[100];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
}

void CreateList(Sqlist &L, int n) {
    int i;
    for(i = 0; i < n; i++) {
        cin >> L.elem[i];
    }
    L.length = n;
}


void LongestSubsequence(Sqlist L) {
    int n = 0, m = 0;
    int mark  = 1;
    for(int i = 0; i < L.length - 1; i++) {
        if(L.elem[i] < L.elem[i + 1]) {
            m++;
        } else {
            if(m > n) {
                n = m;
                mark = i + 1 - m;
            }
            m = 1;
        }
    }
    for(int i = mark; i < mark + n; i++) {
        if(!flag) {
            cout << " " << L.elem[i];
        } else {
            flag = false;
            cout << L.elem[i];
        }
    }
}

int main(int argc, char** argv) {
    int n;
    Sqlist L;
    InitList(L);
    cin >> n;
    CreateList(L, n);
    LongestSubsequence(L);
}




