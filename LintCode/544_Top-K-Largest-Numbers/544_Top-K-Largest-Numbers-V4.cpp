class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < n; ++i) {
            if (i < k) {
                minHeap.push(nums[i]);
            }
            else {
                if (nums[i] > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            }
        }
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};