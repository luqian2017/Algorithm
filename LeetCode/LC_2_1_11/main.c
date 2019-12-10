#include <stdio.h>
#include <stdlib.h>

int remove_element(int a[], int len, int target)
{
    int i=0, j=0;

    for (i=0; i<len; i++)
    {
       if (a[i]!=target)
       {
          a[j++]=a[i];
       }
    }

    return j;

}

int main()
{
    int a[6] = {1,1,4,2,2,3};
    int len = 6;
    int i;
    int k, target;

    for (i=0; i<len; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");

    target=4;
    k=remove_element(a,len,target);

    for (i=0; i<k; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
    printf("Hello world!\n");
    return 0;
}
