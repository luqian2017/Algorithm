#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int a[], unsigned int len, int target)
{
    unsigned int start, end, mid;
    start = 0;
    end = len-1;

    while (start <= end)
    {
        mid = (start + end) /2;
        //printf("start, mid, end = %d, %d, %d\n", start, mid, end);

        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }

    }

    return -1;
}

//For rotated binary search,
// if a[mid] == target
//      return mid
// else if (a[mid] < a[start])
//      if a[mid]<target
//          start = mid + 1
//      else
//          end = mid - 1
// else if (a[mid] > a[end])
//      if a[mid] < target
//          start = mid + 1
//      else
//          end = mid - 1

int RotatedBinarySearch(int a[], unsigned int len, int target)
{
    unsigned int start, end, mid;
    start = 0;
    end = len-1;

    while (start <= end)
    {
        mid = (start + end) /2;
        //printf("start, mid, end = %d, %d, %d\n", start, mid, end);
        //printf("a[mid]=%d, target=%d\n", a[mid], target);
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < a[start])
        {
              if (a[start] <= target)
                end = mid - 1;
              else if (a[mid] < target)
                start = mid + 1;
              else
                end = mid - 1;
            //    start = mid + 1;
        }
        else if (a[mid] > a[end])
        {
              if (a[end] >= target)
                 start = mid + 1;
              else if (a[mid] > target)
                 end = mid - 1;
              else
                 start = mid + 1;
              //  end = mid - 1;
        }
        else
        {
            if (a[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
    }

    return -1;
}


int RotatedBinarySearchII(int a[], unsigned int len, int target)
{
    unsigned int start, end, mid;
    start = 0;
    end = len-1;

    while (start <= end)
    {
        mid = (start + end) /2;
        //printf("start, mid, end = %d, %d, %d\n", start, mid, end);
        //printf("a[mid]=%d, target=%d\n", a[mid], target);
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < a[start])
        {
              if (a[start] <= target)
                end = mid - 1;
              else if (a[mid] < target)
                start = mid + 1;
              else
                end = mid - 1;
            //    start = mid + 1;
        }
        else if (a[mid] > a[end])
        {
              if (a[end] >= target)
                 start = mid + 1;
              else if (a[mid] > target)
                 end = mid - 1;
              else
                 start = mid + 1;
              //  end = mid - 1;
        }
        else
        {
            if (a[start]==a[mid])
            {
                start++;
            }
            else if (a[end]==a[mid])
            {
                end--;
            }
            else
            {
                if (a[mid] > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
    }

    return -1;
}


int main()
{
    /* for binary search only
    int a[10] = {0,1,3,7,8,9,12,14,16,50};
    int len = 10;
    int i;
    int location;

    for (i=0; i<len; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");

    location = BinarySearch(a, len, 50);

    printf("50, location=%d\n", location);

    location = BinarySearch(a, len, 0);

    printf("0, location=%d\n", location);

    location = BinarySearch(a, len, 1);

    printf("1, location=%d\n", location);


    location = BinarySearch(a, len, 16);

    printf("16, location=%d\n", location);

    location = BinarySearch(a, len, 17);

    printf("17, location=%d\n", location);
    */

    //for rotated binary search
    /*
    int a[10] = {14,16,50,0,1,3,7,8,9,12};
    int len = 10;
    int i;
    int location;

    for (i=0; i<len; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");

    location = RotatedBinarySearch(a, len, 50);
    printf("50, location=%d\n", location);

    location = RotatedBinarySearch(a, len, 3);
    printf("3, location=%d\n", location);

    location = RotatedBinarySearch(a, len, 12);
    printf("12, location=%d\n", location);

    location = RotatedBinarySearch(a, len, 14);
    printf("14, location=%d\n", location);

    location = RotatedBinarySearch(a, len, 0);
    printf("0, location=%d\n", location);
    */


    //for rotated binary search

    int a[10] = {14,14,14,50,0,1,1,1,1,8};
    int len = 10;
    int i;
    int location;

    for (i=0; i<len; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");

    location = RotatedBinarySearchII(a, len, 50);
    printf("50, location=%d\n", location);

    location = RotatedBinarySearchII(a, len, 0);
    printf("0, location=%d\n", location);

    location = RotatedBinarySearchII(a, len, 12);
    printf("12, location=%d\n", location);

    location = RotatedBinarySearchII(a, len, 14);
    printf("14, location=%d\n", location);

    location = RotatedBinarySearchII(a, len, 1);
    printf("1, location=%d\n", location);

    location = RotatedBinarySearchII(a, len, 8);
    printf("8, location=%d\n", location);

    return 0;
}
