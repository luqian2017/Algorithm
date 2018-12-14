class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        
        int len = nums.size();
        vector<int> result;
        if ((len <= 0) || (len < k)) return result;
        
        deque<int> dq; // non-increasing list, as it needs maximum (otherwise, non-decreasing list for minimum)

        for (int i = 0; i < len; ++i) {

            while (!dq.empty() && (nums[i] > nums[dq.back()]))  {  //for non-increasing, use > here; for non-decreasing, use < here
                dq.pop_back();
            }

            dq.push_back(i);

            if (i - dq.front() == k) {
                dq.pop_front();
            }
            
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};