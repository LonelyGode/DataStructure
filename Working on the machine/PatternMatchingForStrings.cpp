/*
	��ʵ����ɴ���ģʽƥ����������ڴ���ģʽƥ��Ļ����ϣ�����������в���ģʽ�����ֵĴ���������λ�ã�
	�������к�ģʽ����ͬ���Ӵ�ȫ���滻Ϊ��һ������ Ҫʵ�ֵĲ������£�
	1��int Index_BF(SString S,SString T,int pos)  //ģʽƥ���BF�㷨
	2��void get_next(SString T,int next[])   //��ģʽ����nextֵ
	3��int Index_KMP(SString S,SString T,int next[],int pos)  //KMP�㷨
	4��int Index_KMP_ALL(SString S,SString T,int next[],int pos)   //��T��S�г��ֵ�����λ�ü���������KMP�㷨Ϊ����������ʵ�֣�
	5��int Index_KMP_ReplaceALL(SString S,SString T,SString M,SString &R,int next[],int pos)
	   //��S�к�T��ͬ���Ӵ�ȫ���滻ΪM��RΪ�滻��õ����´�
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

//����ģʽ��T������S�е�pos���ַ���ʼ��һ�γ��ֵ�λ�ã��������ڣ��򷵻�ֵΪ0
int Index_BF(SString S, SString T, int pos) {
    //��ͬѧ�ǲ���˲���
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
    return 0; //������ò��������޸Ĵ���
}

//��ģʽ��T�и��ַ���nextֵ���������������next��
void get_next(SString T, int next[]) {
    //��ͬѧ�ǲ���˲���
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

//KMP�㷨��SΪ������TΪģʽ����ģʽ���и��ַ���nextֵ����������next��
int Index_KMP(SString S, SString T, int next[], int pos) {
    //��ͬѧ�ǲ���˲���
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
    return 0; //������ò��������޸Ĵ���
}

//ʹ��KMP�㷨����T��S�г��ֵ�����λ�ü�����
int Index_KMP_ALL(SString S, SString T, int next[], int pos) {
    int i = pos, n = 0; //n��ʾT��S�г��ֵĴ�����iΪÿ����S�в��ҵ���ʼλ��
    while(i <= S.length) {
        int k = Index_KMP(S, T, next, i); //kΪT��S�г��ֵ�λ��
        if(k != 0) { //��T��S�г��֣�������ôγ��ֵ�λ��
            cout << k << " ";
            i = k + T.length; //�޸��´���S�в���T����ʼλ��
            n++;  //T��S�еĳ��ִ�����1
        } else //��ĳ�β���ʧ�ܣ�����ҽ���
            break;
    }
    return n; //����T��S�г��ֵĴ���
}

//ѡ��ʵ��
//ʹ��KMP�㷨����S�е�Tȫ���滻ΪM��RΪ�滻��õ����´������������滻�Ĵ���
int Index_KMP_ReplaceALL(SString S, SString T, SString M, SString &R, int next[], int pos) {

    //��ͬѧ�ǲ���Index_KMP_ALL��ʵ�ֹ��̣�����ò���




    return 0; //������ò��������޸Ĵ���
}

int main(int argc, char** argv) {
    SString S, T;
    int next[MAXLEN + 1], len; //���ģʽ����nextֵ
    cout << "Please enter the main string:";
    fgets(S.ch + 1, MAXLEN, stdin); //���������������S.ch�У����±�1����ʼ���
    //ɾ��Sĩβ����Ļ��з�
    len = strlen(S.ch + 1);
    if(S.ch[len] == '\n')
        S.ch[len] = '\0';
    S.length = strlen(S.ch + 1); //�������ĳ���

    cout << "Please enter mode string:";
    fgets(T.ch + 1, MAXLEN, stdin); //����ģʽ��
    //ɾ��Tĩβ����Ļ��з�
    len = strlen(T.ch + 1);
    if(T.ch[len] == '\n')
        T.ch[len] = '\0';
    T.length = strlen(T.ch + 1); //��ģʽ���ĳ���
    //���²���ʹ��BF�㷨����ģʽƥ��
    cout << endl << "The search result using BF algorithm is:" << endl;
    int pos = Index_BF(S, T, 1); //ʹ��BF�㷨����T��S���״γ��ֵ�λ��pos,��S�ĵ�һ���ַ�����ʼ����
    if(pos == 0) //T��S��û�г���
        cout << "Search failed! The pattern string does not appear in the main string!" << endl;
    else {   //��S���ҵ�T�����T��S���״γ��ֵ�λ��
        cout << "After successful search, the location where the pattern string first appears in the main string is:" << pos << endl;
    }

    //���²���ʹ��KMP����ģʽƥ��
    cout << endl << "The search result using KMP algorithm is:" << endl;
    memset(next, 0, sizeof(next)); //��ʼ��next�����ֵΪ0
    get_next(T, next);    //��ģʽ��T��nextֵ���������������next��
    pos = Index_KMP(S, T, next, 1); //ʹ��KMP�㷨����T��S���״γ��ֵ�λ��pos,��S�ĵ�һ���ַ�����ʼ����
    if(pos == 0) //T��S��û�г���
        cout << "Search failed! The pattern string does not appear in the main string!" << endl;
    else {   //��S���ҵ�T�����T��S���״γ��ֵ�λ��
        cout << "After successful search, the location where the pattern string first appears in the main string is:" << pos << endl;
    }

    //���²���ʹ��KMP����T��S�г��ֵ�����λ��
    cout << endl << T.ch + 1 << " All positions in the main string are:";
    int n = Index_KMP_ALL(S, T, next, 1);
    cout << endl << T.ch + 1 << " A total of the " << n << " times!" << endl;

    //���²�����S�е�Tȫ���滻ΪM��������滻����´�
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

















