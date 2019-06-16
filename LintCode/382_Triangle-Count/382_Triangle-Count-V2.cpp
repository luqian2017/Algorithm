class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        int n = S.size();
        if (n < 3) return 0;
        
        int start = 0, end = 2;
        int count  = 0;
        
        sort(S.begin(), S.end());
        
        while(end < n) {
            start = 0;
            while(start < end - 1) {
                int pos = binarySearch(S, start + 1, end - 1, S[end] - S[start]);
                if (pos > 0) count += end - pos;
                start++;
            }
            end++;
        }

        return count;
    }

private:
    //find the 1st pos such that S[start] + S[pos] > S[end], that is, S[start] + S[pos - 1] <= S[end]
    int binarySearch(vector<int> &S, int start, int end, int target) {

      while(start + 1 < end) {
            int mid = start + (end - start) / 2;

            if (S[mid] > target) {
                end = mid;
            } else {
                start = mid;   
            }
        }
        
        if (S[start] > target) return start;
        if (S[end] > target) return end;
        return -1;
    }
};