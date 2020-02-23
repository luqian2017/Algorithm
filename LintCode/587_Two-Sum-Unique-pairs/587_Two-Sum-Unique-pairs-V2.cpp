class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        int n = nums.size();

        set<pair<int, int>> hashmap;
        sort(nums.begin(), nums.end());
        int p1 = 0, p2 = n - 1;
        while(p1 < p2) {
            int sum = nums[p1] + nums[p2];
            if (sum < target) {
                p1++;
            } else if (sum > target) {
                p2--;
            } else {
                hashmap.insert({nums[p1], nums[p2]});
                p1++;
                p2--;
            }
        }
        
        return hashmap.size();
    }
};