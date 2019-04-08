#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

int InitList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
    return 1;
}

void CreateList(LinkList &L, int n) {
    L = new LNode;
    L->next = NULL;
    struct LNode *r;
    r = L;
    for(int i = 0; i < n; i++) {
        struct LNode *s;
        s = new LNode;
        s->data = rand() % 100 + 1;
        s->next = NULL;
        r->next = s;
        r = s;
    }
}

void showList(LinkList L) {
    LinkList p;
    p = L->next;
    while(p) {
        cout << p->data << endl;
        p = p->next;
    }
}

void exchangeValues(LinkList L) {
    LinkList pmax, pmin, p;
    pmax = L->next;
    pmin = L->next;
    p = L->next;
    while(p) {
        if(p->data > pmax->data) {
            pmax = p;
        }
        if(p->data < pmin->data) {
            pmin = p;
        }
        p = p->next;
    }
    cout << "Max:" << pmax->data << endl;
    cout << "Min:" << pmin->data << endl;
    pmax->data = pmax->data ^ pmin->data;
    pmin->data = pmax->data ^ pmin->data;
    pmax->data = pmax->data ^ pmin->data;
    cout << "Exchange values success!" << endl;
}

int main() {
    LinkList L;

    if(InitList(L)) {
        cout << "Success!"  << endl;
    } else {
        cout << "Failure!" << endl;
    }
    cout << "Length:";
    int n;
    cin >> n;
    CreateList(L, n);
    showList(L);
    exchangeValues(L);
    showList(L);
}





