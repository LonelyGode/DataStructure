/*
   本实验主要实现二叉排序树的基本操作，记录关键字的类型为int
   本实验主要实现7个操作：
   1、void InsertBST(BSTree &T,ElemType e)
//在二叉排序树T中插入一个关键字为e.key的新结点
2、void CreateBST(BSTree &T)
//创建二叉排序树T
3、void InorderBST(BSTree T)
//按中序遍历序列输出各结点关键字值
4、BSTree SearchBST(BSTree T,int key)
//在二叉排序树T中，查找关键字为key的结点，若查找成功，返回该结点地址，否则，返回空指针
5、void Delete(BSTree &T,BSTNode *p,BSTNode *f)
//在二叉排序树T中删除p所指结点，f为p的双亲
6、bool DeleteBST(BSTree &T,int key)
//删除二叉排序树T中关键字等于key的结点，删除成功，返回true，删除失败，返回false
7、BSTree SearchBST_A(BSTree T,int key)
//在二叉排序树T中按照非递归方法查找关键字为key的结点，查找成功，返回该结点地址，查找失败，返回NULL
 */

#include <iostream>
using namespace std;
//数据元素类型ElemType定义
typedef struct {
    int key;           //关键字域
    char *otherinfo;   //其它域
} ElemType;

//二叉链表结构定义
typedef struct BSTNode {
    ElemType data;                    //数据域
    struct BSTNode *lchild, *rchild;  //左右指针域
} BSTNode, *BSTree;


//在二叉排序树T中插入一个关键字为e.key的新结点
void InsertBST(BSTree &T, ElemType e) {
    BSTNode *s;
    if(T == NULL) { //搜索到空树时，插入结点
        s = new BSTNode;
        s->data = e;
        s->lchild = s->rchild = NULL;
        T = s;
    } else if(e.key < T->data .key ) //在左子树中插入结点
        InsertBST(T->lchild, e);
    else if(e.key > T->data .key )   //在右子树中插入结点
        InsertBST(T->rchild, e);

}

//创建二叉排序树T
void CreateBST(BSTree &T) {
    ElemType e;
    T = NULL;             //初始时，二叉排序树T为空树
    cout << "Please enter the key value of each node (integer, separated by space or enter), ending with -1:" << endl;
    cin >> e.key ;
    while(e.key != -1) {  //逐一将新结点插入到二叉排序树T中
        InsertBST(T, e);
        cin >> e.key ;
    }
}

//按中序遍历序列输出各结点关键字值
void InorderBST(BSTree T) {
    if(T) {
        InorderBST(T->lchild);
        cout << T->data .key << "  ";
        InorderBST(T->rchild );
    }
}


//在二叉排序树T中，查找关键字为key的结点，若查找成功，返回该结点地址，否则，返回空指针
BSTree SearchBST(BSTree T, int key) {
    //请同学们将该操作补充完整
    if((!T) || key == T->data.key) {
        return T;
    } else if((!T) || key < T->data.key) {
        return SearchBST(T->lchild, key);
    } else if((!T) || key > T->data.key) {
        return SearchBST(T->rchild, key);
    }
    return T;  //补充完该部分操作后，将改行删除
}

//在二叉排序树T中按照非递归方法查找关键字为key的结点，查找成功，返回该结点地址，查找失败，返回NULL
BSTree SearchBST_A(BSTree T, int key) {
    //请同学们将该操作补充完整

    return T;  //补充完该部分操作后，将改行删除
}

//本操作请在课下完成
//在二叉排序树T中删除p所指结点，f为p的双亲
void Delete(BSTree &T, BSTNode *p, BSTNode *f) {
    BSTNode *q, *s;
    q = p;
    if(p->rchild  && p->lchild ) { //p所指结点的左右子树均非空
        //请同学们补充此部分操作
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
    } else if(p->rchild == NULL) { //p所指结点只有左子树
        //请同学们补充此部分操作
        p = p->lchild;

    } else if(p->lchild == NULL) { //p所指结点只有右子树
        //请同学们补充此部分操作
        p = p->lchild;

    }
    if(f == NULL) T = NULL; //T只有一个根结点，且被删除的是根结点
    else if(q == f->lchild )  f->lchild = p; //被删结点是双亲f的左孩子
    else   f->rchild = p;   //被删结点是双亲f的右孩子
    delete q;    //释放被删结点
}


//删除二叉排序树T中关键字等于key的结点，删除成功，返回true，删除失败，返回false
bool DeleteBST(BSTree &T, int key) {
    BSTNode *p = T, *f = NULL;
    while(p) {   //从二叉排序树的根开始，查找关键字为key的结点，并用p指向它，f指向p的双亲
        if(p->data .key == key)    //找到关键字为key的结点，且p指向它
            break;
        f = p;                     //f为p的双亲
        if(p->data .key > key)     //在p的左子树中继续查找
            p = p->lchild ;
        else                       //在p的右子树中继续查找
            p = p->rchild ;
    }
    if(p == NULL)          //T中不存在关键字等于key的结点，返回false
        return false;
    Delete(T, p, f);       //在二叉排序树T中删除p所指结点（关键字为key的结点），f指向p的双亲
    return true;           //删除成功，返回true
}

int main() {

    BSTree T;
    int key;

    CreateBST(T);         //创建二叉排序树
    cout << "The middle order traversal sequence of the binary sort tree is:" << endl;
    InorderBST(T);       //输出二叉排序树的中序遍历序列
    cout << endl;

    //二叉排序树的查找（递归方式）
    cout << "Please enter the value of the keyword to look for(recursively):";
    cin >> key;
    if(SearchBST(T, key) == NULL)    //在二叉排序树T中查找关键字为key的结点，并输出查找结果
        cout << "The search failed. No node of value " << key << " exists in the binary sort tree..." << endl;
    else
        cout << "Find success!" << endl;

    //二叉排序树的查找（非递归方式）
    cout << "Please enter the value of the keyword to look for(non-recursive search):";
    cin >> key;
    if(SearchBST_A(T, key) == NULL)    //在二叉排序树T中查找关键字为key的结点，并输出查找结果
        cout << "The search failed. No node of value " << key << " exists in the binary sort tree..." << endl;
    else
        cout << "Find success!" << endl;

    //以下为二叉排序树的删除操作
    cout << "Please enter the value of the keyword to be deleted:";
    cin >> key;
    if(DeleteBST(T, key) == false) //在二叉排序树T中删除关键字为key的结点，并输出删除结果
        cout << "Delete failed. No node of value " << key << "exists in the binary sort tree..." << endl;
    else {
        cout << "Delete successful! The middle order traversal result of the binary sort tree is:" << endl;
        InorderBST(T);
    }
    return 0;
}


















