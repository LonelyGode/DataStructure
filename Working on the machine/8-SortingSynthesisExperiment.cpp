/*
	本实验主要实现排序操作，待排序的记录存储在顺序表中，记录关键字的类型为int
	本实验主要实现16个操作：
	1、void InsertSort(SqList &L)   //对顺序表L中的记录进行直接插入排序
	2、void BInsertSort(SqList &L)    //对顺序表L中的记录进行折半插入排序
	3、void ShellInsert(SqList &L,int dk)   //对顺序表L中的记录进行一趟增量为dk的希尔排序
	4、void ShellSort(SqList &L,int dt[],int t)    //对顺序表L中的记录按增量序列（存储在数组dt中）进行t趟希尔排序（已实现）
	5、void BubbleSort(SqList &L)    //对顺序表L中的记录进行冒泡排序
	6、int Partition(SqList &L,int low,int high)   //对顺序表L中的子表L.r[low...high]进行一次划分，并返回枢轴位置
	7、void QSort(SqList &L,int low,int high)    //对顺序表L中的子序列L.r[low...high]进行快速排序
	8、void SelectSort(SqList &L)   //对顺序表L中的记录进行简单选择排序
	9、void HeapAdjust(SqList &L,int s,int m)  //堆的调整，假设L.r[s+1...m]已经是一个大根堆，该操作将L.r[s...m]调整为以L.r[s]为根的大根堆
	10、void CreatHeap(SqList &L)  //把顺序表L中的无序记录序列建成大根堆
	11、void HeapSort(SqList &L)  //对顺序表L中的记录进行堆排序
	12、void Merge(RedType R[],int low,int mid,int high)  //将有序表R[low...mid]和R[mid+1...high]归并为有序表R[low...high]
	13、void MSort(RedType R[],int low,int high)  //对R[low...high]中的记录进行二路归并排序
	14、void CreateList(SqList &L)  //创建顺序表：向顺序表L中添加50个记录，记录的关键字为1-100范围内的随机整数（已实现）
	15、void PrintList(SqList L)    //输出顺序表L中各记录关键字的值，中间用空格分隔（已实现）
	16、void showmenu()    //程序菜单（已实现）
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MAXSIZE 100     //顺序表最大长度

typedef struct {
    int key;           //关键字项，关键字类型为整形
    char *otherinfo;   //其它数据项
} RedType;    //记录类型

typedef struct {
    RedType r[MAXSIZE + 1];   //0号单元闲置
    int length;               //顺序表长度
} SqList;    //顺序表类型


//对顺序表L中的记录进行直接插入排序
void InsertSort(SqList &L) {
    //请同学们补充此操作
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

//对顺序表L中的记录进行折半插入排序
void BInsertSort(SqList &L) {
    //请同学们补充此操作
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

//对顺序表L中的记录进行一趟增量为dk的希尔排序
void ShellInsert(SqList &L, int dk) {
    //请同学们补充此操作
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

//对顺序表L中的记录按增量序列（存储在数组dt中）进行t趟希尔排序
void ShellSort(SqList &L, int dt[], int t) {
    int i;
    for(i = 0; i < t; i++) {
        ShellInsert(L, dt[i]);
    }
}

//对顺序表L中的记录进行冒泡排序
void BubbleSort(SqList &L) {
    //请同学们补充此操作
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

//对顺序表L中的子表L.r[low...high]进行一次划分，并返回枢轴位置
int Partition(SqList &L, int low, int high) {
    //请同学们补充此操作
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
    return low;  //代码补充完整后，删除该行
}


//对顺序表L中的子序列L.r[low...high]进行快速排序
void QSort(SqList &L, int low, int high) {
    //请同学们补充此操作
    if(low < high) {
        int pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc - 1);
        QSort(L, pivotloc + 1, high);
    }
}

//对顺序表L中的记录进行快速排序
void QuickSort(SqList &L) {
    QSort(L, 1, L.length);
}

//对顺序表L中的记录进行简单选择排序
void SelectSort(SqList &L) {
    //请同学们补充此操作
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

//堆的调整，假设L.r[s+1...m]已经是一个大根堆，该操作将L.r[s...m]调整为以L.r[s]为根的大根堆
void HeapAdjust(SqList &L, int s, int m) {
    //请同学们补充此操作
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

//把顺序表L中的无序记录序列建成大根堆
void CreatHeap(SqList &L) {
    //请同学们补充此操作
    int n = L.length;
    for(int i = n / 2; i > 0; i--) {
        HeapAdjust(L, i, n);
    }
}

//对顺序表L中的记录进行堆排序
void HeapSort(SqList &L) {
    //请同学们补充此操作
    CreatHeap(L);
    for(int i = L.length; i > 1; i--) {
        RedType x = L.r[1];
        L.r[1] = L.r[i];
        L.r[i] = x;
        HeapAdjust(L, 1, i - 1);
    }
}

//将有序表R[low...mid]和R[mid+1...high]归并为有序表R[low...high]
void Merge(RedType R[], RedType T[], int low, int mid, int high) {
    //请同学们补充此操作
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

//对R[low...high]中的记录进行二路归并排序
void MSort(RedType R[], RedType T[], int low, int high) {
    //请同学们补充此操作
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

//对顺序表L中的记录进行归并排序
void MergeSort(SqList &L) {
    MSort(L.r, 1, L.length);
}

//创建顺序表：向顺序表L中添加50个记录，记录的关键字为1-100范围内的随机整数
void CreateList(SqList &L) {
    int i;
    srand(time(0));
    for(i = 1; i <= 50; i++) {
        L.r[i].key = rand() % 100 + 1;
    }
    L.length = 50;
}

//输出顺序表L中各记录关键字的值，中间用空格分隔
void PrintList(SqList L) {
    int i;
    for(i = 1; i <= L.length ; i++) {
        cout << L.r[i].key << "  ";
    }
    cout << endl;
}

//程序菜单
void showmenu() {
    cout << endl;
    cout << "*************Sorting method*********************" << endl;
    cout << "1. 直接插入排序\t2. 折半插入排序" << endl;
    cout << "3. 希尔排序\t4. 冒泡排序" << endl;
    cout << "5. 快速排序\t6. 简单选择排序" << endl;
    cout << "7. 堆排序\t8. 二路归并排序" << endl;
    cout << "0.退出" << endl;
    cout << "请选择要执行的排序方法序号" << endl;

}

int main() {
    SqList L;
    int n, dt[3] = {5, 3, 1}; //dt中存放的是希尔排序时使用的三个增量
    CreateList(L);         //创建长度为10的顺序表L，表中记录的关键字为1-100范围内的随机整数
    showmenu();
    cin >> n;       //输入选择的排序方法序号
    while(n != 0) { //循环显示菜单，按0结束程序
        if(n >= 1 && n <= 8) {
            cout << "待排序记录初始关键字为：" << endl;
            PrintList(L);        //输出排序前表中各记录关键字的值
        }
        switch(n) {   //根据选择的序号调用不同的排序方法
        case 1:
            cout << "直接插入排序的结果为：" << endl;
            InsertSort(L);    //直接插入排序
            PrintList(L);     //输出排序后各记录关键字的值
            break;
        case 2:
            cout << "折半插入排序的结果为：" << endl;
            BInsertSort(L);   //折半插入排序
            PrintList(L);
            break;
        case 3:
            cout << "希尔排序的结果为：" << endl;
            ShellSort(L, dt, 3);  //希尔排序，（3趟）
            PrintList(L);
            break;
        case 4:
            cout << "冒泡排序的结果为：" << endl;
            BubbleSort(L);     //冒泡排序
            PrintList(L);
            break;
        case 5:
            cout << "快速排序的结果为：" << endl;
            QuickSort(L);    //快速排序
            PrintList(L);
            break;
        case 6:
            cout << "简单选择排序的结果为：" << endl;
            SelectSort(L);     //简单选择排序
            PrintList(L);
            break;
        case 7:
            cout << "堆排序的结果为：" << endl;
            HeapSort(L);    //堆排序
            PrintList(L);
            break;
        case 8:
            cout << "快速排序的结果为：" << endl;
            MergeSort(L);    //二路归并排序
            PrintList(L);
            break;
        default:
            cout << "序号选择错误，请重新选择！" << endl;
            break;

        }
        CreateList(L);    //每次排序后，重置L中的50个记录
        showmenu();
        cin >> n;
        system("cls");   //清屏
    }
}


































