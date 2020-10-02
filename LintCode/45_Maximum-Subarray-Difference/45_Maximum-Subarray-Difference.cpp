class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    int maxDiffSubArrays(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<int> l2rMax(n, 0), l2rMin(n, 0), r2lMax(n, 0), r2lMin(n, 0);
        int max_sum, min_sum, g_max_sum, g_min_sum;
        
        l2rMax[0] = max_sum = g_max_sum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (max_sum > 0) {
                max_sum += nums[i];
            } else {
                max_sum = nums[i]; 
            }
            g_max_sum = max(g_max_sum, max_sum);
            l2rMax[i] = g_max_sum;
        }
        
        l2rMin[0] = min_sum = g_min_sum = nums[0]; 
        for (int i = 1; i < n; ++i) {
            if (min_sum < 0) {
                min_sum += nums[i];
            } else {
                min_sum = nums[i];
            }
            g_min_sum = min(g_min_sum, min_sum);
            l2rMin[i] = g_min_sum;
        }
        
        r2lMax[n - 1] = max_sum = g_max_sum = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (max_sum > 0) {
                max_sum += nums[i];
            } else {
                max_sum = nums[i];
            }
            g_max_sum = max(g_max_sum, max_sum);
            r2lMax[i] = g_max_sum;
        }
        
        r2lMin[n - 1] = min_sum = g_min_sum = nums[n  - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (min_sum < 0) {
                min_sum += nums[i];
            } else {
                min_sum = nums[i];
            }
            g_min_sum = min(g_min_sum, min_sum);
            r2lMin[i] = g_min_sum;
        }
        
        // now go through the array to try all the index positions
        int g_max_subarray_diff = INT_MIN;
        for (int i = 0; i < n - 1; ++i) {
            g_max_subarray_diff = max(g_max_subarray_diff, abs(l2rMax[i] - r2lMin[i + 1]));
            g_max_subarray_diff = max(g_max_subarray_diff, abs(l2rMin[i] - r2lMax[i + 1]));
        }
        
        return g_max_subarray_diff;
    }
};