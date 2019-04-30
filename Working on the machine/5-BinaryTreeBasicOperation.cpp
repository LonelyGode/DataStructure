/*
	��ʵ����Ҫʵ�ֶ������Ļ����������������н��ֵ������Ϊchar
	��ʵ����Ҫʵ��5��������
	1��void CreatBitree(BiTree &T)  //���������������������У��������ַ�'#'��ʾ����������������T
	2��void InOrderTraverse(BiTree T)   //�������������T
	3��void PreOrderTraverse(BiTree T)  //�������������T
	4��void PostOrderTraverse(BiTree T)  //�������������T
	5��bool SearchTree(BiTree T,char ch,BiTree &p)  //�ڶ�����T�в���ֵΪch�Ľ�㣬���ҳɹ�����������true,pָ��ý��,����������false��pΪ��
	6��int Depth(BiTree T) //�������T�����
	7��int NodeCount(BiTree T)  //�������T�н��ĸ���
	8��int LeafCount(BiTree T)  //�������T��Ҷ�ӽ�������
	9��int NodeCount1(BiTree T)  //�������T�ж�Ϊ1�Ľ�������
	10��int NodeCount2(BiTree T)   //�������T�ж�Ϊ2�Ľ�������
	11��int Width(BiTree T)   //�������T�Ŀ��
*/
#include <iostream>
#include <stdlib.h>

using namespace std;
//��������ṹ
typedef struct BiTNode {
    char data;      //������,��Ž��ֵ
    struct BiTNode *lchild, *rchild; //���Һ���ָ��
} BiTNode, *BiTree; // ��������

typedef struct {
    char *base;   //ջ��ָ��,ջ��Ԫ��Ϊ�ַ�
    char *top;    //ջ��ָ��
    int stacksize;   //ջ���õ��������
} SqStack;      //˳��ջ�ṹ

//���������������������У��������ַ�'#'��ʾ����������������T
void CreatBitree(BiTree &T) {
    //��ͬѧ�ǲ���˲���
    char ch;
    cin >> ch;
    if(ch == '#') {
        T = NULL;
    } else {
        T = new BiTNode;
        T->data = ch;
        CreatBitree(T->lchild);
        CreatBitree(T->rchild);
    }
}

//�������T��ֵΪch�Ľ��Ĳ�Σ������p��ʾ��curlevel��ʾ��ǰT���ڵĲ�����
//��ֵ�ɹ�����true,ʧ�ܷ���false
bool level(BiTree T, char ch, int curlevel, int &p) {
    if(T == NULL) //��TΪ����������false
        return false;
    if(T->data == ch) { //��T��ֵΪch,�������pΪcurlevel
        p = curlevel;
        return true;
    } else { //��T��ֵΪch,������T������������ch���Ĳ�������ch��㲻��T���������У�����T������������ch���Ĳ���
        if(level(T->lchild, ch, curlevel + 1, p))
            return true;
        else
            return level(T->rchild, ch, curlevel + 1, p);
    }
}

//�ڶ�����T����ֵΪch�Ľ�������,�ɹ�����true,ʧ�ܷ���false
bool ancestor(BiTree T, char ch) {
    if(T == NULL) //TΪ����ʱ������false
        return false;
    else if(T->lchild && T->lchild->data == ch ) { //��T������ֵΪch����TΪch�������ȣ����T��㣬����true
        cout << T->data << " ";
        return true;
    } else if(T->rchild && T->rchild->data == ch) { //��T���Һ���ֵΪch����TΪch�������ȣ����T���,����true
        cout << T->data << " ";
        return true;
    }
    //��T������ֵ��ch�������ȣ���TҲ��ch�����ȣ����T��㣬����true
    else if(ancestor(T->lchild, ch) || ancestor(T->rchild, ch)) {
        cout << T->data << " ";
        return true;
    } else //�������ʱ��������ֵΪch�Ľ�����ȣ���ʱֵΪch�Ľ�����Ϊ����㣬���߲����ڣ�����false
        return false;
}

//�������������T������������������
void InOrderTraverse(BiTree T) {
    //��ͬѧ�ǲ���˲���
    if(T) {
        InOrderTraverse(T->lchild);
        cout << T->data << " ";
        InOrderTraverse(T->rchild);
    }
}

//�������������T������������������
void PreOrderTraverse(BiTree T) {
    //��ͬѧ�ǲ���˲���
    if(T) {
        cout << T->data << " ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//�������������T�����������������
void PostOrderTraverse(BiTree T) {
    //��ͬѧ�ǲ���˲���
    if(T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data << " ";
    }
}

//�ڶ�����T�в���ֵΪch�Ľ�㣬���ҳɹ�����������true,pָ��ý��,����������false��pΪ��
bool SearchTree(BiTree T, char ch, BiTree &p) {
    //��ͬѧ�ǲ���˲���
    if(T) {
        SearchTree(T->lchild, ch, p);
        if(ch == T->data) {
            p = T;
        }
        SearchTree(T->rchild, ch, p);
    }
    if(p) {
        return true;  //������ò��������޸Ĵ��д���
    } else {
        return false;
    }
}

//�������T�����
int Depth(BiTree T) {
    //��ͬѧ�ǲ���˲���
    if(!T) {
        return 0;
    } else {
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if(m > n) {
            return m + 1;
        } else {
            return n + 1;
        }
    }
}

//�������T�Ŀ��
int Width(BiTree T) {
    //��ͬѧ�ǲ���˲���
    BiTree q[100];  //qΪһ��˳����У���ͷ�Ͷ�βΪfront��rear
    //end��¼��ǰ�����һ������λ�ã�length��ʾ��ǰ��Ŀ�ȣ�maxwidth��ʾT�Ŀ��
    int front = 0, rear = 0, end, length = 0, maxwidth = 0;
    q[rear] = T; //��������
    rear++;
    end = rear; //��¼��ǰ�㣨��һ�㣩�Ľ���λ�ã����һ������λ�ã�
    while(front != rear) { //�����зǿ�ʱ�����δ���ÿһ���еĽ��
        if(front < end) //����ǰ�㻹�н��û�����꣬��ǰ��������һ
            length++;
        else { //����ǰ���н���Ѵ����꣬��ʱ����ǰ��Ŀ��Ϊlength
            maxwidth = max(length, maxwidth); //��ǰ�������������
            end = rear; //��¼��һ��Ľ���λ��
            length = 1; //��������һ����ǰ����length����Ϊһ
        }
        BiTNode *s = q[front]; //��ͷ�����ӣ���s��ʾ�ý��
        front++;
        if(s->lchild) { //��s�����ӣ��������������
            q[rear] = s->lchild;
            rear++;
        }
        if(s->rchild) { //��s���Һ��ӣ��������Һ������
            q[rear] = s->rchild;
            rear++;
        }
    }
    maxwidth = max(length, maxwidth); //������Ϊ��ʱ����Ҫ���������һ��Ŀ�ȣ��Ի�ȡ���յ�maxwidth
    return maxwidth; //������õĶ������Ŀ��
}

//����TΪ���Ķ��������в�����������������
void LevelTraverse(BiTree T) {
    BiTree q[100];  //����˳�����q,��ͷΪfront,��βΪrear
    int front = 0, rear = 0;
    q[rear] = T; //��������
    rear++;
    while(front != rear) { //�����зǿ�ʱ������ɾ����ͷԪ�ز�����������亢���������
        BiTNode *s = q[front]; //ɾ����ͷԪ�أ�s��ʾ�������
        cout << s->data << " ";
        front++;
        if(s->lchild) { //��s�����ӣ��������
            q[rear] = s->lchild;
            rear++;
        }
        if(s->rchild) { //��s���Һ��ӣ��Һ������
            q[rear] = s->rchild;
            rear++;
        }
    }
}

//�������T�н������
int NodeCount(BiTree T) {
    //��ͬѧ�ǲ���˲���
    if(!T) {
        return 0;
    } else {
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    }
}

//�������T��Ҷ�ӽ������
int LeafCount(BiTree T) {
    //��ͬѧ�ǲ���˲���
    if(!T) {
        return 0;
    }
    if(!T->lchild && !T->rchild) {
        return 1;
    }
    return LeafCount(T->lchild) + LeafCount(T->rchild); //������ò��������޸Ĵ��д���
}

//�������T�ж�Ϊ1�Ľ������
int NodeCount1(BiTree T) {
    //��ͬѧ�ǲ���˲���
    if(!T) {
        return 0;
    }
    if((T->lchild && !T->rchild) || (!T->lchild && T->rchild)) {
        return NodeCount1(T->lchild) + NodeCount1(T->rchild) + 1;
    } else {
        return NodeCount1(T->lchild) + NodeCount1(T->rchild);
    }
    //������ò��������޸Ĵ��д���
}

//�������T�ж�Ϊ2�Ľ������
int NodeCount2(BiTree T) {
    //��ͬѧ�ǲ���˲���
    if(!T) {
        return 0;
    }
    if(T->lchild && T->rchild) {
        return NodeCount2(T->lchild) + NodeCount2(T->rchild) + 1;
    } else {
        return NodeCount2(T->lchild) + NodeCount2(T->rchild);
    }
    //������ò��������޸Ĵ��д���
}

int main() {
    BiTree T, p = NULL;    //TΪ��������Ҫ�����Ķ�������
    char ch;    //ch��ʾ�ڶ�������Ҫ��ѯ�Ľ��
    bool flag;
    cout << "Please enter the binary tree to be created, input in the preamble sequence, empty tree replaced with the character '#':" << endl;
    CreatBitree(T);  //��������Ķ������������У�������������T
    cout << "The result of the sequence traversal is:" << endl;
    LevelTraverse(T);
    cout << endl << "Please enter the node to be queried:";
    cin >> ch;
    int n;
    level(T, ch, 1, n); //��ֵΪch���Ĳ�������ʼʱ���Ĳ���Ϊ1
    cout << "The level of the node is:" << n << endl;
    cout << "The ancestor of the node is:";
    flag = ancestor(T, ch);
    if(flag == false) {
        cout << "No ancestor node!" << endl;
    }
    cout << endl << "The result of the in-order traversal is:��" << endl;
    InOrderTraverse(T);      //���������T�������������
    cout << endl << "The preorder traversal result is:" << endl;
    PreOrderTraverse(T);     //���������T�������������
    cout << endl << "The post-order traversal result is:" << endl;
    PostOrderTraverse(T);    //���������T�ĺ����������
    cout << endl << "Please enter the node you want to find in the binary tree:";
    rewind(stdin);   //������뻺����
    cin >> ch;
    flag = SearchTree(T, ch, p); //�ڶ�����T�в���ֵΪch1�Ľ��
    if(flag) {
        cout << "Find success in the binary tree!" << endl;
    } else {
        cout << "There is no node with a value of " << ch << " in the binary tree!" << endl;
    }
    cout << "The depth of the binary tree is:" << Depth(T) << endl;
    cout << "The width of the binary tree is:" << Width(T) << endl;
    cout << "The number of points in the binary tree is:" << NodeCount(T) << endl;
    cout << "The number of leaf nodes, the degree of 1 node, and the degree of 2 nodes are:" << LeafCount(T) << "," << NodeCount1(T) << "," << NodeCount2(T) << endl;
    return 0;
}













