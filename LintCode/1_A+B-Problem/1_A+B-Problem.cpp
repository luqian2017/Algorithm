class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b 
     */
    int aplusb(int a, int b) {
        while (b) {
            int a1 = a ^ b;
            int b1 = (a & b) << 1;
            a = a1;
            b = b1;
        }
        
        return a;    
    }
};