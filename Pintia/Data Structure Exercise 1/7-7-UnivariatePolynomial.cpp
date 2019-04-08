#include <bits/stdc++.h>
using namespace std;

typedef struct LNode {
    int coefficient;
    int exponent;
    struct LNode *next;
} LNode, *LinkList;

bool flag = true;

void InitList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
}

void CreateList(LinkList &L, int l) {
    LNode *p, *s, *r;
    r = L;
    for(int i = 0; i < l; i++) {
        s = new LNode;
        if(abs(s->coefficient) < 1000 && abs(s->exponent) < 1000 ) {
            if(s->coefficient == 0) {
                s->coefficient = 0;
                s->exponent = 0;
            }
            cin >> s->coefficient;
            cin >> s->exponent;
        }
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void AppendList(int coefficient, int exponent, LinkList &endR) {
    LNode *s;
    s = new LNode;
    s->coefficient = coefficient;
    s->exponent = exponent;
    endR->next = s;
    endR = s;
    endR->next = NULL;
}

void PrintResult(LinkList L) {
    flag = true;
    LNode *p = L->next;
    while(p) {
        if(!flag) {
            cout << " " << p->coefficient << " " << p->exponent;
        } else {
            flag = false;
            cout << p->coefficient << " " << p->exponent;
        }
        p = p->next;
    }
}

LinkList PolynomialAddition(LinkList L1, LinkList L2) {
    LinkList p1, p2, R, endR;
    p1 = L1->next;
    p2 = L2->next;
    InitList(R);
    endR = R;
    while(p1 && p2) {
        if(p1->exponent == p2->exponent) {
            if(p1->coefficient + p2->coefficient) {
                AppendList(p1->coefficient + p2->coefficient, p1->exponent, endR);
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if(p1->exponent > p2->exponent) {
            AppendList(p1->coefficient, p1->exponent, endR);
            p1 = p1->next;
        } else {
            AppendList(p2->coefficient, p2->exponent, endR);
            p2 = p2->next;
        }
    }
    while(p2) {
        AppendList(p2->coefficient, p2->exponent, endR);
        p2 = p2->next;
    }
    while(p1) {
        AppendList(p1->coefficient, p1->exponent, endR);
        p1 = p1->next;
    }
    if(!R->next) {
        AppendList(0, 0, endR);
    }
    return R;
}

LinkList PolynomialMultiplication(LinkList L1, LinkList L2) {
    LinkList tR, R;
    LNode *p1, *p2, *endR;
    p1 = L1->next;
    p2 = L2->next;
    InitList(tR);
    InitList(R);
    endR = tR;
    if(!p1 || !p2) {
        return NULL;
    }
    if(p1->coefficient == 0 || p2->coefficient == 0) {
        AppendList(0, 0, endR);
    }
    while(p1) {
        while(p2) {
            AppendList(p1->coefficient * p2->coefficient, p1->exponent + p2->exponent, endR);
            p2 = p2->next;
        }
        p2 = L2->next;
        R = PolynomialAddition(R, tR);
        InitList(tR);
        endR = tR;
        p1 = p1->next;
    }
    return R;
}


int main(int argc, char** argv) {
    LinkList L1, L2;
    int l1, l2;
    cin >> l1;
    InitList(L1);
    CreateList(L1, l1);
    cin >> l2;
    InitList(L2);
    CreateList(L2, l2);
    PrintResult(PolynomialMultiplication(L1, L2));
    cout << endl;
    PrintResult(PolynomialAddition(L1, L2));
    return 0;
}











