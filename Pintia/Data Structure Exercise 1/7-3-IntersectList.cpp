#include <bits/stdc++.h>   //���ܵ�ͷ�ļ�������C++�����е�ͷ�ļ� 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;   //������洢�ṹ����

bool flag = true; //��־�������ж��Ƿ��ǽ����еĵ�һ��Ԫ�ؽ������
int n = 0; //ȫ�ֱ����������жϽ����е�Ԫ�ظ���

void InitList(LinkList &L) {  //��ʼ��������L
    L = new LNode;
    L->next = NULL;
}

void CreateList(LinkList &L) { //������L�в������� ��ʹ�ú�巨����������L
    LNode *p, *s, *r;
    r = L;
    int a;
    cin >> a; //�����һ������
    while(a != -1) { //�ж��Ƿ��������������������ı�־Ϊ-1
        s = new LNode; //�����½��s���ú�巨���뵽L��
        s->data = a;
        r->next = s;
        r = s;
        cin >> a;	 //���ζ�����еĺ�������
    }
    r->next = NULL; //��L�����һ�����ָ�����ÿ�
}

//������L1��L2�Ľ������������õĽ���
void IntersectList(LinkList L1, LinkList L2) {
    LNode *p1, *p2;
    p1 = L1->next;
    p2 = L2->next;
    while(p1 && p2) { //�����ж�P1��p2��ָ���Ĵ�С��������Ӧ�Ĵ���
        if(p1->data == p2->data) {
            if(!flag) { //������ǽ����е���Ԫ�������flag==false)���������һ���ո�
                cout << " " << p1->data;
                n++;  //��õĽ���Ԫ��������1
            } else { //��������Ԫ�ص����������Ԫ��ǰû�пո�
                flag = false;
                cout << p1->data;
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if(p1->data < p2->data)
            p1 = p1->next;
        else
            p2 = p2->next;
    }
    if(n == 0) //������Ԫ�ظ���Ϊ0�������NULL
        cout << "NULL";
}

int main(int argc, char** argv) {
    LinkList L1, L2; //���嵥����L1��L2
    InitList(L1);   //��ʼ��������L1��L2
    InitList(L2);
    CreateList(L1);	//��L1��L2�в���Ԫ��
    CreateList(L2);
    IntersectList(L1, L2); //��L1��L2�Ľ��������
    return 0;
}



