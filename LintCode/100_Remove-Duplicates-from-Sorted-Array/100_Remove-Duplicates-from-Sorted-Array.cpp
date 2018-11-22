class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        set<int> s;
        int len = nums.size();
        int i = 0, j = 0;
        while (j < len) {
            while (s.find(nums[j]) != s.end()) {
                j++;
            }
            s.insert(nums[j]);
            
            if (j < len) {
                nums[i] = nums[j];
                i++; j++;
            }
            
        }
        
        return i;
    }
};