#include <bits/stdc++.h>
using namespace std;

typedef struct StackNode {
    char data;
    struct StackNode *next;
} StackNode, *LinkStack;

void InitStack(LinkStack &S) {
    S = NULL;
}

void Push(LinkStack &S, char e) {
    StackNode *p = new StackNode;
    p->data = e;
    p->next = s;
    s = p;
}

void Pop(LinkStack &S, char &e) {
    e = S->data;
    StackNode *p = new StackNode;
    p = S;
    S = S->next;
    delete p;
}

void PrintReault(char result) {
switch result:
}

int main(int argc, char** argv) {

}

