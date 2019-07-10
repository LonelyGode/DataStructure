/*
   ��ʵ����Ҫʵ�ֶ����������Ļ�����������¼�ؼ��ֵ�����Ϊint
   ��ʵ����Ҫʵ��7��������
   1��void InsertBST(BSTree &T,ElemType e)
//�ڶ���������T�в���һ���ؼ���Ϊe.key���½��
2��void CreateBST(BSTree &T)
//��������������T
3��void InorderBST(BSTree T)
//���������������������ؼ���ֵ
4��BSTree SearchBST(BSTree T,int key)
//�ڶ���������T�У����ҹؼ���Ϊkey�Ľ�㣬�����ҳɹ������ظý���ַ�����򣬷��ؿ�ָ��
5��void Delete(BSTree &T,BSTNode *p,BSTNode *f)
//�ڶ���������T��ɾ��p��ָ��㣬fΪp��˫��
6��bool DeleteBST(BSTree &T,int key)
//ɾ������������T�йؼ��ֵ���key�Ľ�㣬ɾ���ɹ�������true��ɾ��ʧ�ܣ�����false
7��BSTree SearchBST_A(BSTree T,int key)
//�ڶ���������T�а��շǵݹ鷽�����ҹؼ���Ϊkey�Ľ�㣬���ҳɹ������ظý���ַ������ʧ�ܣ�����NULL
 */

#include <iostream>
using namespace std;
//����Ԫ������ElemType����
typedef struct {
    int key;           //�ؼ�����
    char *otherinfo;   //������
} ElemType;

//��������ṹ����
typedef struct BSTNode {
    ElemType data;                    //������
    struct BSTNode *lchild, *rchild;  //����ָ����
} BSTNode, *BSTree;


//�ڶ���������T�в���һ���ؼ���Ϊe.key���½��
void InsertBST(BSTree &T, ElemType e) {
    BSTNode *s;
    if(T == NULL) { //����������ʱ��������
        s = new BSTNode;
        s->data = e;
        s->lchild = s->rchild = NULL;
        T = s;
    } else if(e.key < T->data .key ) //���������в�����
        InsertBST(T->lchild, e);
    else if(e.key > T->data .key )   //���������в�����
        InsertBST(T->rchild, e);

}

//��������������T
void CreateBST(BSTree &T) {
    ElemType e;
    T = NULL;             //��ʼʱ������������TΪ����
    cout << "Please enter the key value of each node (integer, separated by space or enter), ending with -1:" << endl;
    cin >> e.key ;
    while(e.key != -1) {  //��һ���½����뵽����������T��
        InsertBST(T, e);
        cin >> e.key ;
    }
}

//���������������������ؼ���ֵ
void InorderBST(BSTree T) {
    if(T) {
        InorderBST(T->lchild);
        cout << T->data .key << "  ";
        InorderBST(T->rchild );
    }
}


//�ڶ���������T�У����ҹؼ���Ϊkey�Ľ�㣬�����ҳɹ������ظý���ַ�����򣬷��ؿ�ָ��
BSTree SearchBST(BSTree T, int key) {
    //��ͬѧ�ǽ��ò�����������
    if((!T) || key == T->data.key) {
        return T;
    } else if((!T) || key < T->data.key) {
        return SearchBST(T->lchild, key);
    } else if((!T) || key > T->data.key) {
        return SearchBST(T->rchild, key);
    }
    return T;  //������ò��ֲ����󣬽�����ɾ��
}

//�ڶ���������T�а��շǵݹ鷽�����ҹؼ���Ϊkey�Ľ�㣬���ҳɹ������ظý���ַ������ʧ�ܣ�����NULL
BSTree SearchBST_A(BSTree T, int key) {
    //��ͬѧ�ǽ��ò�����������

    return T;  //������ò��ֲ����󣬽�����ɾ��
}

//���������ڿ������
//�ڶ���������T��ɾ��p��ָ��㣬fΪp��˫��
void Delete(BSTree &T, BSTNode *p, BSTNode *f) {
    BSTNode *q, *s;
    q = p;
    if(p->rchild  && p->lchild ) { //p��ָ���������������ǿ�
        //��ͬѧ�ǲ���˲��ֲ���
        s = p->lchild;
        while(s->rchild) {
            q = s;
            s = s->rchild;
        }
        p->data = s->data;
        if(q != p) {
            q->rchild = s->lchild;
        } else {
            q->lchild = s->lchild;
        }
        delete s;
        return;
    } else if(p->rchild == NULL) { //p��ָ���ֻ��������
        //��ͬѧ�ǲ���˲��ֲ���
        p = p->lchild;

    } else if(p->lchild == NULL) { //p��ָ���ֻ��������
        //��ͬѧ�ǲ���˲��ֲ���
        p = p->lchild;

    }
    if(f == NULL) T = NULL; //Tֻ��һ������㣬�ұ�ɾ�����Ǹ����
    else if(q == f->lchild )  f->lchild = p; //��ɾ�����˫��f������
    else   f->rchild = p;   //��ɾ�����˫��f���Һ���
    delete q;    //�ͷű�ɾ���
}


//ɾ������������T�йؼ��ֵ���key�Ľ�㣬ɾ���ɹ�������true��ɾ��ʧ�ܣ�����false
bool DeleteBST(BSTree &T, int key) {
    BSTNode *p = T, *f = NULL;
    while(p) {   //�Ӷ����������ĸ���ʼ�����ҹؼ���Ϊkey�Ľ�㣬����pָ������fָ��p��˫��
        if(p->data .key == key)    //�ҵ��ؼ���Ϊkey�Ľ�㣬��pָ����
            break;
        f = p;                     //fΪp��˫��
        if(p->data .key > key)     //��p���������м�������
            p = p->lchild ;
        else                       //��p���������м�������
            p = p->rchild ;
    }
    if(p == NULL)          //T�в����ڹؼ��ֵ���key�Ľ�㣬����false
        return false;
    Delete(T, p, f);       //�ڶ���������T��ɾ��p��ָ��㣨�ؼ���Ϊkey�Ľ�㣩��fָ��p��˫��
    return true;           //ɾ���ɹ�������true
}

int main() {

    BSTree T;
    int key;

    CreateBST(T);         //��������������
    cout << "The middle order traversal sequence of the binary sort tree is:" << endl;
    InorderBST(T);       //��������������������������
    cout << endl;

    //�����������Ĳ��ң��ݹ鷽ʽ��
    cout << "Please enter the value of the keyword to look for(recursively):";
    cin >> key;
    if(SearchBST(T, key) == NULL)    //�ڶ���������T�в��ҹؼ���Ϊkey�Ľ�㣬��������ҽ��
        cout << "The search failed. No node of value " << key << " exists in the binary sort tree..." << endl;
    else
        cout << "Find success!" << endl;

    //�����������Ĳ��ң��ǵݹ鷽ʽ��
    cout << "Please enter the value of the keyword to look for(non-recursive search):";
    cin >> key;
    if(SearchBST_A(T, key) == NULL)    //�ڶ���������T�в��ҹؼ���Ϊkey�Ľ�㣬��������ҽ��
        cout << "The search failed. No node of value " << key << " exists in the binary sort tree..." << endl;
    else
        cout << "Find success!" << endl;

    //����Ϊ������������ɾ������
    cout << "Please enter the value of the keyword to be deleted:";
    cin >> key;
    if(DeleteBST(T, key) == false) //�ڶ���������T��ɾ���ؼ���Ϊkey�Ľ�㣬�����ɾ�����
        cout << "Delete failed. No node of value " << key << "exists in the binary sort tree..." << endl;
    else {
        cout << "Delete successful! The middle order traversal result of the binary sort tree is:" << endl;
        InorderBST(T);
    }
    return 0;
}


















