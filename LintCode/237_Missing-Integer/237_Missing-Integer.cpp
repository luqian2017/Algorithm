/**
 * Definition of BitInteger:
 * class BitInteger {
 * public:
 *     static int INTEGER_SIZE;
 *     int fetch(int j) {
 *         .... // return 0 or 1, fetch the jth bit of this number
 *     }
 * }
 * int BitInteger::INTEGER_SIZE = 31;
 */
class Solution {
public:
    /**
     * @param str a BitInteger list
     * @return an integer
     */
    int findMissing(vector<BitInteger>& array) {
        vector<int> XORResult(BitInteger::INTEGER_SIZE, 0);
        int arraySize = array.size();
        int result = 0;
        for (int i = 0; i < BitInteger::INTEGER_SIZE; ++i) {
            for (auto bitInt : array) {
                result ^= (bitInt.fetch(i)) << i;
            }
            for (int j = 0; j < arraySize + 1; ++j) {
                result ^= j & (1 << i);
            }
        }
        
        return result;
    }
};