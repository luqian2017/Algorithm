#include <stdio.h>
#include <stdlib.h>

int KthSmallestNumIn2SortedArrays(int a[], int len_a, int b[], int len_b, int k, int *target)
{
    unsigned int pt_a = 0, pt_b = 0;
    unsigned int cur_num = 0;

    if ((k <= 0) || (k >(len_a+len_b)))
    {
        printf("cannot find the number!\n0");
        return 0;
    }

   /*
    if (k == 1)
    {
        *target = (a[0]<b[0])?a[0]:b[0];
        printf("found in a[%d]!\n", *target);
        return 1;
    }

    if (k==2)
    {
        *target = (a[0]>b[0])?a[0]:b[0];
        printf("found in a[%d]!\n", *target);
        return 1;
    }
*/
    //cur_num = 2; //pt_a=1; pt_b=1;
    while ((pt_a < len_a) && (pt_b < len_b) && (cur_num<=k))
    {
        if (a[pt_a]<=b[pt_b])
        {
            if (++cur_num == k)
            {
                *target = a[pt_a];
                printf("found %d in a[%d]!\n", *target, pt_a);
                return 1;
            }
            pt_a++;
        }
        else
        {
            if (++cur_num == k)
            {
                *target = b[pt_b];
                printf("found %d in b[%d]!\n", *target, pt_b);
                return 1;
            }
            pt_b++;
        }
    }

    if (pt_a > len_a)
    {
        pt_b += k - 1 - cur_num;
        *target = b[pt_b];
        printf("cur_num=%d, pt_a=%d, pt_b=%d, found %d in b[%d]!\n", cur_num, pt_a, pt_b, *target, pt_b);
        return 1;
    }
    else
    {
        pt_a += k - 1 - cur_num;
        *target = a[pt_a];
        //printf("found %d in a[%d]!\n", *target, pt_a);
        printf("cur_num=%d, pt_a=%d, pt_b=%d, found %d in a[%d]!\n", cur_num, pt_a, pt_b, *target, pt_a);

        return 1;
    }
}


int main()
{
    int a[10]={1,2,42,61,71,71,100,128,128,130};
   // int b[10]={2,4,4,7,8,9,12,12,18,18};
    int b[1]={1};
    int find_target;
    int i; int k;

    for (i=0; i<10; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");

    for (i=0; i<1; i++)
    {
        printf(" %d ", b[i]);
    }
    printf("\n");

    for (k=1; k<=11; k++)
    {
       //k=1;
       printf("find the %d-th smallest number\n", k);
       //KthSmallestNumIn2SortedArrays(a,10,b,10,k,&find_target);
       KthSmallestNumIn2SortedArrays(a,10,b,1,k,&find_target);
    }
    //k=19;
    //printf("find the %d-th smallest number\n", k);
    //KthSmallestNumIn2SortedArrays(a,10,b,10,k,&find_target);


    printf("Hello world!\n");
    return 0;
}
