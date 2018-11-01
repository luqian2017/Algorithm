Description:
Given 2*n + 2 numbers, every numbers occurs twice except two, find them.

Have you met this question in a real interview?  
Example
Given [1,2,2,3,4,4,5,3] return 1 and 5

Challenge
O(n) time, O(1) extra space.

Solution:
First XOR all the numbers, the result is a ^ b, which should not be 0 (otherwise a == b). We can choose any 1 bit of the result, which can separate all the numbers into two categories: the one which has the bit as 1, and the one which has the bit as 0.

The simplest way is to use x & (-x) to return the right most 1 (which is the LowBit() used in Binary Index Tree).

```
class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer array
     */
    vector<int> singleNumberIII(vector<int> &A) {
        int xor_v = 0;

        for (auto i : A) {
            xor_v ^= i;
        }
        
        int lastOne = xor_v & (-xor_v);
        
        vector<int> result = {0, 0}; //result[0] and result[1] are two categories
        
        for (auto i : A) {
            if (i & lastOne)
                result[0] ^= i;
            else
                result[1] ^= i;
        }
        
        return result;
    }
};
```
