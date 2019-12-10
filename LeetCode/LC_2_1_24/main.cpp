#include <iostream>

using namespace std;

int singleOne(int a[], int n)
{
    int bit_loc[sizeof(int)]={0};
    int result = 0;
    int i,j;

    for (i=0; i<n; i++)
    {
        for (j=0; j<sizeof(int); j++)
        {
            bit_loc[j] += (a[i]>>j) & 0x1;
        }
    }

    for (j =0; j<sizeof(int); j++)
    {
        if ((bit_loc[j] % 3) != 0)
        {
            result |= 1<<j;
        }
    }

    return result;
}


int main()
{
    int a[22] = {2, 6, 8, 7, 4, 123, 42, 2, 2, 7, 15, 6, 4, 123, 42, 6, 8, 7, 8, 4, 123, 42};
    cout << singleOne(a,22) <<endl;
    return 0;
}
