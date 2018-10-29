class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        int count = 0;
        while (num) {
            count++;
            num &= num - 1;
        }
        
        return count;
    }
};