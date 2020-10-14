class Solution {
public:
    /**
     * @param n: 
     * @param k: 
     * @param len: 
     * @param num: //same as problem
     * @return: //return long
     */
    long long solve(int n, int k, int len, vector<int> &num) {
        int num_len = num.size();
        double sum = 0.0, ave = 0.0;
        long long cnt = 0;
                
        for (int i = 0; i < num_len; ++i) {
            if (i < len - 1) {
                sum += num[i];
            } else {
                sum += num[i] - num[i - len];
                ave = sum / len;
                if (ave > k) cnt++;
            }
        }
        
        return cnt;
    }
};