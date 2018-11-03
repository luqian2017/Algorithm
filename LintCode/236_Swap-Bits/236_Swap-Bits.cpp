class Solution {
public:
    /*
     * @param x: An integer
     * @return: An integer
     */
    int swapOddEvenBits(int x) {
        int len = sizeof(int) * 8;
        for (int i = 0; i < len; i += 2) {
            int even = (x >> i) & 0x1;
            int odd = (x >> i + 1) & 0x1;
            if (odd != even) {
                if (even == 1) {
                    x &= ~(0x1 << i);  //clear i th bit
                    x |= (0x1 << (i + 1)); //set the i+1 th bit
                } else {
                    x &= ~(0x1 << (i + 1));  //clear i+1 th bit
                    x |= (0x1 << i); //set the i th bit
                }
            } 
        }
        
        return x;
    }
};c