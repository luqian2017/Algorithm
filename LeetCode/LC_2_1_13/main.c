#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int i;
    int ret=1;

    if (n<0)
       return 0;

    if (n==0)
       return 1;

    for (i=1; i<=n; i++)
    {
       ret*=i;
    }

    return ret;
}


int cal_seq(int num, int arr[], int len)
{
    //int arr[10]={0};
    int used[10]={0};
    int i,j,k;
    int add_value=0;

    arr[0]=num/factorial(len-1) + 1;
    used[arr[0]]=1;
    num=num%factorial(len-1);

    printf("\nfactorial(%d)=%d\n", len-1, factorial(len-1));
    printf("\narr[0]=%d, used[%d]=1, num=%d\n", arr[0], arr[0], num);

    for (i=1; i<len; i++)
    {
        printf("\n\ni=%d***\n",i);
        for (k=0; k<len; k++)
            printf(" %d ", used[k]);
        printf("\n");


        add_value=0;
        arr[i]=num/factorial(len-1-i) + 1;
        printf("\n===>i=%d, arr[%d]=%d, factorial(%d)=%d\n", i, i, arr[i], len-1-i, factorial(len-1-i));
        //for (j=1; j<=arr[i]; j++)
        for (j=1; j<len; j++)
        {
            //if ((used[j]==1) && (j<=arr[i]))
            //{
            //    add_value++;
            //    printf("   i=%d,j=%d,used[%d]=1, add_value=%d\n", i,j,j, add_value);
            //}
            if (used[j]==0)
            {
                add_value++;
            }
            if (add_value == arr[i])
            {
                break;
            }
        }

        arr[i] = j;
        used[arr[i]]=1;
        num=num%factorial(len-1-i);
        printf("arr[%d]=%d, used[%d]=1, num=%d\n", i, arr[i], arr[i], num);

    }

    return 1;
}

int main()
{
    //int a[6] = {1,1,4,2,2,3};
    //{1,2,3,4,5,6,7,8,9}
    int i;
    int len = 9;
    int arr[10]={0};
    int num = 98884;

    for (i=0; i<9; i++)
        printf("\ni=%d, factorial(%d)=%d\n", i,i,factorial(i));

    //printf("\nfactorial[8]=%d\n", factorial(8));
    cal_seq(num, arr, len);

    for (i=0; i<len; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");

    printf("Hello world!\n");
    return 0;
}
