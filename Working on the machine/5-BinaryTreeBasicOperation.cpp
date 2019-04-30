/*
	本实验主要实现二叉树的基本操作，二叉树中结点值的类型为char
	本实验主要实现5个操作：
	1、void CreatBitree(BiTree &T)  //输入二叉树的先序遍历序列（空树用字符'#'表示），创建二叉链表T
	2、void InOrderTraverse(BiTree T)   //中序遍历二叉树T
	3、void PreOrderTraverse(BiTree T)  //先序遍历二叉树T
	4、void PostOrderTraverse(BiTree T)  //后序遍历二叉树T
	5、bool SearchTree(BiTree T,char ch,BiTree &p)  //在二叉树T中查找值为ch的结点，查找成功，函数返回true,p指向该结点,否则函数返回false，p为空
	6、int Depth(BiTree T) //求二叉树T的深度
	7、int NodeCount(BiTree T)  //求二叉树T中结点的个数
	8、int LeafCount(BiTree T)  //求二叉树T中叶子结点的数量
	9、int NodeCount1(BiTree T)  //求二叉树T中度为1的结点的数量
	10、int NodeCount2(BiTree T)   //求二叉树T中度为2的结点的数量
	11、int Width(BiTree T)   //求二叉树T的宽度
*/
#include <iostream>
#include <stdlib.h>

using namespace std;
//二叉链表结构
typedef struct BiTNode {
    char data;      //数据域,存放结点值
    struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree; // 二叉链表

typedef struct {
    char *base;   //栈底指针,栈中元素为字符
    char *top;    //栈顶指针
    int stacksize;   //栈可用的最大容量
} SqStack;      //顺序栈结构

//输入二叉树的先序遍历序列（空树用字符'#'表示），创建二叉链表T
void CreatBitree(BiTree &T) {
    //请同学们补充此操作
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

//求二叉树T中值为ch的结点的层次，结果用p表示，curlevel表示当前T所在的层数，
//求值成功返回true,失败返回false
bool level(BiTree T, char ch, int curlevel, int &p) {
    if(T == NULL) //若T为空树，返回false
        return false;
    if(T->data == ch) { //若T的值为ch,则结点层数p为curlevel
        p = curlevel;
        return true;
    } else { //若T的值为ch,则先在T的左子树中求ch结点的层数，若ch结点不在T的左子树中，再在T的右子树中求ch结点的层数
        if(level(T->lchild, ch, curlevel + 1, p))
            return true;
        else
            return level(T->rchild, ch, curlevel + 1, p);
    }
}

//在二叉树T中求值为ch的结点的祖先,成功返回true,失败返回false
bool ancestor(BiTree T, char ch) {
    if(T == NULL) //T为空树时，返回false
        return false;
    else if(T->lchild && T->lchild->data == ch ) { //若T的左孩子值为ch，则T为ch结点的祖先，输出T结点，返回true
        cout << T->data << " ";
        return true;
    } else if(T->rchild && T->rchild->data == ch) { //若T的右孩子值为ch，则T为ch结点的祖先，输出T结点,返回true
        cout << T->data << " ";
        return true;
    }
    //若T的左孩子值是ch结点的祖先，则T也是ch的祖先，输出T结点，返回true
    else if(ancestor(T->lchild, ch) || ancestor(T->rchild, ch)) {
        cout << T->data << " ";
        return true;
    } else //其它情况时，不能求值为ch的结点祖先，此时值为ch的结点或者为根结点，或者不存在，返回false
        return false;
}

//中序遍历二叉树T，输出其中序遍历序列
void InOrderTraverse(BiTree T) {
    //请同学们补充此操作
    if(T) {
        InOrderTraverse(T->lchild);
        cout << T->data << " ";
        InOrderTraverse(T->rchild);
    }
}

//先序遍历二叉树T，输出其先序遍历序列
void PreOrderTraverse(BiTree T) {
    //请同学们补充此操作
    if(T) {
        cout << T->data << " ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//后序遍历二叉树T，输出其后序遍历序列
void PostOrderTraverse(BiTree T) {
    //请同学们补充此操作
    if(T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data << " ";
    }
}

//在二叉树T中查找值为ch的结点，查找成功，函数返回true,p指向该结点,否则函数返回false，p为空
bool SearchTree(BiTree T, char ch, BiTree &p) {
    //请同学们补充此操作
    if(T) {
        SearchTree(T->lchild, ch, p);
        if(ch == T->data) {
            p = T;
        }
        SearchTree(T->rchild, ch, p);
    }
    if(p) {
        return true;  //补充完该操作后，请修改此行代码
    } else {
        return false;
    }
}

//求二叉树T的深度
int Depth(BiTree T) {
    //请同学们补充此操作
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

//求二叉树T的宽度
int Width(BiTree T) {
    //请同学们补充此操作
    BiTree q[100];  //q为一个顺序队列，队头和队尾为front和rear
    //end记录当前层最后一个结点的位置，length表示当前层的宽度，maxwidth表示T的宽度
    int front = 0, rear = 0, end, length = 0, maxwidth = 0;
    q[rear] = T; //根结点入队
    rear++;
    end = rear; //记录当前层（第一层）的结束位置（最后一个结点的位置）
    while(front != rear) { //当队列非空时，依次处理每一层中的结点
        if(front < end) //若当前层还有结点没处理完，则当前层结点数增一
            length++;
        else { //若当前层中结点已处理完，此时，当前层的宽度为length
            maxwidth = max(length, maxwidth); //求当前二叉树的最大宽度
            end = rear; //记录下一层的结束位置
            length = 1; //重新求下一层宽度前，将length重置为一
        }
        BiTNode *s = q[front]; //队头结点出队，用s表示该结点
        front++;
        if(s->lchild) { //若s有左孩子，则另其左孩子入队
            q[rear] = s->lchild;
            rear++;
        }
        if(s->rchild) { //若s有右孩子，则另其右孩子入队
            q[rear] = s->rchild;
            rear++;
        }
    }
    maxwidth = max(length, maxwidth); //当队列为空时，不要忘了求最后一层的宽度，以获取最终的maxwidth
    return maxwidth; //返回求得的二叉树的宽度
}

//对以T为根的二叉树进行层序遍历，需借助队列
void LevelTraverse(BiTree T) {
    BiTree q[100];  //定义顺序队列q,队头为front,队尾为rear
    int front = 0, rear = 0;
    q[rear] = T; //根结点入队
    rear++;
    while(front != rear) { //当队列非空时，依次删除队头元素并输出，再另其孩子依次入队
        BiTNode *s = q[front]; //删除队头元素（s表示）并输出
        cout << s->data << " ";
        front++;
        if(s->lchild) { //若s有左孩子，左孩子入队
            q[rear] = s->lchild;
            rear++;
        }
        if(s->rchild) { //若s有右孩子，右孩子入队
            q[rear] = s->rchild;
            rear++;
        }
    }
}

//求二叉树T中结点总数
int NodeCount(BiTree T) {
    //请同学们补充此操作
    if(!T) {
        return 0;
    } else {
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    }
}

//求二叉树T中叶子结点总数
int LeafCount(BiTree T) {
    //请同学们补充此操作
    if(!T) {
        return 0;
    }
    if(!T->lchild && !T->rchild) {
        return 1;
    }
    return LeafCount(T->lchild) + LeafCount(T->rchild); //补充完该操作后，请修改此行代码
}

//求二叉树T中度为1的结点总数
int NodeCount1(BiTree T) {
    //请同学们补充此操作
    if(!T) {
        return 0;
    }
    if((T->lchild && !T->rchild) || (!T->lchild && T->rchild)) {
        return NodeCount1(T->lchild) + NodeCount1(T->rchild) + 1;
    } else {
        return NodeCount1(T->lchild) + NodeCount1(T->rchild);
    }
    //补充完该操作后，请修改此行代码
}

//求二叉树T中度为2的结点总数
int NodeCount2(BiTree T) {
    //请同学们补充此操作
    if(!T) {
        return 0;
    }
    if(T->lchild && T->rchild) {
        return NodeCount2(T->lchild) + NodeCount2(T->rchild) + 1;
    } else {
        return NodeCount2(T->lchild) + NodeCount2(T->rchild);
    }
    //补充完该操作后，请修改此行代码
}

int main() {
    BiTree T, p = NULL;    //T为本程序中要操作的二叉链表
    char ch;    //ch表示在二叉树中要查询的结点
    bool flag;
    cout << "Please enter the binary tree to be created, input in the preamble sequence, empty tree replaced with the character '#':" << endl;
    CreatBitree(T);  //根据输入的二叉树先序序列，创建二叉链表T
    cout << "The result of the sequence traversal is:" << endl;
    LevelTraverse(T);
    cout << endl << "Please enter the node to be queried:";
    cin >> ch;
    int n;
    level(T, ch, 1, n); //求值为ch结点的层数，初始时根的层数为1
    cout << "The level of the node is:" << n << endl;
    cout << "The ancestor of the node is:";
    flag = ancestor(T, ch);
    if(flag == false) {
        cout << "No ancestor node!" << endl;
    }
    cout << endl << "The result of the in-order traversal is:：" << endl;
    InOrderTraverse(T);      //输出二叉树T的中序遍历序列
    cout << endl << "The preorder traversal result is:" << endl;
    PreOrderTraverse(T);     //输出二叉树T的先序遍历序列
    cout << endl << "The post-order traversal result is:" << endl;
    PostOrderTraverse(T);    //输出二叉树T的后序遍历序列
    cout << endl << "Please enter the node you want to find in the binary tree:";
    rewind(stdin);   //清空输入缓冲区
    cin >> ch;
    flag = SearchTree(T, ch, p); //在二叉树T中查找值为ch1的结点
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













