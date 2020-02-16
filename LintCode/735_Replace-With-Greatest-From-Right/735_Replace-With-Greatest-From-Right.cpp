class Solution {
public:
    /**
     * @param nums: An array of integers.
     * @return: nothing
     */
    void arrayReplaceWithGreatestFromRight(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return;
        
        vector<int> revMaxes(n, INT_MIN);
        for (int i = n - 2; i >= 0; --i) {
            revMaxes[i] = max(revMaxes[i + 1], nums[i + 1]);
        }

        for (int i = 0; i < n - 1; ++i) {
            nums[i] = revMaxes[i];
        }
        
        nums[n - 1] = -1;
    }
};