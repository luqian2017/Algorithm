#include <stdio.h>
#include <stdlib.h>

int removeDup2(int a[], unsigned int len)
{
    unsigned int index1 = 0, index2 = 0;
    if ((len == 0) || (len == 1) || (len == 2))
        return len;

    //index2 = 1;
    while (index2 < len-1)
    {
        if (a[++index2] != a[index1])
        {
            if (index2 > index1 + 1)
            {
                index1 = index1+2;
                a[index1] = a[index2];
            }
            else
            {
                index1=index2;
            }
        }
    }

    return index1+1;

}

int main()
{
    //int a[10] = {1,1,2,2,2,3,4,4,4,5};
    int a[6] = {1,1,1,2,2,3};
    int len = 6;
    int i;

    for (i=0; i<len; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");

    printf("remove duplicate ... \n");
    len = removeDup2(a, len);
    printf("new len = %d\n", len);
    for (i=0; i<len; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");

    return 0;
}
