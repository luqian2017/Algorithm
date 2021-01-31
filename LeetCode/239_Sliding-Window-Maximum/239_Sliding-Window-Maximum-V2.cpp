class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return {};
        vector<int> q(n, 0), res;
        int tail = 0, head = 0;
        
        for (int i = 0; i < n; ++i) {
            while (tail > head && nums[q[tail - 1]] < nums[i]) tail--;

            q[tail++] = i;
            
            if (i - q[head] + 1 > k) { //i is q[oldtail]
                //q[head]++;
                head++;
            }
            
            if (i >= k - 1) res.push_back(nums[q[head]]);
        }
        
        return res;
    }
};