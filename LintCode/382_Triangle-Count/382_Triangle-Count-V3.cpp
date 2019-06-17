class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        int n = S.size();
        if (n < 3) return 0;
        
        int count  = 0;
        
        sort(S.begin(), S.end());
        
        for (int pos = 2; pos < n; ++pos) {
            int start = 0, end = pos - 1;
            while (start < end) {
                if ((S[start] + S[end]) > S[pos]) {
                    count += end - start;
                    end--;
                } else {
                    start++;
                }
            }
        }

        return count;
    }

};