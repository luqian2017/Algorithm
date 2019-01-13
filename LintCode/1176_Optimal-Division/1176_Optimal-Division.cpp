class Solution {
public:
    /**
     * @param nums: an array
     * @return: the corresponding expression in string format
     */
    string optimalDivision(vector<int> &nums) {
        string result;
        int len = nums.size();
        
   //     if (len == 0) return "";
   //     if (len == 1) return to_string(nums[0]);
        
        result = result + to_string(nums[0]) + '/';
        if (len > 2)
            result = result + '(';
            
        for (int i = 1; i < len; ++i) {
            result = result + to_string(nums[i]) + '/';
        }
            
        result.pop_back(); //remove the last '/'
        
        if (len > 2) result = result + ')';

        return result; 
    }
};