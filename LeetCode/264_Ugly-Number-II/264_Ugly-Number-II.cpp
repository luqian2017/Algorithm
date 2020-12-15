class Solution {
public:
    int nthUglyNumber(int n) {
        int index2 = 0, index3 = 0, index5 = 0;
        vector<int> uglys;
        uglys.push_back(1);
        int res = 1;
        while(res < n) {
            int try2 = uglys[index2] * 2;
            int try3 = uglys[index3] * 3;
            int try5 = uglys[index5] * 5;
            int candidate = min(try2, min(try3, try5));
            if (candidate == try2) index2++;
            if (candidate == try3) index3++;
            if (candidate == try5) index5++;
            uglys.push_back(candidate);
            res++;
        }
        return uglys[n - 1];
    } 
};