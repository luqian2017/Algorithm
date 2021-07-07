class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 0, end = 1e9 + 7;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            long long cnt = 0;
            for (int i = 0; i < nums.size(); ++i) {
                cnt += (nums[i] - 1) / mid;
            }
            if (cnt <= maxOperations) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        return end;
    }
};