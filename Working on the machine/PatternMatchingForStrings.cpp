/*
	本实验完成串的模式匹配操作，并在串的模式匹配的基础上，完成在主串中查找模式串出现的次数及所有位置，
	把主串中和模式串相同的子串全部替换为另一个串。 要实现的操作如下：
	1、int Index_BF(SString S,SString T,int pos)  //模式匹配的BF算法
	2、void get_next(SString T,int next[])   //求模式串的next值
	3、int Index_KMP(SString S,SString T,int next[],int pos)  //KMP算法
	4、int Index_KMP_ALL(SString S,SString T,int next[],int pos)   //求T在S中出现的所有位置及次数，以KMP算法为基础，（已实现）
	5、int Index_KMP_ReplaceALL(SString S,SString T,SString M,SString &R,int next[],int pos)
	   //将S中和T相同的子串全部替换为M，R为替换后得到的新串
*/
#include <iostream>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAXLEN 255
typedef struct {
    char ch[MAXLEN + 1];
    int length;
} SString;

//返回模式串T在主串S中第pos个字符开始第一次出现的位置，若不存在，则返回值为0
int Index_BF(SString S, SString T, int pos) {
    //请同学们补充此操作
    int i = pos;
    int j = 1;
    while(i < S.length && j <= T.length) {
        if(S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > T.length) {
        return i - T.length;
    }
    return 0; //补充完该操作后，请修改此行
}

//求模式串T中各字符的next值，结果保存在数组next中
void get_next(SString T, int next[]) {
    //请同学们补充此操作
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i < T.length) {
        if(j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

//KMP算法，S为主串，T为模式串，模式串中各字符的next值保存在数组next中
int Index_KMP(SString S, SString T, int next[], int pos) {
    //请同学们补充此操作
    int i = pos;
    int j = 0;
    while(i <= S.length && j <= T.length) {
        if(j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if(j > T.length) {
        return i - T.length;
    }
    return 0; //补充完该操作后，请修改此行
}

//使用KMP算法，求T在S中出现的所有位置及次数
int Index_KMP_ALL(SString S, SString T, int next[], int pos) {
    int i = pos, n = 0; //n表示T在S中出现的次数，i为每次在S中查找的起始位置
    while(i <= S.length) {
        int k = Index_KMP(S, T, next, i); //k为T在S中出现的位置
        if(k != 0) { //若T在S中出现，则输出该次出现的位置
            cout << k << " ";
            i = k + T.length; //修改下次在S中查找T的起始位置
            n++;  //T在S中的出现次数加1
        } else //若某次查找失败，则查找结束
            break;
    }
    return n; //返回T在S中出现的次数
}

//选做实验
//使用KMP算法，将S中的T全部替换为M，R为替换后得到的新串，函数返回替换的次数
int Index_KMP_ReplaceALL(SString S, SString T, SString M, SString &R, int next[], int pos) {

    //请同学们参照Index_KMP_ALL的实现过程，补充该操作




    return 0; //补充完该操作后，请修改此行
}

int main(int argc, char** argv) {
    SString S, T;
    int next[MAXLEN + 1], len; //存放模式串的next值
    cout << "Please enter the main string:";
    fgets(S.ch + 1, MAXLEN, stdin); //读入主串，存放在S.ch中，从下标1处开始存放
    //删除S末尾多余的换行符
    len = strlen(S.ch + 1);
    if(S.ch[len] == '\n')
        S.ch[len] = '\0';
    S.length = strlen(S.ch + 1); //求主串的长度

    cout << "Please enter mode string:";
    fgets(T.ch + 1, MAXLEN, stdin); //读入模式串
    //删除T末尾多余的换行符
    len = strlen(T.ch + 1);
    if(T.ch[len] == '\n')
        T.ch[len] = '\0';
    T.length = strlen(T.ch + 1); //求模式串的长度
    //以下操作使用BF算法进行模式匹配
    cout << endl << "The search result using BF algorithm is:" << endl;
    int pos = Index_BF(S, T, 1); //使用BF算法，求T在S中首次出现的位置pos,从S的第一个字符处开始查找
    if(pos == 0) //T在S中没有出现
        cout << "Search failed! The pattern string does not appear in the main string!" << endl;
    else {   //在S中找到T，输出T在S中首次出现的位置
        cout << "After successful search, the location where the pattern string first appears in the main string is:" << pos << endl;
    }

    //以下操作使用KMP进行模式匹配
    cout << endl << "The search result using KMP algorithm is:" << endl;
    memset(next, 0, sizeof(next)); //初始化next数组的值为0
    get_next(T, next);    //求模式串T的next值，结果保存在数组next中
    pos = Index_KMP(S, T, next, 1); //使用KMP算法，求T在S中首次出现的位置pos,从S的第一个字符处开始查找
    if(pos == 0) //T在S中没有出现
        cout << "Search failed! The pattern string does not appear in the main string!" << endl;
    else {   //在S中找到T，输出T在S中首次出现的位置
        cout << "After successful search, the location where the pattern string first appears in the main string is:" << pos << endl;
    }

    //以下操作使用KMP查找T在S中出现的所有位置
    cout << endl << T.ch + 1 << " All positions in the main string are:";
    int n = Index_KMP_ALL(S, T, next, 1);
    cout << endl << T.ch + 1 << " A total of the " << n << " times!" << endl;

    //以下操作把S中的T全部替换为M，并输出替换后的新串
    cout << endl << "Please enter the replacement string:";
    SString M, R;
    cin >> M.ch + 1;
    M.length = strlen(M.ch + 1);
    n = Index_KMP_ReplaceALL(S, T, M, R, next, 1);
    cout << "The replaced string S is:" << endl;
    cout << R.ch + 1 << endl;
    cout << n << "substitutions were made" << endl;
    return 0;
}

















