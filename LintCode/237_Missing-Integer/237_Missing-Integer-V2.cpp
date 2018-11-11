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
        // Write your code here
        return findMissing(array, 0);
    }

    int findMissing(vector<BitInteger> input, int column) {
        if (column >= BitInteger::INTEGER_SIZE) { // We're done!
            return 0;
        }
        vector<BitInteger> oneBits;
        vector<BitInteger> zeroBits;
        for (BitInteger t : input) {
            if (t.fetch(column) == 0) {
                zeroBits.push_back(t);
            } else {
                oneBits.push_back(t);
            }
        }
        
        if (zeroBits.size() <= oneBits.size()) {
            int v = findMissing(zeroBits, column + 1);
            return (v << 1) | 0;
        } else {
            int v = findMissing(oneBits, column + 1);
            return (v << 1) | 1;
        }
    }
};