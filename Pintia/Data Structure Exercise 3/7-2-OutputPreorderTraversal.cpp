#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

typedef struct BiTNode {         //二叉链表结构定义
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//由二叉树的先序遍历序列prestr和中序遍历序列instr，创建包含n个结点的二叉链表，并返回根指针；
//pre表示要创建的二叉树的先序序列在prestr中的起始位置，in表示要创建的二叉树的中序序列在instr中的起始位置
BiTNode *CreateBiTree(char postr[], int pos, char instr[], int in, int n) {
    BiTNode *r;
    if(n <= 0) return NULL; //递归出口，若要创建的二叉树中的结点数<=0，则建空树
    r = new BiTNode;   //创建二叉树结点r
    char ch = postr[pos]; //从prestr中获取该二叉树根结点的值，在prestr中的起始处（即pre位置处）
    r->data = ch;     //为结点赋值
    r->rchild = NULL;
    r->lchild = NULL;
    int j = in;
    while(j < in + n) { //在中序序列中找根的位置j
        if(instr[j] == ch) {
            break;
        }
        j++;
    }
    int k = j - in; //计算左子树中结点个数
    r->lchild = CreateBiTree(postr, pos + 1, instr, in, k); //递归创建左子树，左子树的先序遍历序列从prestr中的pre+1位置开始，长度为k(左子树中结点的个数)，左子树的中序遍历序列从instr的in处开始，长度为k
    r->rchild = CreateBiTree(postr, pos + k + 1, instr, j + 1, n - k - 1); //递归创建右子树,右子树的先序遍历序列从prestr中的pre+k+1位置开始，长度为n-k-1，右子树的中序遍历序列从instr的j+1处开始，长度为n-k-1
    return r;	//返回创建的二叉链表的根指针
}

//先序遍历二叉树T，输出其先序遍历序列
void PreOrderTraverse(BiTree T) {
    //请同学们补充此操作
    if(T) {
        cout << " " << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

int main(int argc, char** argv) {
    int n;
    cin >> n; //输入结点数
    char postr[n], instr[n];  //用一维字符数组prestr和instr存放二叉树的先序遍历序列和中序遍历序列
    cin >> postr >> instr; //读入先序遍历序列和中序遍历序列
    BiTree T = CreateBiTree(postr, 0, instr, 0, n); //根据先序遍历序列和中序遍历序列创建二叉链表，T为根指针
    cout << "Preorder:";
    PreOrderTraverse(T);
    return 0;
}




