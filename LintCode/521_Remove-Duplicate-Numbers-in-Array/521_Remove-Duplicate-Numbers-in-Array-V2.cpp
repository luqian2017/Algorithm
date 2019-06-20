class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return n;
        
        unordered_map<int, int> um;
        vector<int> nums2;
        
        for (int i = 0; i < n; ++i) {
            if (um.find(nums[i]) != um.end()) {
                um[nums[i]]++;
            } else {
                um[nums[i]] = 1;
                nums2.push_back(nums[i]);
            }
        }


        for (int i = 0; i < um.size(); ++i) {
            nums[i] = nums2[i];
        }
        
        return um.size();
    }
};