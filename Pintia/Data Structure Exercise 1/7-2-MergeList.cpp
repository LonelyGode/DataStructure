#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool flag = true;

void InitList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
}

void CreateList(LinkList &L) {
    LNode *p, *s, *r;
    r = L;
    int a;
    cin >> a;
    while(a != -1) {
        s = new LNode;
        s->data = a;
        r->next = s;
        r = s;
        cin >> a;
    }
    r->next = NULL;
}

void MergeList(LinkList L1, LinkList L2) {
    LNode *p1, *p2;
    p1 = L1->next;
    p2 = L2->next;
    while(p1 || p2) {
        if(p1->data < p2->data) {
            if(!flag) {
                cout << " " << p1->data;
            } else {
                flag = false;
                cout << p1->data;
            }
            p1 = p1->next;
        } else {
            if(!flag) {
                cout << " " << p2->data;
            } else {
                flag = false;
                cout << p2->data;
            }
            p2 = p2->next;
        }
        if(!p1) {
            while(p2) {
                cout << " " << p2->data;
                p2 = p2->next;
            }
        }
        if(!p2) {
            while(p1) {
                cout << " " << p1->data;
                p1 = p1->next;
            }
        }
    }
    if(flag)
        cout << "NULL";
}

int main(int argc, char** argv) {
    LinkList L1, L2;
    InitList(L1);
    InitList(L2);
    CreateList(L1);
    CreateList(L2);
    MergeList(L1, L2);
    return 0;
}




























