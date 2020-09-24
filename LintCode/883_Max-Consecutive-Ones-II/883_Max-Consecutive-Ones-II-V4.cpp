class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &A) {
        int n = A.size();
        int ans = 0, pos = 0, prev_count = 0, curr_count = 0;
        for (int i = 0; i < n; i++) {
            if( A[i] == 1) {
                curr_count++;
            }else{
                ans = max(ans, curr_count + prev_count + 1);
                prev_count = curr_count;
                curr_count = 0;
            }
        }
        
        return ans; 
    }
};