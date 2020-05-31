class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: the nth digit of the infinite integer sequence
     */
    int findNthDigit(int n) {
        if (n <= 9) return n;
        
        long long baseCount = 9;
        long long sumCount = 9, oldSumCount = 9;
        
        int groupIndex = 1;
        while (sumCount <= n) {
            baseCount *= 10;
            groupIndex++;
            oldSumCount = sumCount;
            sumCount += baseCount * groupIndex;

        }
        long long digitPos = n - oldSumCount;
        long long numPos_int = digitPos / groupIndex;
        int numPos_reminder = digitPos % groupIndex;
        long long targetNumber = pow(10, groupIndex - 1) + numPos_int - 1;
        
        if (numPos_reminder > 0) targetNumber++;
        
        if (numPos_reminder > 0)
            return to_string(targetNumber)[numPos_reminder - 1] - '0';
        else 
            return to_string(targetNumber)[groupIndex - 1] - '0';
        
    }
};