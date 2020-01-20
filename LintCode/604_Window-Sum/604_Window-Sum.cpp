class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 0) return {};
        int p1 = 0, p2 = 0;
        int sum = 0;
        vector<int> result;
        for (p2 = 0; p2 < n; ++p2) {
            sum += nums[p2];
            if (p2 == k - 1) {
                result.push_back(sum); 
            } else if (p2 > k - 1) {
                sum -= nums[p1++];
                result.push_back(sum);
            }
        }
        
        return result;
    }
};