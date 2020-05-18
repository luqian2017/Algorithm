class Solution {
public:
    /**
     * @param nums: 4 cards
     * @return: whether they could get the value of 24
     */
    bool compute24(vector<double> &nums) {
        return dfs(nums, 4);
    }
    
private:
    bool dfs(vector<double> &nums, int n) {
        if (n == 1) {
            if (fabs(nums[0] - 24) < 1e-6) return true;
            else return false;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double a = nums[i];
                double b = nums[j];
                nums[j] = nums[n - 1];
                
                // a + b
                nums[i] = a + b;
                if (dfs(nums, n - 1)) {
                    return true;
                }
                
                // a - b
                nums[i] = a - b;
                if (dfs(nums, n - 1)) {
                    return true;
                }
                
                // b - a
                nums[i] = b - a;
                if (dfs(nums, n - 1)) {
                    return true;
                }
                
                // a * b
                nums[i] = a * b;
                if (dfs(nums, n - 1)) {
                    return true;
                }
                
                // a / b
                if (fabs(b) > 1e-6) {
                    nums[i] = a / b;
                    if (dfs(nums, n - 1)) {
                        return true;
                    }
                }
                
                // b / a
                if (fabs(a) > 1e-6) {
                    nums[i] = b / a;
                    if (dfs(nums, n - 1)) {
                        return true;
                    }
                }
                nums[i] = a;
                nums[j] = b;
            }
        }
        
        return false;
    }
};