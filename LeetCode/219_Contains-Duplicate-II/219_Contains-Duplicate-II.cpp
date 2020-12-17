class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  //<num, index>
        int n = nums.size();
        bool res;
        for (int i = 0; i < n; ++i) {
            if (mp.find(nums[i]) != mp.end()) {
                if (abs(mp[nums[i]] - i) <= k) return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};