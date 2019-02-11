class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double preSum = accumulate(nums.begin(), nums.begin() + k, 0);
        double sum = preSum, res = preSum / k;
        for (int i = k; i < nums.size(); ++i) {
            preSum += nums[i];
            sum = preSum;
            if (sum > res * (i + 1)) res = sum / (i + 1);
            for (int j = 0; j <= i - k; ++j) {
                sum -= nums[j];
                if (sum > res * (i - j)) res = sum / (i - j);
            }
        }
        return res;
    }
};