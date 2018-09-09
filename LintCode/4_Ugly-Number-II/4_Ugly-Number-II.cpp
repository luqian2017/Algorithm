class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        //the ugly number is 2^i * 3^j * 5^k
        int id2 = 0;    
        int id3 = 0;    
        int id5 = 0;    
        int index = 1;
        
        vector<int> uglys;
        uglys.push_back(1);
        
        while (index < n) {
            int candidate = min(min(uglys[id2] * 2, uglys[id3] * 3), uglys[id5] * 5);
            
            if (candidate == uglys[id2] * 2) {
                id2++;
            }
            
            if (candidate == uglys[id3] * 3) {
                id3++;
            }
            
            if (candidate == uglys[id5] * 5) {
                id5++;
            }
            
            uglys.push_back(candidate);
            index++;
        }
        
        return uglys[n - 1];
    }
};