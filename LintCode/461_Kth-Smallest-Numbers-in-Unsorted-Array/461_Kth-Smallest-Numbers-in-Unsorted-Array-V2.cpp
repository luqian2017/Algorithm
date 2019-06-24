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
            
            if (i < k) {
                pq.push(nums[i]);
            } else {
                if (nums[i] < pq.top()) {
                    pq.push(nums[i]);
                    pq.pop();
                }
            }
            
        }
        
        return pq.top();
    }
};