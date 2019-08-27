#include <time.h>
class Solution {
public:
    Solution(vector<int>& nums) : orig(nums) {
        srand((unsigned)time(NULL));  
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums(orig);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int randN = rand() % n;
            swap(nums[i], nums[randN]);
        }
        return nums;
    }
private:
    vector<int> orig;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */