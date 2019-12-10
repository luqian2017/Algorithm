#include <iostream>

using namespace std;


int removeDup(int a[], unsigned int len)
{
    unsigned int index1=0, index2=1;

    if ((len == 0) || (len == 1))
        return len;

    while (index2 != len-1)
    {
        if (a[index2] != a[index1])
        {
            a[++index1] = a[index2];
        }

        index2++;
    }

    return index1+1;
}

int main()
{
    int a[10] = {1,1,2,2,2,3,4,4,5,5};
    int i, len;

    for (i=0; i<10; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");

    printf("remove duplicate ... \n");
    len = removeDup(a, 10);
    printf("new len = %d\n", len);
    for (i=0; i<len; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");

    return 0;
}
