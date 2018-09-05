class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        
        vector<int> results;
        int numSize = nums.size();
        
        if (numSize < k) return results;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
       
        for (int i = 0; i < numSize; ++i) {
            pq.push(nums[i]);
            if (i >= k) pq.pop();
        }
        
        while(!pq.empty()) {
            results.push_back(pq.top());
            pq.pop();
        }
        
        reverse(results.begin(), results.end());
        return results;
    }
};