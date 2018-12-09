class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {

        long long count = 0; //count of 5   
        while (n) {
            n /= 5;
            count += n;
        }
        
        return count;
    }
};