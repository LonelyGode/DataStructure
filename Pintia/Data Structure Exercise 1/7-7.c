#include<stdio.h>
struct Poly
{
    int ex;
    int co;
} Poly[1001];
int main()
{
    int a, b, A[2005] = {0}, B[1005] = {0};

    scanf("%d", &a);
    int temp1, temp2;

    for (int i = 0; i < a; i++)
    {
        scanf("%d%d", &Poly[i].co, &Poly[i].ex); //?????,?????
        B[Poly[i].ex] += Poly[i].co;    //??????,????????
    }
    scanf("%d", &b);

    for (int i = 0; i < b; i++)
    {
        scanf("%d%d", &temp1, &temp2);
        B[temp2] += temp1;
        for (int j = 0; j < a; j++)
            A[temp2 + Poly[j].ex] += (temp1 * Poly[j].co); //????,????
    }
    int isfirst = 1, haveoutput = 0; //isfirst??????????,haveoutput???????????
    for (int i = 2000; i >= 0; i--)
    {
        if (A[i] != 0)
        {
            if (!isfirst)    printf(" %d %d", A[i], i);
            if (isfirst)
            {
                isfirst = 0;
                printf("%d %d", A[i], i);
            }
            haveoutput = 1; //?????if?????????
        }
    }

    if (!haveoutput) printf("0 0");
    haveoutput = 0; //????????????????
    isfirst = 1;    //?????????????
    putchar('\n');
    for (int i = 1000; i >= 0; i--)
    {
        if (B[i] != 0)
        {
            if (!isfirst)        printf(" %d %d", B[i], i);
            if (isfirst)
            {
                printf("%d %d", B[i], i);
                isfirst = 0;
            }
            haveoutput = 1;
        }

    }
    if (!haveoutput) printf("0 0");
    return 0;
}

