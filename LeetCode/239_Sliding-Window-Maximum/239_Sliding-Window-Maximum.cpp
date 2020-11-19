class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int len = nums.size();
        vector<int> res;
        if (len < k) return res;
        deque<int> dq; //mono decreasing queue (from head to tail)
        for (int i = 0; i < len; ++i) {
            while (!dq.empty() && (nums[i] > nums[dq.back()])) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            if (i - dq.front() == k) {
                dq.pop_front();
            }
            
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};
