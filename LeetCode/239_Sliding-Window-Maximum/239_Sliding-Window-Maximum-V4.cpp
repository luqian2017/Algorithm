class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec(n, 0);
        int head = 0, tail = 0;
        vector<int> res;

        for (int i = 0; i < n; ++i) {
            while(head < tail && nums[vec[tail - 1]] < nums[i]) {
            //while(tail > 0 && nums[vec[tail - 1]] < nums[i]) {
                tail--;
            }
            vec[tail] = i;
            tail++;
          
            if (tail > 0 && vec[tail - 1] - vec[head] + 1 > k) head++;
            //if (head < tail && vec[tail - 1] - vec[head] + 1 > k) head++;     也可以
            //if (head < tail && i - vec[head] + 1 > k) head++;   也可以 
            if (i >= k - 1) {
                res.push_back(nums[vec[head]]);
            }
        }
        
        return res;
    }
};