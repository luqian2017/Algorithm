class Solution {
public:
    /**
     * @param nums: an array
     * @return: the minimum number of moves required to make all array elements equal
     */
    int minMoves(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int cnt = 0;
        int min = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            if (min > nums[i]) min = nums[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cnt += nums[i] - min;
        }
        return cnt;
    }
};