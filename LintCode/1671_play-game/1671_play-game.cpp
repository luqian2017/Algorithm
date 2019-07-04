class Solution {
public:
    /**
     * @param A: 
     * @return: nothing
     */
    long long playGames(vector<int> &A) {
        int n = A.size();
        if (n == 0) return 0;
        int maxV = A[0];
        for (auto a : A) maxV = max(maxV, a);
        
        long long start = 0, end = maxV * 2;
        while(start + 1 < end) {
            long long mid = start + (end - start) / 2;
            long long count = 0;
            for (auto a : A) count += max(mid - (long long)a, 0ll);
            if (mid > count) start = mid;
            else end = mid;
        }
        
        
        return max(start + 1, (long long)maxV);
    }
};