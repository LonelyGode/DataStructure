#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;

} LNode, *LinkList;
int n = 0;
void InitList(LinkList &L) {
    L = new LNode;
    L->next = NULL;

}
int creatlist(LinkList &L) {
    LNode *s, *r;
    r = L;
    int a;
    scanf("%d", &a);
    while(a >= 0) {
        s = new LNode;
        s->data = a;
        r->next = s;
        r = s;
        scanf("%d", &a);
        n++;
    }
    r->next = NULL;

}

void printLk(LinkList L, int k) {

    LNode *p;
    if(n < k) {
        cout << "NULL";
        return;
    } else {
        p = L;
        for(int i = 0; i <= n - k; i++) {
            p = p->next;
        }
        cout << p->data << endl;
    }
}


int main(int argc, char** argv) {
    int a, k, i;
    LinkList L;
    LNode *p;
    cin >> k;
    InitList(L);
    creatlist(L);
    printLk(L, k);
    return 0;
}




