/*
	��ʵ����Ҫʵ�����������������ļ�¼�洢��˳����У���¼�ؼ��ֵ�����Ϊint
	��ʵ����Ҫʵ��16��������
	1��void InsertSort(SqList &L)   //��˳���L�еļ�¼����ֱ�Ӳ�������
	2��void BInsertSort(SqList &L)    //��˳���L�еļ�¼�����۰��������
	3��void ShellInsert(SqList &L,int dk)   //��˳���L�еļ�¼����һ������Ϊdk��ϣ������
	4��void ShellSort(SqList &L,int dt[],int t)    //��˳���L�еļ�¼���������У��洢������dt�У�����t��ϣ��������ʵ�֣�
	5��void BubbleSort(SqList &L)    //��˳���L�еļ�¼����ð������
	6��int Partition(SqList &L,int low,int high)   //��˳���L�е��ӱ�L.r[low...high]����һ�λ��֣�����������λ��
	7��void QSort(SqList &L,int low,int high)    //��˳���L�е�������L.r[low...high]���п�������
	8��void SelectSort(SqList &L)   //��˳���L�еļ�¼���м�ѡ������
	9��void HeapAdjust(SqList &L,int s,int m)  //�ѵĵ���������L.r[s+1...m]�Ѿ���һ������ѣ��ò�����L.r[s...m]����Ϊ��L.r[s]Ϊ���Ĵ����
	10��void CreatHeap(SqList &L)  //��˳���L�е������¼���н��ɴ����
	11��void HeapSort(SqList &L)  //��˳���L�еļ�¼���ж�����
	12��void Merge(RedType R[],int low,int mid,int high)  //�������R[low...mid]��R[mid+1...high]�鲢Ϊ�����R[low...high]
	13��void MSort(RedType R[],int low,int high)  //��R[low...high]�еļ�¼���ж�·�鲢����
	14��void CreateList(SqList &L)  //����˳�����˳���L�����50����¼����¼�Ĺؼ���Ϊ1-100��Χ�ڵ������������ʵ�֣�
	15��void PrintList(SqList L)    //���˳���L�и���¼�ؼ��ֵ�ֵ���м��ÿո�ָ�����ʵ�֣�
	16��void showmenu()    //����˵�����ʵ�֣�
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MAXSIZE 100     //˳�����󳤶�

typedef struct {
    int key;           //�ؼ�����ؼ�������Ϊ����
    char *otherinfo;   //����������
} RedType;    //��¼����

typedef struct {
    RedType r[MAXSIZE + 1];   //0�ŵ�Ԫ����
    int length;               //˳�����
} SqList;    //˳�������


//��˳���L�еļ�¼����ֱ�Ӳ�������
void InsertSort(SqList &L) {
    //��ͬѧ�ǲ���˲���
    for(int i = 2; i < L.length; i++) {
        if(L.r[i].key < L.r[i - 1].key) {
            L.r[0] = L.r[i];
            L.r[i] = L.r[i - 1];
            int j;
            for(j = i - 2; L.r[0].key < L.r[j].key; j--) {
                L.r[j + 1] = L.r[j];
            }
            L.r[j + 1] = L.r[0];
        }
    }
}

//��˳���L�еļ�¼�����۰��������
void BInsertSort(SqList &L) {
    //��ͬѧ�ǲ���˲���
    for(int i = 2; i <= L.length; i++) {
        L.r[0] = L.r[i];
        int low = 1;
        int high = i - 1;
        while(low <= high ) {
            int m = (low + high) / 2;
            if(L.r[0].key < L.r[m].key) {
                high = m - 1;
            } else {
                low = m + 1;
            }
        }
        for(int j = i - 1; j <= high + 1; j--) {
            L.r[j + 1] = L.r[j];
        }
        L.r[high + 1] = L.r[0];
    }
}

//��˳���L�еļ�¼����һ������Ϊdk��ϣ������
void ShellInsert(SqList &L, int dk) {
    //��ͬѧ�ǲ���˲���
    for(int i = dk + 1; i < L.length; i++) {
        if(L.r[i].key < L.r[i - dk].key) {
            L.r[0] = L.r[i];
            int j;
            for(j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk) {
                L.r[j + dk] = L.r[j];
            }
            L.r[j + dk] = L.r[0];
        }
    }

}

//��˳���L�еļ�¼���������У��洢������dt�У�����t��ϣ������
void ShellSort(SqList &L, int dt[], int t) {
    int i;
    for(i = 0; i < t; i++) {
        ShellInsert(L, dt[i]);
    }
}

//��˳���L�еļ�¼����ð������
void BubbleSort(SqList &L) {
    //��ͬѧ�ǲ���˲���
    int m = L.length - 1;
    int flag = 1;
    while((m > 0) && (flag == 1)) {
        flag = 0;
        for(int j = 1; j < m; j++) {
            if(L.r[j].key > L.r[j + 1].key) {
                flag = 1;
                RedType t = L.r[j];
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = t;
            }
            m--;
        }
    }
}

//��˳���L�е��ӱ�L.r[low...high]����һ�λ��֣�����������λ��
int Partition(SqList &L, int low, int high) {
    //��ͬѧ�ǲ���˲���
    L.r[0] = L.r[low];
    int pivotkey = L.r[0].key;
    while(low < high) {
        while(low < high && L.r[high].key > pivotkey) {
            high--;
        }
        L.r[low] = L.r[high];
        while(low < high && L.r[low].key <= pivotkey) {
            low++;
        }
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0];
    return low;  //���벹��������ɾ������
}


//��˳���L�е�������L.r[low...high]���п�������
void QSort(SqList &L, int low, int high) {
    //��ͬѧ�ǲ���˲���
    if(low < high) {
        int pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc - 1);
        QSort(L, pivotloc + 1, high);
    }
}

//��˳���L�еļ�¼���п�������
void QuickSort(SqList &L) {
    QSort(L, 1, L.length);
}

//��˳���L�еļ�¼���м�ѡ������
void SelectSort(SqList &L) {
    //��ͬѧ�ǲ���˲���
    for(int i = 1; i < L.length; i++) {
        int k = i;
        for(int j = i + 1; j < L.length; j++) {
            if(L.r[j].key < L.r[k].key) {
                k = j;
            }
        }
        if(k != i) {
            RedType t = L.r[i];
            L.r[i] = L.r[k];
            L.r[k] = t;
        }
    }
}

//�ѵĵ���������L.r[s+1...m]�Ѿ���һ������ѣ��ò�����L.r[s...m]����Ϊ��L.r[s]Ϊ���Ĵ����
void HeapAdjust(SqList &L, int s, int m) {
    //��ͬѧ�ǲ���˲���
    RedType rc = L.r[s];
    for(int j = 2 * s; j <= m; j *= 2) {
        if(j < m && L.r[j].key < L.r[j + 1].key) {
            j++;
        }
        if(rc.key > L.r[j].key) {
            break;
        }
        L.r[s] = L.r[j];
        s = j;
    }
    L.r[s] = rc;
}

//��˳���L�е������¼���н��ɴ����
void CreatHeap(SqList &L) {
    //��ͬѧ�ǲ���˲���
    int n = L.length;
    for(int i = n / 2; i > 0; i--) {
        HeapAdjust(L, i, n);
    }
}

//��˳���L�еļ�¼���ж�����
void HeapSort(SqList &L) {
    //��ͬѧ�ǲ���˲���
    CreatHeap(L);
    for(int i = L.length; i > 1; i--) {
        RedType x = L.r[1];
        L.r[1] = L.r[i];
        L.r[i] = x;
        HeapAdjust(L, 1, i - 1);
    }
}

//�������R[low...mid]��R[mid+1...high]�鲢Ϊ�����R[low...high]
void Merge(RedType R[], RedType T[], int low, int mid, int high) {
    //��ͬѧ�ǲ���˲���
    int i = low;
    int j = mid + 1;
    int k = low;
    while(i < mid && j < high) {
        if(R[i].key < R[j].key) {
            T[k++] = R[i++];
        } else {
            T[k++] = R[i++];
        }
    }
    while(i <= mid) {
        T[k++] = R[i++];
    }
    while(j <= high) {
        T[k++] = R[j++];
    }
}

//��R[low...high]�еļ�¼���ж�·�鲢����
void MSort(RedType R[], RedType T[], int low, int high) {
    //��ͬѧ�ǲ���˲���
    if(low == high) {
        T[low] = R[low];
    } else {
        int mid = (low + high) / 2;
        RedType S[];
        MSort(R, S, low, mid);
        MSort(R, S, mid + 1, high);
        Merge(S, T, low, mid, high);
    }
}

//��˳���L�еļ�¼���й鲢����
void MergeSort(SqList &L) {
    MSort(L.r, 1, L.length);
}

//����˳�����˳���L�����50����¼����¼�Ĺؼ���Ϊ1-100��Χ�ڵ��������
void CreateList(SqList &L) {
    int i;
    srand(time(0));
    for(i = 1; i <= 50; i++) {
        L.r[i].key = rand() % 100 + 1;
    }
    L.length = 50;
}

//���˳���L�и���¼�ؼ��ֵ�ֵ���м��ÿո�ָ�
void PrintList(SqList L) {
    int i;
    for(i = 1; i <= L.length ; i++) {
        cout << L.r[i].key << "  ";
    }
    cout << endl;
}

//����˵�
void showmenu() {
    cout << endl;
    cout << "*************Sorting method*********************" << endl;
    cout << "1. ֱ�Ӳ�������\t2. �۰��������" << endl;
    cout << "3. ϣ������\t4. ð������" << endl;
    cout << "5. ��������\t6. ��ѡ������" << endl;
    cout << "7. ������\t8. ��·�鲢����" << endl;
    cout << "0.�˳�" << endl;
    cout << "��ѡ��Ҫִ�е����򷽷����" << endl;

}

int main() {
    SqList L;
    int n, dt[3] = {5, 3, 1}; //dt�д�ŵ���ϣ������ʱʹ�õ���������
    CreateList(L);         //��������Ϊ10��˳���L�����м�¼�Ĺؼ���Ϊ1-100��Χ�ڵ��������
    showmenu();
    cin >> n;       //����ѡ������򷽷����
    while(n != 0) { //ѭ����ʾ�˵�����0��������
        if(n >= 1 && n <= 8) {
            cout << "�������¼��ʼ�ؼ���Ϊ��" << endl;
            PrintList(L);        //�������ǰ���и���¼�ؼ��ֵ�ֵ
        }
        switch(n) {   //����ѡ�����ŵ��ò�ͬ�����򷽷�
        case 1:
            cout << "ֱ�Ӳ�������Ľ��Ϊ��" << endl;
            InsertSort(L);    //ֱ�Ӳ�������
            PrintList(L);     //�����������¼�ؼ��ֵ�ֵ
            break;
        case 2:
            cout << "�۰��������Ľ��Ϊ��" << endl;
            BInsertSort(L);   //�۰��������
            PrintList(L);
            break;
        case 3:
            cout << "ϣ������Ľ��Ϊ��" << endl;
            ShellSort(L, dt, 3);  //ϣ�����򣬣�3�ˣ�
            PrintList(L);
            break;
        case 4:
            cout << "ð������Ľ��Ϊ��" << endl;
            BubbleSort(L);     //ð������
            PrintList(L);
            break;
        case 5:
            cout << "��������Ľ��Ϊ��" << endl;
            QuickSort(L);    //��������
            PrintList(L);
            break;
        case 6:
            cout << "��ѡ������Ľ��Ϊ��" << endl;
            SelectSort(L);     //��ѡ������
            PrintList(L);
            break;
        case 7:
            cout << "������Ľ��Ϊ��" << endl;
            HeapSort(L);    //������
            PrintList(L);
            break;
        case 8:
            cout << "��������Ľ��Ϊ��" << endl;
            MergeSort(L);    //��·�鲢����
            PrintList(L);
            break;
        default:
            cout << "���ѡ�����������ѡ��" << endl;
            break;

        }
        CreateList(L);    //ÿ�����������L�е�50����¼
        showmenu();
        cin >> n;
        system("cls");   //����
    }
}


































