#include <bits/stdc++.h>
#define MAXSIZE 1000001
#define OVERFLOW -2

using namespace std;

typedef struct {
    int length;
    int *elem;
} Sqlist;

void InitSqlist(Sqlist &L) {
    L.elem = new int[MAXSIZE];
    if (L.elem == NULL)
        exit(OVERFLOW);
    L.length = 0;
}

void CreatList(Sqlist &L, int n) {
    for (int i = 0; i < n; i++) {
        cin >> L.elem[i];
    }
    L.length = n;
}

void getMaxLength(Sqlist L, int n) {
    int max = 0, count = 0, i;
    int flagstart = 0, left = 0, right = 0;
    for (i = 0; i < n - 1; i++) {
        right = i + 1;
        if (L.elem[i + 1] > L.elem[i]) {
            count++;
            if (count > max) {
                max = count;
                flagstart = left;
            }
        } else {
            count = 0;
            left = right;
        }
    }
    for (i = flagstart; i <= flagstart + max - 1; i++) {
        cout << L.elem[i] << " ";
    }
    cout << L.elem[i];
}

int main() {
    Sqlist L;
    int n;
    InitSqlist(L);
    cin >> n;
    CreatList(L, n);
    getMaxLength(L, n);
    return 0;
}




