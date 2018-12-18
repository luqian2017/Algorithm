class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        int result = 0;
        map<int, int> mp;
        
        int len = nums.size();
        if (len == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        int p1 = 0, p2 = len - 1;
        
        while (p1 < p2) {
            int sum = nums[p1] + nums[p2];
            
            if (sum == target) {
                mp[nums[p1]] = nums[p2];
                p1++;
                p2--;
            }else if (sum < target) {
                p1++;   
            } else {
                p2--;
            }
        }
        
        return mp.size();
    }
};