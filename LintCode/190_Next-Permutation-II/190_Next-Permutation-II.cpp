class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: nothing
     */
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return;
        int i = 0, j = 0;
        for (i = n - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) break;
        }
        
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for (j = n - 1; j > i; --j) {
            if (nums[j] > nums[i - 1]) break;
        }
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());        
    //    int p1 = i, p2 = n - 1;
    //    while(p1 < p2) {
    //        swap(nums[p1], nums[p2]);
    //        p1++; p2--;
    //    }
    }
};