class Solution {
public:
    /**
     * @param n: an integer
     * @return: return an integer
     */
    long long reverseBits(long long n) {
        return reverseBits(n, 0);
    }
    
private:
    long long reverseBits(long long n, int pos) {
        if (pos == 31) return n;
        
        long long lastBit = n & 0x1;
        long long result = reverseBits(n >> 1, pos + 1);
        
        if (lastBit) result += (lastBit << (31 - pos));
        return result;
    }
};