class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int k, vector<int> &nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                minHeap.push(nums[i]);
            }
            else {
                if (nums[i] < minHeap.top()) continue;
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};