class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        int  n = nums.size();
        if (n < k) return -1;
        
        priority_queue<int> pq; //max-heap
        
        for (int i = 0; i < n; ++i) {
            pq.push(nums[i]);
            if (i >= k) pq.pop();
        }
        
        return pq.top();
    }
};