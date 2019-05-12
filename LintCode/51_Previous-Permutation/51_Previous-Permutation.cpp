class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        int n = nums.size();
        
        if (n <= 1) return nums;
        
        vector<int> results = nums;
    
        int index = 0;
        
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] < nums[i - 1]) {
                index = i;
                break;
            }
        }

        if (index == 0) {
            reverse(results.begin(), results.end());
            return results;
        }
       
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] < nums[index - 1]) {
                swap(results[i], results[index - 1]);
                sort(results.begin() + index, results.end());
                reverse(results.begin() + index, results.end());        
                break;
            }    
        } 
        
        return results;
    }
};