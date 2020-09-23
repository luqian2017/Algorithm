class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int len = nums.size();
        int prev_count = 0, curr_count = 0, max_count = 0;
        bool connect_ok = false;
        
        for (int i = 0; i < len; ++i) {
            if (nums[i] == 1) {
                curr_count++;
            } else {
                if (connect_ok) {
                    max_count = max(max_count, prev_count + curr_count + 1);
                    connect_ok = false;
                }
                prev_count = curr_count;
                curr_count = false;

                if (i < len - 1 && i > 0 && nums[i - 1] == 1 && nums[i + 1] == 1) {
                    connect_ok = true;
                }
            }
        }
        
        // for the case that reaches the end
        if (connect_ok) {
            max_count = max(max_count, prev_count + curr_count + 1);
        }
        
        return max_count;
    }
};